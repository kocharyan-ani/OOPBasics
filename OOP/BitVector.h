#pragma once

#include <iostream>

class BitVector {
	friend std::ostream& operator<<(std::ostream&, const BitVector&);
	friend std::istream& operator<<(std::istream&, BitVector&);

public:
	explicit BitVector(int);
	BitVector(int, const bool*);
	BitVector(const BitVector&);
	BitVector& operator=(const BitVector&);
	~BitVector();

	int size() const { return m_size; }

	BitVector& operator&=(const BitVector&);
	BitVector& operator|=(const BitVector&);
	BitVector& operator^=(const BitVector&);
	BitVector& operator<<=(int);
	BitVector& operator>>=(int);

	BitVector& operator~();

	bool& operator[](int);
	const bool& operator[](int) const;

private:
	void allocate_and_initialize(const bool* = nullptr);
	void deallocate();

	void check_index(int) const;

	void check_size_correct(const BitVector&) const;

private:
	int m_size;
	bool* m_data;
};

BitVector operator&(BitVector, const BitVector&);
BitVector operator|(BitVector, const BitVector&);
BitVector operator^(BitVector, const BitVector&);
BitVector operator<<(BitVector, int);
BitVector operator>>(BitVector, int);