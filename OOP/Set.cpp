#include "Set.h"

#include <algorithm>

std::ostream& operator<<(std::ostream& out, const Set& object) {
	for (int i = 0; i < Set::s_set_limit; ++i) {
		if (object.m_data[i]) {
			out << i << ' ';
		}
	}
	out << std::endl;
	return out;
}

Set::Set()
	: m_size(0)
	, m_data(nullptr) {
	m_data = new bool[s_set_limit] {};
}

Set::Set(int size, const int* data)
	: m_size(size)
	, m_data(nullptr) {
	m_data = new bool[s_set_limit] {};
	for (int i = 0; i < m_size; ++i) {
		m_data[data[i]] = true;
	}
}

Set::Set(const Set& object) {
	allocate_and_initialize(object.m_data);
}

Set::~Set() {
	deallocate();
}

Set& Set::operator=(const Set& object) {
	if (this != &object) {
		deallocate();
		allocate_and_initialize(object.m_data);
	}
	return *this;
}

bool Set::contains(int element) const {
	check_size(element);
	return m_data[element];
}

bool Set::is_sub_set(const Set& object) const {
	for (int i = 0; i < s_set_limit; ++i) {
		if (object.m_data[i] && !m_data[i]) {
			return false;
		}
	}
	return true;
}

Set& Set::operator&=(const Set& object) {
	for (int i = 0; i < s_set_limit; ++i) {
		m_data[i] = m_data[i] || object.m_data[i];
	}
	return *this;
}

Set& Set::operator|=(const Set& object) {
	for (int i = 0; i < s_set_limit; ++i) {
		m_data[i] = m_data[i] && object.m_data[i];
	}
	return *this;
}

Set& Set::operator-=(const Set& object) {
	for (int i = 0; i < s_set_limit; ++i) {
		if (m_data[i] && object.m_data[i]) {
			m_data[i] = false;
		}
	}
	return *this;
}

bool Set::operator==(const Set& object) const {
	for (int i = 0; i < s_set_limit; ++i) {
		if (m_data[i] != object.m_data[i]) {
			return false;
		}
	}
	return true;
}

void Set::allocate_and_initialize(const bool* data) {
	m_data = new bool[s_set_limit] {};
	for (int i = 0; i < s_set_limit; ++i) {
		m_data[i] = data[i];
	}
}

void Set::deallocate() {
	delete[] m_data;
}

void Set::check_size(int element) const {
	if (element < 0 || element >= s_set_limit) {
		throw std::exception("Element is out of limits.");
	}
}

Set operator&(Set ms1, const Set& ms2) {
	return ms1 &= ms2;
}

Set operator|(Set ms1, const Set& ms2) {
	return ms1 |= ms2;
}

Set operator-(Set ms1, const Set& ms2) {
	return ms1 -= ms2;
}

bool operator!=(const Set& ms1, const Set& ms2) {
	return !(ms1 == ms2);
}