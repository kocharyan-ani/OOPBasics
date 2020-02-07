#pragma once

#include <iostream>

class MyVector {
	friend std::ostream& operator<<(std::ostream&, const MyVector&);
	friend std::istream& operator>>(std::istream&, MyVector&);

public:
	explicit MyVector(int);	// n >= 2
	MyVector(int, const int*);
	MyVector(const MyVector&);
	MyVector& operator=(const MyVector&);
	~MyVector();

	int dimension() const { return m_dimension; }
	double distance(const MyVector&) const;

	int& operator[](int);
	const int& operator[](int) const;

	MyVector& operator+=(const MyVector&);
	MyVector& operator-=(const MyVector&);
	int operator*(const MyVector&);

	bool operator==(const MyVector&) const;

private:
	void allocate_and_initialize(const int* = nullptr);
	void deallocate();

	void check_dimension(int) const;
	void check_size(const MyVector&) const;

private:
	int m_dimension;
	int* m_data;
};

MyVector operator+(MyVector, const MyVector&);
MyVector operator-(MyVector, const MyVector&);

bool operator!=(const MyVector&, const MyVector&);