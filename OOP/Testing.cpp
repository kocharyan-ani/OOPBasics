#include "Testing.h"

#include "Array.h"
#include "BitVector.h"
#include "HugeInteger.h"
#include "MultiSet.h"
#include "Set.h"
#include "String.h"
#include "Table.h"
#include "Vector.h"

void Testing::test_for_array() {
	Array a1;
	a1.push_back(1);
	a1.push_back(2);
	a1.push_back(3);
	a1.push_back(4);
	std::cout << a1;
	a1.pop_back();
	a1.pop_back();
	std::cout << a1;

	const int n = 5;
	int a[5] = { 5, 4, 3, 2, 1 };
	Array a2(5, a);
	std::cout << a2;
	a2.insert(2, 100);
	std::cout << a2;
	a2.insert(5, 100);
	std::cout << a2;
	a2.insert(10, 100);
	std::cout << a2;
	a2.remove(10);
	std::cout << a2;
	a2.remove(5);
	std::cout << a2;
	a2.remove(2);
	std::cout << a2;

	Array a3(a2);
	a3.push_back(0);
	std::cout << a3;

	a1 = a3;
	std::cout << a1;

	Array a4;
	std::cout << "sizes: " << a1.size() << ", " << a2.size() << ", " << a3.size() << ", " << a4.size() << std::endl;
	std::cout << "empty: " << a1.is_empty() << ", " << a2.is_empty() << ", " << a3.is_empty() << ", " << a4.is_empty() << std::endl;

	std::cin >> a4;
	std::cout << a4;
}

void Testing::test_for_bitvector() {

}

void Testing::test_for_hugeinteger() {

}

void Testing::test_for_multiset() {

}

void Testing::test_for_set() {

}

void Testing::test_for_string() {

}

void Testing::test_for_table() {

}

void Testing::test_for_vector() {

}