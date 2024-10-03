#include <iostream>
#include <cassert>
#include "ArrayShifter.hpp"

using namespace std;

void print_array(int *array, int size) {
	cout << "Finished Array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}

void test_function(int *testArray, int *correctArrayAfterChange, int arraySize, int shiftAmount) {
	ArrayShifter::array_shift(testArray, arraySize, shiftAmount);

	//print_array(testArray, arraySize);
	assert(*testArray == *correctArrayAfterChange);

	delete testArray;
	delete correctArrayAfterChange;
}

int main() {
	cout << "--Beginning tests. \n";

	test_function(new int[4] {10, 20, 30, 40}, new int[4] {20, 30, 40, 10}, 4, 1);

	test_function(new int[4] {10, 20, 30, 40}, new int[4] {10, 20, 30, 40}, 4, 8);

	test_function(new int[4] {10, 20, 30, 40}, new int[4] {10, 20, 30, 40}, 4, 0); // Shift 0

	test_function(new int[4] {10, 20, 30, 40}, new int[4] {30, 40, 10, 20}, 4, 34); // Shift 34, AKA: 2

	test_function(new int[4] {10, 20, 30, 40}, new int[4] {10, 20, 30, 40}, 4, 800); // Shift 800, AKA: 0

	test_function(new int[50] {0}, new int[50] {0}, 50, 7); // Array with lots of 0

	test_function(new int[1] {5}, new int[1] {5}, 1, 7); // Array with 1 value

	cout << "--Tests completed successfully! \n";
}