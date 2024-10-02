#include <iostream>
#include <cassert>
#include "ArrayShifter.hpp"

using namespace std;

void print_array(int *array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}

int main() {
	cout << "--Beginning tests. \n";

	int *testArray = new int[4] {10, 20, 30, 40};

	ArrayShifter::array_shift(testArray, 4, 1);

	print_array(testArray, 4);

	int* testArray2 = new int[4] {10, 20, 30, 40};

	ArrayShifter::array_shift(testArray2, 4, 8);

	print_array(testArray2, 4);

	//assert();

	cout << "--Tests completed successfully! \n";
}