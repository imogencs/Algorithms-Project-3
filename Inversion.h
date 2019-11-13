//============================================================================
// Name        : HW3_Inversion.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/13/19
// Copyright   : 2019 IMGLU
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef INVERSION_H_
#define INVERSION_H_

int easyInversionCount(int* array, int arraySize);
int fastInversionCount(int array[], int arraySize);
int mergeSort(int array[], int temp[], int left, int right);
int merge(int array[], int temp[], int left, int right, int lastArrayIndex);

#endif /* INVERSION_H_ */
