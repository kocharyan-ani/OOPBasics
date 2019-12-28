#pragma once

#include <iostream>

class HugeInteger {
	friend std::ostream& operator<<(std::ostream&, const HugeInteger&);
	friend std::istream& operator>>(std::istream&, HugeInteger&);

public:
	explicit HugeInteger(int = 0);
	HugeInteger(int, const char*);
	HugeInteger(const HugeInteger&);
	HugeInteger& operator=(const HugeInteger&);
	~HugeInteger();

	HugeInteger& operator+=(const HugeInteger&);
	HugeInteger& operator++();
	HugeInteger operator++(int);

	bool operator==(const HugeInteger&) const;
	bool operator<(const HugeInteger&) const;

	explicit operator int();

public:
	static int get_created_object_count() { return s_created_object_count; }

private:
	static int s_created_object_count;

private:
	int m_max_length;
	int m_length;
	char* m_data;
};

HugeInteger operator+(HugeInteger, const HugeInteger&);

bool operator!=(const HugeInteger&, const HugeInteger&);
bool operator<=(const HugeInteger&, const HugeInteger&);
bool operator>(const HugeInteger&, const HugeInteger&);
bool operator>=(const HugeInteger&, const HugeInteger&);
