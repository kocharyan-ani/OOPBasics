#pragma once

#include <iostream>

class String {
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator<<(std::istream&, String&);

public:
	String();
	explicit String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	int size() const { return m_size; }
	int index_of(const String&) const;

	char& operator[](int);
	const char& operator[](int) const;

	String& operator+=(const String&);

	bool operator==(const String&) const;

public:
	static int get_existing_object_count() { return s_existing_object_count; }

private:
	static int s_existing_object_count;

private:
	int m_max_size;
	int m_size;
	char* m_data;
};

String operator+(String, const String&);

bool operator!=(const String&, const String&);