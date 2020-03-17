#pragma once

#include <iostream>

/*Class objects are matrixes.*/
class Table {
	friend std::ostream& operator<<(std::ostream&, const Table&);
	friend std::istream& operator>>(std::istream&, Table&);

public:
	// class does not have default ctor
	Table(int, int);	// ctor with parameters
	Table(int, int, const int* const *);	// ctor with parameters
	Table(const Table&);	// copy ctor
	Table& operator=(const Table&);	// assignment operator
	~Table();	// dtor

	int row_count() const { return m_rows; }
	int column_count() const { return m_columns; }

	int& operator()(int, int);	// [i][j]
	const int& operator()(int, int) const;

	Table& operator+=(const Table&);
	Table& operator-=(const Table&);
	Table& operator*=(const Table&);

private:
	void allocate_and_initialize(const int* const* = nullptr);
	void deallocate();

	void check_row_index(int) const;
	void check_column_index(int) const;
	
	void check_sum_and_diff_correct(const Table&) const;
	void check_mult_correct(const Table&) const;

private:
	int m_rows;
	int m_columns;
	int** m_data;
};

Table operator+(Table, const Table&);
Table operator-(Table, const Table&);
Table operator*(Table, const Table&);