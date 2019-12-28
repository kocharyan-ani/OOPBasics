#include "Vector.h"

std::ostream& operator<<(std::ostream& out, const Vector& object) {
	out << '(';
	for (int i = 0; i < object.m_dimension - 1; ++i) {
		out << object.m_data[i] << ', ';
	}
	out << object.m_data[object.m_dimension - 1] << ')';
	return out;
}

std::istream& operator>>(std::istream& in, Vector& object) {
	// TODO
	return in;
}

Vector::Vector(int dimension)
	: m_dimension(dimension)
	, m_data(nullptr) {
	allocate_and_initialize();
}

Vector::Vector(int dimension, const int* data)
	: m_dimension(dimension)
	, m_data(nullptr) {
	allocate_and_initialize(data);
}

Vector::Vector(const Vector& object)
	: m_dimension(object.m_dimension)
	, m_data(nullptr) {
	allocate_and_initialize(object.m_data);
}

Vector& Vector::operator=(const Vector& object) {
	if (this != &object) {
		deallocate();
		m_dimension = object.m_dimension;
		allocate_and_initialize(object.m_data);
	}
	return *this;
}

Vector::~Vector() {
	deallocate();
}

int Vector::distance(const Vector& object) const {
	check_size(object);
	// TODO
	return -1;
}

int& Vector::operator[](int dimension) {
	check_dimension(dimension);
	return m_data[dimension];
}

const int& Vector::operator[](int dimension) const {
	check_dimension(dimension);
	return m_data[dimension];
}

Vector& Vector::operator+=(const Vector& object) {
	check_size(object);
	for (int i = 0; i < m_dimension; ++i) {
		m_data[i] += object.m_data[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& object) {
	check_size(object);
	for (int i = 0; i < m_dimension; ++i) {
		m_data[i] += object.m_data[i];
	}
	return *this;
}

int Vector::operator*(const Vector& object) {
	// TODO;
	return -1;
}

bool Vector::operator==(const Vector& object) const {
	if (m_dimension != object.m_dimension) {
		return false;
	}
	for (int i = 0; i < m_dimension; ++i) {
		if (m_data[i] != object.m_data[i]) {
			return false;
		}
	}
	return true;
}

void Vector::allocate_and_initialize(const int* data) {
	m_data = new int[m_dimension] {};
	if (data != nullptr) {
		for (int i = 0; i < m_dimension; ++i) {
			m_data[i] = data[i];
		}
	}
}

void Vector::deallocate() {
	delete[] m_data;
}

void Vector::check_dimension(int dimension) const {
	if (dimension < 0 || dimension >= m_dimension) {
		throw std::exception("Index is out of bounds.");
	}
}

void Vector::check_size(const Vector& object) const {
	if (m_dimension != object.m_dimension) {
		throw std::exception("Not correspondig dimensions of vectors.");
	}
}

Vector operator+(Vector v1, const Vector& v2) {
	return v1 += v2;
}

Vector operator-(Vector v1, const Vector& v2) {
	return v1 -= v2;
}

bool operator!=(const Vector& v1, const Vector& v2) {
	return !(v1 == v2);
}