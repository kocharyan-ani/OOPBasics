#include "HugeInteger.h"

std::ostream& operator<<(std::ostream& out, const HugeInteger& object) {
	// TODO
	return out;
}

std::istream& operator>>(std::istream& in, HugeInteger& object) {
	// TODO
	return in;
}

int HugeInteger::s_created_object_count = 0;

HugeInteger::HugeInteger(int value) {
	++s_created_object_count;
}

HugeInteger::HugeInteger(int length, const char* data) {
	++s_created_object_count;
}

HugeInteger::HugeInteger(const HugeInteger& object) {
	++s_created_object_count;
}

HugeInteger& HugeInteger::operator=(const HugeInteger& object) {
	// TODO
	return *this;
}

HugeInteger::~HugeInteger() {

}

HugeInteger& HugeInteger::operator+=(const HugeInteger& object) {
	// TODO
	return *this;
}

HugeInteger& HugeInteger::operator++() {
	// TODO
	return *this;
}

HugeInteger HugeInteger::operator++(int) {
	HugeInteger tmp(*this);
	operator++();
	return tmp;
}

bool HugeInteger::operator==(const HugeInteger& object) const {
	// TODO
	return true;
}

bool HugeInteger::operator<(const HugeInteger& object) const {
	// TODO
	return true;
}

HugeInteger::operator int() {
	// TODO
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