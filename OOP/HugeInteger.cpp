#include "HugeInteger.h"

// TODO implement
std::ostream& operator<<(std::ostream& out, const HugeInteger& object) {
	return out;
}

// TODO implement
std::istream& operator>>(std::istream& in, HugeInteger& object) {
	return in;
}

int HugeInteger::s_created_object_count = 0;

// TODO implement
HugeInteger::HugeInteger(int value) {
	++s_created_object_count;
}

// TODO implement
HugeInteger::HugeInteger(int length, const char* data) {
	++s_created_object_count;
}

// TODO implement
HugeInteger::HugeInteger(const HugeInteger& object) {
	++s_created_object_count;
}

// TODO implement
HugeInteger& HugeInteger::operator=(const HugeInteger& object) {
	if (this != &object) {
	}
	return *this;
}

// TODO implement
HugeInteger::~HugeInteger() {
}

// TODO implement
HugeInteger& HugeInteger::operator+=(const HugeInteger& object) {
	return *this;
}

// TODO implement
HugeInteger& HugeInteger::operator++() {
	return *this;
}

HugeInteger HugeInteger::operator++(int) {
	HugeInteger tmp(*this);
	operator++();
	return tmp;
}

// TODO implement
bool HugeInteger::operator==(const HugeInteger& object) const {
	return true;
}

// TODO implement
bool HugeInteger::operator<(const HugeInteger& object) const {
	return true;
}

// TODO implement
HugeInteger::operator int() {
	return -1;
}

HugeInteger operator+(HugeInteger I1, const HugeInteger& I2) {
	return I1 += I2;
}

bool operator!=(const HugeInteger& I1, const HugeInteger& I2) {
	return !(I1 == I2);
}

bool operator<=(const HugeInteger& I1, const HugeInteger& I2) {
	return (I1 == I2) || (I1 < I2);
}

bool operator>(const HugeInteger& I1, const HugeInteger& I2) {
	return !(I1 <= I2);
}

bool operator>=(const HugeInteger& I1, const HugeInteger& I2) {
	return (I1 == I2) || (I1 > I2);
}