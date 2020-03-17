#pragma once

#include <iostream>

/*Class objects are arrays with variable size.*/
class Array {
	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);

public:
	Array();	// default ctor
	Array(int, const int*);	// ctor with parameters
	Array(const Array&);	// copy ctor
	Array& operator=(const Array&);	// assignment operator
	~Array();	// dtor

	int size() const { return m_size; }
	bool is_empty() const { return m_size == 0; }

	int& operator[](int);
	const int& operator[](int) const;

	void push_back(int);	// add a new element to the end of the array
	void pop_back();	// remove the last element from the array
	void insert(int, int);	// add a new element at the given index of the array
	void remove(int);	// remove the given element from the array

private:
	void allocate_and_initialize(const int* = nullptr);
	void deallocate();

	void check_index(int) const;

private:
	int m_max_size;
	int m_size;
	int* m_data;
};