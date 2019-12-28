#include "Table.h"

std::ostream& operator<<(std::ostream& out, const Table& object) {
	for (int i = 0; i < object.m_rows; ++i) {
		for (int j = 0; j < object.m_columns - 1; ++j) {
			out << object.m_data[i][j] << ' ';
		}
		out << object.m_data[i][object.m_columns - 1] << std::endl;
	}
	return out;
}

std::istream& operator<<(std::istream& in, Table& object) {
	// TODO
	return in;
}

Table::Table(int rows, int columns)
	: m_rows(rows)
	, m_columns(columns)
	, m_data(nullptr) {
	allocate_and_initialize();
}

Table::Table(int rows, int columns, const int* const* data) 
	: m_rows(rows)
	, m_columns(columns)
	, m_data(nullptr) {
	allocate_and_initialize(data);
}

Table::Table(const Table& object)
	: m_rows(object.m_rows)
	, m_columns(object.m_columns)
	, m_data(nullptr) {
	allocate_and_initialize(object.m_data);
}

Table& Table::operator=(const Table& object) {
	if (this != &object) {
		deallocate();
		m_rows = object.m_rows;
		m_columns = object.m_columns;
		allocate_and_initialize(object.m_data);
	}
	return *this;
}

Table::~Table() {
	deallocate();
}

int& Table::operator()(int row_index, int column_index) {
	check_row_index(row_index);
	check_column_index(column_index);	
	return m_data[row_index][column_index];
}

const int& Table::operator()(int row_index, int column_index) const {
	check_row_index(row_index);
	check_column_index(column_index);
	return m_data[row_index][column_index];
}

Table& Table::operator+=(const Table& object) {
	check_sum_and_diff_correct(object);
	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_columns; ++j) {
			m_data[i][j] += object.m_data[i][j];
		}
	}
	return *this;
}

Table& Table::operator-=(const Table& object) {
	check_sum_and_diff_correct(object);
	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_columns; ++j) {
			m_data[i][j] -= object.m_data[i][j];
		}
	}
	return *this;
}

Table& Table::operator*=(const Table& object) {
	check_mult_correct(object);
	int r = m_rows;
	int c = object.m_columns;
	int** tmp = new int* [r];
	for (int i = 0; i < r; ++i) {
		tmp[i] = new int[c];
	}
	// TODO
	deallocate();
	m_rows = r;
	m_columns = c;
	m_data = tmp;
	return *this;
}

void Table::allocate_and_initialize(const int* const* data) {
	m_data = new int* [m_rows];
	for (int i = 0; i < m_columns; ++i) {
		m_data[i] = new int[m_columns] {};
	}
	if (data != nullptr) {
		for (int i = 0; i < m_rows; ++i) {
			for (int j = 0; j < m_columns; ++j) {
				m_data[i][j] = data[i][j];
			}
		}
	}
}

void Table::deallocate() {
	for (int i = 0; i < m_rows; ++i) {
		delete[] m_data[i];
	}
	delete[] m_data;
}

void Table::check_row_index(int row_index) const {
	if (row_index < 0 || row_index >= m_rows) {
		throw std::exception("Row index is out of bounds.");
	}
}

void Table::check_column_index(int column_index) const {
	if (column_index < 0 || column_index >= m_columns) {
		throw std::exception("Column index is out of bounds.");
	}
}

void Table::check_sum_and_diff_correct(const Table& object) const {
	if (m_rows != object.m_rows || m_columns != object.m_columns) {
		throw std::exception("Not correspondig sizes of arguments.");
	}
}

void Table::check_mult_correct(const Table& object) const {
	if (m_columns != object.m_rows) {
		throw std::exception("Not correspondig sizes of arguments.");
	}
}

Table operator+(Table t1, const Table& t2) {
	return t1 += t2;
}

Table operator-(Table t1, const Table& t2) {
	return t1 -= t2;
}

Table operator*(Table t1, const Table& t2) {
	return t1 *= t2;
}