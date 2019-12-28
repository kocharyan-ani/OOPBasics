#pragma once

#include <iostream>

class Set {
	friend std::ostream& operator<<(std::ostream&, const Set&);
	friend std::istream& operator>>(std::istream&, Set&);

public:
	Set();
	Set(int, const int*);
	Set(const Set&);
	Set& operator=(const Set&);
	~Set() {}

	bool contains(int) const;
	bool is_sub_set(const Set&) const;

	Set& operator&=(const Set&);
	Set& operator|=(const Set&);
	Set& operator-=(const Set&);

	bool operator==(const Set&) const;

private:
	void initialize(const bool*);

	void check_size(int) const;

private:
	static const int s_set_limit = 10001;

	int m_size;
	bool m_data[s_set_limit];
};

Set operator&(Set, const Set&);
Set operator|(Set, const Set&);
Set operator-(Set, const Set&);

bool operator!=(const Set&, const Set&);