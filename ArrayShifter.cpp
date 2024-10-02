#include <iostream>
#include "ArrayShifter.hpp"

using namespace std;

static void print_array(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}

static int convert_negative_shifted_index_to_positive_relative_to_size(int shiftedIndex, int size) {
	if (shiftedIndex >= 0) {
		return shiftedIndex;
	}

	shiftedIndex += size;
	convert_negative_shifted_index_to_positive_relative_to_size(shiftedIndex, size);
}

// [10, 20, 30, 40] shift 1 | \
// 10 (index 0) -> index: -1 % size (4) = index 3
// 20 (index 1) -> index: 0 % size (4) = index 0
// 30 (index 2) -> index: 1 % size (4) = index 1
// 40 (index 3) -> index: 2 % size (4) = index 2
void ArrayShifter::array_shift(int *&intArray, const int arraySize, const int shiftAmount)
{
	int *shiftedArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++) {
		const int SHIFTED_INDEX = i - shiftAmount;
		//const int NEW_INDEX = SHIFTED_INDEX % arraySize;
		const int NEW_INDEX = convert_negative_shifted_index_to_positive_relative_to_size(SHIFTED_INDEX, arraySize) % arraySize;

		cout << "Index: " << i << " Value: " << intArray[i] << " | shifted index: " << SHIFTED_INDEX << ", new index: " << NEW_INDEX << endl;
		shiftedArray[NEW_INDEX] = intArray[i];
		cout << "New value at NEW_INDEX (" << NEW_INDEX << ") in shiftedArray : " << shiftedArray[NEW_INDEX] << endl;
	}

	print_array(shiftedArray, arraySize);

	//delete[] intArray;
	intArray = shiftedArray;

	print_array(intArray, arraySize);
}
