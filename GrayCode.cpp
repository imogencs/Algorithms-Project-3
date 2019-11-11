//============================================================================
// Name        : GrayCode.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/11/19
// Copyright   : 2019 IMGLU
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include "GrayCode.h"
using namespace std;

int main() {
	int n = 6;

	char* grayCodes = new char[(int) pow(2, n) - 1];

	grayCodes = grayCodesAreFun(n);
	for (int i = 0; i < pow(2, n) - 1; i++) {
		cout << grayCodes[i];
	}
	cout << endl;
	return 0;
}

//Generates recursively the binary reflected Gray code of order n
//Input: A positive integer n
//Output: A list of all bit strings of length n composing the Gray code
char* grayCodesAreFun(int n) {
	int size = (int) pow(2, n);
	cout << "size " << size << endl;
	char* grayCode = new char[size];
	char* grayCodeLeft = new char[(size + 1) / 2];
	char* grayCodeRight = new char[(size + 1) / 2];
	int grayCodeIndex = 0;

	if (n == 1) {
		cout << "here!" << endl;
//		make list L containing bit strings 0 and 1 in this order
//		grayCode = new int[2];
		grayCode[0] = '0';
		grayCode[1] = '1';


//
//		for (int i = 0; i < size; i++) {
//			cout << grayCode[i];
//		}
//cout << endl;
	}
	else {
		grayCodeLeft = grayCodesAreFun(n - 1);
		// copy list L1 to list L2 in reversed order
		for (int i = 0; i < (size + 1) / 2; i++) {
			grayCodeRight[i] = grayCodeLeft[(size + 1) / 2 - i];
		}
		grayCode[grayCodeIndex++] = '0'; // add 0 in front of each bit string in list L1
		for (int i = 0; i < (size + 1) / 2; i++) { // copy L1 to L
			grayCode[grayCodeIndex++] = grayCodeLeft[i];
		}
		grayCode[grayCodeIndex++] = '1'; // add 1 in front of each bit string in list L2
		for (int i = 0; i < (size + 1) / 2; i++) { // copy L2 to L after L1
			grayCode[grayCodeIndex++] = grayCodeLeft[i];
		}
	}
	return grayCode;
}
