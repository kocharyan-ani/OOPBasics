#pragma once

#include <iostream>

class MultiSet {
	friend std::ostream& operator<<(std::ostream&, const MultiSet&);

public:
	MultiSet();
	MultiSet(int, const int*);
	MultiSet(const MultiSet&);
	MultiSet& operator=(const MultiSet&);
	~MultiSet();

	bool contains(int) const;
	bool is_sub_set(const MultiSet&) const;

	MultiSet& operator&=(const MultiSet&);
	MultiSet& operator|=(const MultiSet&);
	MultiSet& operator-=(const MultiSet&);

	bool operator==(const MultiSet&) const;

private:
	void allocate_and_initialize(const int*);
	void deallocate();

	void check_size(int) const;

private:
	static const int s_set_limit = 10001;

	int m_size;
	int* m_data;
};

MultiSet operator&(MultiSet, const MultiSet&);
MultiSet operator|(MultiSet, const MultiSet&);
MultiSet operator-(MultiSet, const MultiSet&);

bool operator!=(const MultiSet&, const MultiSet&);