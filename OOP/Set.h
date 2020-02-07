#pragma once

#include <iostream>

class Set {
	friend std::ostream& operator<<(std::ostream&, const Set&);

public:
	Set();
	Set(int, const int*);
	Set(const Set&);
	Set& operator=(const Set&);
	~Set();

	bool contains(int) const;
	bool is_sub_set(const Set&) const;

	Set& operator&=(const Set&);
	Set& operator|=(const Set&);
	Set& operator-=(const Set&);

	bool operator==(const Set&) const;

private:
	void allocate_and_initialize(const bool*);
	void deallocate();

	void check_size(int) const;

private:
	static const int s_set_limit = 10001;

	int m_size;
	bool* m_data;
};

Set operator&(Set, const Set&);
Set operator|(Set, const Set&);
Set operator-(Set, const Set&);

bool operator!=(const Set&, const Set&);