#pragma once

#include <iostream>

class MultiSet {
	friend std::ostream& operator<<(std::ostream&, const MultiSet&);
	friend std::istream& operator>>(std::istream&, MultiSet&);

public:
	MultiSet();
	MultiSet(int, const int*);
	MultiSet(const MultiSet&);
	MultiSet& operator=(const MultiSet&);
	~MultiSet() {}

	bool contains(int) const;
	bool is_sub_set(const MultiSet&) const;

	MultiSet& operator&=(const MultiSet&);
	MultiSet& operator|=(const MultiSet&);
	MultiSet& operator-=(const MultiSet&);

	bool operator==(const MultiSet&) const;

private:
	void initialize(const int*);

	void check_size(int) const;

private:
	static const int s_set_limit = 10001;

	int m_size;
	int m_data[s_set_limit]{};
};

MultiSet operator&(MultiSet, const MultiSet&);
MultiSet operator|(MultiSet, const MultiSet&);
MultiSet operator-(MultiSet, const MultiSet&);

bool operator!=(const MultiSet&, const MultiSet&);