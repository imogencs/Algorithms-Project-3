//============================================================================
// Name        : HW3_Inversion.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/11/19
// Copyright   : 2019 IMGLU
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Inversion.h"
using namespace std;

int main(int argc, char** argv) {
	int* array ;//= new int[256];
	int arraySize = 0;

	if (argc > 1) { // get user array
		array = new int[argc - 1];
		arraySize = argc - 1;
		for (int i = 1; i <= arraySize; i++) {
			array[i-1] = atoi(*(argv + i));
		}
		cout << "Naive inversion count: " << easyInversionCount(array, arraySize) << endl;
		cout << "Fast inversion count: " << fastInversionCount(array, arraySize) << endl;
	}
	else {
		cout << "You forgot to specify an array :(" << endl;
	}

	return 0;
}

/*
 * Counts the number of inversions in the given array in O(n^2).
 * @param array The array
 * @param arraySize The size of the array
 * @return The number of inversions in the given array.
 */
int easyInversionCount(int* array, int arraySize) {
	int count = 0;

	for (int i = 0; i < arraySize - 1; i++) {
		for (int j = i + 1; j < arraySize; j++) {
			if (array[i] > array[j]) {
				count++;
			}
		}
	}
	return count;
}

/*
 * Counts the number of inversions in the given array in O(nlogn).
 * @param array The array
 * @param arraySize The size of the array
 * @return The number of inversions in the given array.
 */
int fastInversionCount(int array[], int arraySize) {
    int temp[arraySize];
    return mergeSort(array, temp, 0, arraySize - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
/*
 * Sorts the given array according to the left and right indices and
 * counts the number of inversions in the array.
 * @param array The given array
 * @param temp A temporary array to store the newly sorted array
 * @param left The starting index of the left subarray
 * @param right The starting index of the right subarray
 * @return The number of inversions of the array
 */
int mergeSort(int array[], int temp[], int left, int right) {
    int mid, count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        count = mergeSort(array, temp, left, mid);
        count += mergeSort(array, temp, mid + 1, right);

        count += merge(array, temp, left, mid + 1, right);
    }
    return count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
/*
 * Merges the two sorted arrays and returns inversion count in the arrays.
 * @param array The given array
 * @param temp A temporary array to store the newly sorted array
 * @param left The starting index of the left subarray
 * @param mid The starting index of the left subarray
 * @param right The starting index of the right subarray
 * @
 */
int merge(int array[], int temp[], int left, int right, int lastArrayIndex) {
    int count = 0;
    int leftIndex = left;
    int rightIndex = right;
    int mergeIndex = left;

    while ((leftIndex <= right - 1) && (rightIndex <= lastArrayIndex)) {
        if (array[leftIndex] <= array[rightIndex]) {
            temp[mergeIndex++] = array[leftIndex++];
        }
        else {
            temp[mergeIndex++] = array[rightIndex++];
            count += (right - leftIndex);
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (leftIndex <= right - 1)
        temp[mergeIndex++] = array[leftIndex++];

    /* Copy the remaining elements of right subarray
(if there are any) to temp*/
    while (rightIndex <= lastArrayIndex)
        temp[mergeIndex++] = array[rightIndex++];

    /*Copy back the merged elements to original array*/
    for (leftIndex = left; leftIndex <= lastArrayIndex; leftIndex++)
    	array[leftIndex] = temp[leftIndex];

    return count;
}
