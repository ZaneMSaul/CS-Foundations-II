/*
 * Main.cpp
 *
 *  Created on: Sep 19, 2017
 *      Author: two
 *      A program illustrating dynamic allocation of memory, dynamic resizing, and
 *      copying original values into a dynamically allocated array but in reverse order
 */
#include<iostream>
using namespace std;

// The function that "resizes" the memory for an array, usually allocating
// more memory
int *resize(int * arrayPointer, int currentSize, int newSize);

// A helper function to print the values in an array
void printValues(int *arrayPointer, int size);

// The function that allocates memory for the reverse copy of the input
// array and creates the reverse copy
int * reverse (int *arrayPointer, int size) ;

int main() {
	 // Various resizing values -- NOTE: resizing to a smaller value can be
	 // very dangerous!
	const int SIZE1 = 10;
	const int SIZE2 = 25;
	const int SIZE3 = 60;
	const int SIZE4 =   8;

	// Dynamically allocate memory for the pointer based array
	// Assign some values and print them
	int *arrayPointer = new int[SIZE1];
	for (int i = 0; i < SIZE1; i++) {
		arrayPointer[i] = i;
	}
	printValues(arrayPointer, SIZE1);

	// Get a copy of the original array reversed. Print those values
	int *reverseArray  = reverse(arrayPointer, SIZE1);
	printValues (reverseArray, SIZE1);

	// Resize the original array. Add some values into the new array
	// that illustrate where we "added" memory (we didn't really add
	// it, we grabbed more memory from a new location and deleted
	// the old memory
	int index = 0;
	arrayPointer = resize(arrayPointer, SIZE1, SIZE2);
	cout << "Setting values for indices " << SIZE1 << " to " << SIZE2 << endl;
	for (int i=SIZE1; i<SIZE2; i++) {
		arrayPointer[i] = index;
		index++;
	}
	printValues(arrayPointer, SIZE2);

	// Do another resize as we did above
	index = 0;
	arrayPointer = resize(arrayPointer, SIZE2, SIZE3);
	for (int i=SIZE2; i<SIZE3; i++) {
		arrayPointer[i] = index;
		index++;
	}
	printValues(arrayPointer, SIZE3);

	// Danger! Danger! Will Robinson!
	// Resize the array to a much smaller size
	arrayPointer = resize(arrayPointer, SIZE3, SIZE4);
	printValues(arrayPointer, SIZE4);
}

// The function that "resizes" the memory for an array, usually allocating
// more memory
int * resize(int *arrayPointer, int currentSize, int newSize) {
	int *newArrayPointer = new int[newSize];
	for (int i = 0; i < currentSize; i++) {
		newArrayPointer[i] = arrayPointer[i];
	}

	delete[] arrayPointer;
	return newArrayPointer;
}

// The function that allocates memory for the reverse copy of the input
// array and creates the reverse copy
int * reverse (int *arrayPointer, int size) {
   int * reverseArrayPointer = new int[size];
   int fromTheEnd = size - 1;
   for (int i=0;i<size; i++) {
	   cout << "@@@@@ in reverse: putting value at " << i << " into location " << fromTheEnd << endl;
	   reverseArrayPointer [fromTheEnd] = arrayPointer[i];
	   fromTheEnd--;
   }
   return reverseArrayPointer;
}

// A helper function to print the values in an array
void printValues(int *arrayPointer, int size) {
	cout << "Values for array at " << arrayPointer << " with size " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << "array[" << i << "]: " << arrayPointer[i] << endl;
	}
	cout << endl;
}

