/*
 * Vectors.cpp
 *
 *  Created on: Sep 10, 2017
 *  Author: Carando  pjc78@txstate.edu
 *  Assignment 2 (Programming Assignment 1)
 *  Fun with Vectors
 */
#include <string>
#include <iostream>
#include <cstdlib>
#include<vector>

using namespace std;

// Specification: signature for computeMean is as below
double computeMean(vector<int> numbers);

// Specification: signature for computeMedian is as below
int computeMedian(vector<int> numbers);

// Specification: signature for searchLinear is as below
int searchLinear(int value, vector<int> numbers);
// Specification: signature for computeBinary is as below
int searchBinary(int value, vector<int> numbers);

// Specification: signature for selectionSort is as below
vector<int> selectionSort(vector<int> numbers, bool ascending);

// prototypes for "helper" functions for sort
vector<int> selectionSortDescending (vector<int> numbers);
vector<int> selectionSortAscending(vector<int> numbers);

// prototypes for "helper" functions for printing search information
void printSearchIntent (string searchType, int searchValue);
void printSearchResult (int searchValue, int searchLocation);
void printVector (vector <int>numbers);

int main() {
	// seed value used for initializing random number generator
	const unsigned int seed = 75025;
	// modulo value for random number generation
	const int UPPER_VALUE = 517;
	// maximum values in vector, odd number to assure single median
	const int COUNT = 101;
    // the vector used in these exercises
	vector<int> numbers(COUNT);

	// value to search for in vector
	int searchValue;
    // index location where value was found or -1 if not found
	int searchLocation;
    // the mean of the vector values
	double mean;
	// the median of the vector values
	int median;

	// initalize the random number generator for consistent sequence
	srand(seed);

	cout << "Vector of values randomly generated " << endl;
	for (int i = 0; i < COUNT; i++) {
		numbers[i] = rand() % UPPER_VALUE;
		cout << "value[" << i << "]: " << numbers[i] << endl;
	}

	cout << endl;

	cout << "Vector of values sorted (descending) by selection sort" << endl;
	numbers = selectionSort(numbers, false);
    printVector (numbers);

    cout << endl;
	cout << "Vector of values sorted (ascending) by selection sort" << endl;
	numbers = selectionSort(numbers, true);
    printVector (numbers);

	cout << endl << "****Linear Searches****" << endl;

	// Requirement 1: search for the smallest value in the vector using
	//     linear search; note: smallest value is at location 0 after sort ascending
	searchValue  = numbers[0];
	printSearchIntent ("linear search", searchValue);
	searchLocation = searchLinear(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	// Requirement 2: search for the largest value in the vector using
	//     linear search; note: smallest value is at location COUNT-1 after sort
	searchValue  = numbers[COUNT-1];
	printSearchIntent ("linear search", searchValue);
	searchLocation = searchLinear(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	// Requirement 3: search for the -1 in the vector using linear search;
	searchValue  = -1;
	printSearchIntent ("linear search", searchValue);
	searchLocation = searchLinear(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	// Requirement 4: search for the 1024 in the vector using linear search;
	searchValue  = 1024;
	printSearchIntent ("linear search", searchValue);
	searchLocation = searchLinear(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	cout << endl << "****Binary Searches****" << endl;

	// Requirement 5: search for the smallest value in the vector using
	//     binary search; note: smallest value is at location 0 after sort
	searchValue  = numbers[0];
	printSearchIntent ("binary search", searchValue);
	searchLocation = searchBinary(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	// Requirement 6: search for the largest value in the vector using
	//     binary search; note: largest value is at location COUNT-1 after sort
	searchValue  = numbers[COUNT-1];
	printSearchIntent ("binary search", searchValue);
	searchLocation = searchBinary(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	// Requirement 7: search for the -1 in the vector using binary search;
	searchValue  = -1;
	printSearchIntent ("binary search", searchValue);
	searchLocation = searchBinary(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	// Requirement 8: search for the 1024 in the vector using binary search;
	searchValue  = 1024;
	printSearchIntent ("binary search", searchValue);
	searchLocation = searchBinary(searchValue, numbers);
	printSearchResult (searchValue, searchLocation);

	// Requirement 9: compute the mediam
	median = computeMedian(numbers);
	cout << endl << "Median is " << median << endl << endl;

	// Requirement 10: compute the mean
	mean = computeMean(numbers);
	cout << "Mean is " << mean << endl << endl;
}

// Requirement: compute the mean of the vector values
double computeMean(vector<int> numbers) {
	int size = numbers.size();
	double total = 0;
	for (int i = 0; i < size; i++) {
		total = numbers[i] + total;
	}
	return total / size;
}

// Requirement: compute the median of the vector values; assume for
// this exercise the number of values in the vector is odd
int computeMedian(vector<int> numbers) {
	int size = numbers.size();
	int medianIndex = size / 2;
	return numbers[medianIndex];
}

// Requirement: perform a linear search for a specified value; return the
// index of the value if found, -1 if not found
int searchLinear(int value, vector<int> numbers) {
	const int NOT_FOUND = -1;
	int size = numbers.size();
	for (int i = 0; i < size; i++) {
		if (value == numbers[i])
			return i;
	}
	return NOT_FOUND;
}

// Requirement: perform a binary search for a specified value; return the
// index of the value if found, -1 if not found
int searchBinary(int value, vector<int> numbers) {
	const int NOT_FOUND = -1;
	int lowerBound = 0;
	int upperBound = numbers.size();
	int middle = (lowerBound + upperBound) / 2;
	int middleValue;

	while (lowerBound < upperBound) {
		middleValue = numbers[middle];
//		cout << "Search value " << value << " Middle value " <<  middleValue << " middle index " << middle << endl;
		if (value == middleValue) {
			return middle;

		} else if (value > middleValue) {
			lowerBound = middle + 1;
		} else {
			upperBound = middle - 1;
		}
		middle = (lowerBound + upperBound) / 2;
	}
	return NOT_FOUND;
}

// Use selection sort to sort values either from low to high (ascending)
// or from high to low (descending) depending on the value of boolean
// parameter "ascending"
vector<int> selectionSort(vector<int> numbers, bool ascending) {
    if (ascending) return selectionSortAscending (numbers);
    return selectionSortDescending (numbers);
}

vector<int> selectionSortAscending(vector<int> numbers) {
	int size = numbers.size();

	for (int i = 0; i < size; i++) {
		int currentMinimum = numbers[i];
		int currentMinimumIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (numbers[j] < currentMinimum) {
				currentMinimum = numbers[j];
				currentMinimumIndex = j;
			}
		}
		if (currentMinimumIndex != i) {
		    	int swapValue = numbers[i];
			    numbers[i] = numbers[currentMinimumIndex];
			    numbers[currentMinimumIndex] = swapValue;
		}
	}
	return numbers;
}

vector<int> selectionSortDescending (vector<int> numbers) {
	int size = numbers.size();
	int last  = size -1;

	for (int i = 0; i < size; i++) {
		int currentMaximum = numbers[i];
		int currentMaximumIndex = i;
		for (int j = i+1; j<size; j++) {
			if (numbers[j] > currentMaximum) {
				currentMaximum = numbers[j];
				currentMaximumIndex = j;
			}
		}
		if (currentMaximumIndex != i) {
		    	int swapValue = numbers[i];
			    numbers[i] = numbers[currentMaximumIndex];
			    numbers[currentMaximumIndex] = swapValue;
		}
	}
	return numbers;
}

// Helper function to label the search activity
void printSearchIntent (string searchType, int searchValue) {
	cout << "Searching for " << searchValue << " using " << searchType << endl;
}

// Helper function to label the search result
void printSearchResult (int searchValue, int searchLocation) {
	if (searchLocation != -1) {
		cout << "Found " << searchValue << " at location " << searchLocation << endl;
	} else {
		cout << "!!" << searchValue << " not found" << endl;
	}
}

void printVector (vector <int> numbers) {
	int size = numbers.size();
	for (int i = 0; i < size; i++) {
		cout << "value[" << i << "]: " << numbers[i] << endl;
	}
}
