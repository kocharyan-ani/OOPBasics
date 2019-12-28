#include "Array.h"

std::ostream& operator<<(std::ostream& out, const Array& object) {
	if (!object.is_empty()) {
		int i = 0;
		for (; i < object.m_size - 1; ++i) {
			out << object.m_data[i] << ' ';
		}
		out << object.m_data[i] << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Array& object) {
	if (!object.is_empty()) {
		object.m_size = 0;
	}
	int x{};
	while (in >> x) {
		object.push_back(x);
	}
	return in;
}

const int MAX_SIZE = 100;

Array::Array()
	: m_max_size(MAX_SIZE)
	, m_size(0)
	, m_data(nullptr) {
	allocate_and_initialize();
}

Array::Array(int size, const int* data)
	: m_max_size((size > MAX_SIZE) ? size : MAX_SIZE)
	, m_size(size)
	, m_data(nullptr) {
	allocate_and_initialize(data);
}

Array::Array(const Array& object)
	: m_max_size(object.m_max_size)
	, m_size(object.m_size)
	, m_data(nullptr) {
	allocate_and_initialize(object.m_data);
}

Array& Array::operator=(const Array& object) {
	if (this != &object) {
		deallocate();
		m_max_size = object.m_max_size;
		m_size = object.m_size;
		allocate_and_initialize(object.m_data);
	}
	return *this;
}

Array::~Array() {
	deallocate();
}

int& Array::operator[](int index) {
	check_index(index);
	return m_data[index];
}

const int& Array::operator[](int index) const {
	check_index(index);
	return m_data[index];
}

void Array::push_back(int element) {
	if (m_size == m_max_size) {
		m_max_size *= 2;
		int* tmp = new int[m_max_size];
		for (int i = 0; i < m_size; ++i) {
			tmp[i] = m_data[i];
		}
		delete[] m_data;
		m_data = tmp;
	}
	m_data[m_size++] = element;
}

void Array::pop_back() {
	if (!is_empty()) {
		--m_size;
		return;
	}
	throw std::exception("Array is empty.");
}

void Array::insert(int index, int element) {
	if (index < 0) {
		throw std::exception("Index is less than 0.");
	}
	if (index >= m_size) {
		push_back(element);
	}
	else {
		if (m_size == m_max_size) {
			m_max_size *= 2;
		}
		int* tmp = new int[m_max_size];
		for (int i = 0; i < index; ++i) {
			tmp[i] = m_data[i];
		}
		tmp[index] = element;
		for (int i = index + 1; i < m_size; ++i) {
			tmp[i] = m_data[i - 1];
		}
		delete[] m_data;
		m_data = tmp;
		++m_size;
	}
}

void Array::remove(int index) {
	if (index < 0) {
		throw std::exception("Index is less than 0.");
	}
	if (index >= m_size) {
		pop_back();
	}
	else {
		int* tmp = new int[m_max_size];
		for (int i = 0; i < index; ++i) {
			tmp[i] = m_data[i];
		}
		for (int i = index; i < m_size - 1; ++i) {
			tmp[i] = m_data[i + 1];
		}
		delete[] m_data;
		m_data = tmp;
		--m_size;
	}
}

void Array::allocate_and_initialize(const int* data) {
	m_data = new int[m_max_size] {};
	if (data != nullptr) {
		for (int i = 0; i < m_size; ++i) {
			m_data[i] = data[i];
		}
	}
}

void Array::deallocate() {
	delete[] m_data;
}

void Array::check_index(int index) const {
	if (index < 0 || index >= m_size) {
		throw std::exception("Index is out of bounds.");
	}
}