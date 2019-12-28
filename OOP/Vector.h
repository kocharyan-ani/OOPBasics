#pragma once

#include <iostream>

class Vector {
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);

public:
	explicit Vector(int);	// n >= 2
	Vector(int, const int*);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	~Vector();

	int dimension() const { return m_dimension; }
	int distance(const Vector&) const;

	int& operator[](int);
	const int& operator[](int) const;

	Vector& operator+=(const Vector&);
	Vector& operator-=(const Vector&);
	int operator*(const Vector&);

	bool operator==(const Vector&) const;

private:
	void allocate_and_initialize(const int* = nullptr);
	void deallocate();

	void check_dimension(int) const;
	void check_size(const Vector&) const;

private:
	int m_dimension;
	int* m_data;
};

Vector operator+(Vector, const Vector&);
Vector operator-(Vector, const Vector&);

bool operator!=(const Vector&, const Vector&);