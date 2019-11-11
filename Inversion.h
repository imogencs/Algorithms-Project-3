/*
 * HW3_Inversion.h
 *
 *  Created on: Nov 11, 2019
 *      Author: Jyalu
 */

#ifndef INVERSION_H_
#define INVERSION_H_

int easyInversionCount(int* array, int arraySize);
int fastInversionCount(int array[], int arraySize);
int mergeSort(int array[], int temp[], int left, int right);
int merge(int array[], int temp[], int left, int right, int lastArrayIndex);

#endif /* INVERSION_H_ */
