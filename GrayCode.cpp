//============================================================================
// Name        : GrayCode.cpp
// Author      : Imogen Cleaver-Stigum & Jyalu Wu
// Version     : 11/12/19
// Copyright   : 2019 IMGLU
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include "GrayCode.h"
using namespace std;

int main() {
	int n = 4;

	//char grayCodes[(int) pow(2,n)][n];
	char **grayCodes;
	grayCodes = new char *[(int) pow(2,n)];
	for(int i = 0; i < (int) pow(2,n); i++)
		grayCodes[i] = new char[n];

	newGrayCode(n, grayCodes);
//	for (int i = 0; i < (int)pow(2,n); i++) {
//		for (int j = n-1; j >= 0; j--) {
//			cout << grayCodes[i][j];
//		}
//		cout << endl;
//	}	cout << endl; cout.flush();

	printTable(n, grayCodes);
	return 0;
}

//Generates recursively the binary reflected Gray code of order n
//Input: A positive integer n
//Output: A list of all bit strings of length n composing the Gray code
void newGrayCode(int n, char **grayCodes) {
	int numGrayCodes = (int) pow(2, n);
	//	char grayCodesUpper[numGrayCodes][n];
	char **grayCodesUpper;
	grayCodesUpper = new char *[numGrayCodes / 2];
	for(int i = 0; i < numGrayCodes / 2; i++)
		grayCodesUpper[i] = new char[n];

	//	char grayCodesLower[numGrayCodes][n];
	char **grayCodesLower;
	grayCodesLower = new char *[numGrayCodes / 2];
	for(int i = 0; i < numGrayCodes / 2; i++)
		grayCodesLower[i] = new char[n];

	if (n == 1) {
		//		make list L containing bit strings 0 and 1 in this order
		grayCodes[0][0] = '0';
		grayCodes[1][0] = '1';
	}
	else {
		newGrayCode(n - 1, grayCodesUpper);

		// copy list L1 to list L2 in reversed order
		for (int i = 0; i < numGrayCodes/2; i++) {
			for (int j = 0; j < n-1; j++) {
				grayCodesLower[i][j] = grayCodesUpper[numGrayCodes/2-i-1][j];
			}
		}

		// add 0 in front of each bit string in list L1
		for (int i = 0; i < numGrayCodes/2; i++) { // copy L1 to L
			grayCodesUpper[i][n-1] = '0';
		}
		for (int i = 0; i < numGrayCodes/2; i++) { // copy L1 to L
			grayCodesLower[i][n-1] = '1';
		}

		// copy L1 and L2 into L
		for (int i = 0; i < numGrayCodes/2; i++) {
			for (int j = 0; j < n; j++) {
				grayCodes[i][j] = grayCodesUpper[i][j];
			}
		}
		for (int i = 0; i < numGrayCodes/2; i++) {
			for (int j = 0; j < n; j++) {
				grayCodes[i+numGrayCodes/2][j] = grayCodesLower[i][j];
			}
		}
	}
}



void printTable(int n, char** grayCodes) {

	const char separator = ' ';
	const int indexWidth = 10;
	const int grayCodeWidth = 15;
	const int childrenWidth = 30;
	const int actionWidth = 11;
	const int size = (int) pow(2,n);

	char* currentGrayCode = new char[n];
	int* abacadabra = new int[size];
	string childrenList = "";
	string action = "";

	abacaba(n, abacadabra);

	// print out headers
	cout << left << setw(indexWidth) << setfill(separator) << "Index";
	cout << left << setw(grayCodeWidth) << setfill(separator) << "Gray Code";
	cout << left << setw(childrenWidth) << setfill(separator) << "Child(ren) in Photo";
	cout << left << setw(actionWidth) << setfill(separator) << "Action";
	cout << endl;
	cout << left << setw(indexWidth + grayCodeWidth + childrenWidth + actionWidth) << setfill('-') <<"";
	cout << endl;

	// for all of the gray codes
	for (int i = 0; i < size; i++) {
		// get the next gray code
		for (int j = n-1; j >= 0; j--) {
			currentGrayCode[n - j - 1] = grayCodes[i][j];
		}

		// get the list of children
		for (int j = 0; j < n; j++) {
			if (currentGrayCode[j] == '1') {
				switch (j) {
				case 3 :
					childrenList = childrenList + "Alice ";
					break;
				case 2 :
					childrenList = childrenList + "Bob ";
					break;
				case 1 :
					childrenList = childrenList + "Chris ";
					break;
				case 0 :
					childrenList = childrenList + "Dylan ";
					break;
				}
			}
		}
		// get the action
		switch (abacadabra[i]) {
		case 0 :
			action = action + "Alice ";
			if (currentGrayCode[0] == '1') {
				action = action + "Out";
			}
			else {
				action = action + "In";
			}
			break;
		case 1 :
			action = action + "Bob ";
			if (currentGrayCode[1] == '1') {
				action = action + "Out";
			}
			else {
				action = action + "In";
			}
			break;
		case 2 :
			action = action + "Chris ";
			if (currentGrayCode[2] == '1') {
				action = action + "Out";
			}
			else {
				action = action + "In";
			}
			break;
		case 3 :
			action = action + "Dylan ";
			if (currentGrayCode[3] == '1') {
				action = action + "Out";
			}
			else {
				action = action + "In";
			}
			break;
		}

		cout << left << setw(indexWidth) << setfill(separator) << i;
		cout << left << setw(grayCodeWidth) << setfill(separator) << currentGrayCode;
		cout << left << setw(childrenWidth) << setfill(separator) << childrenList;
		cout << left << setw(actionWidth) << setfill(separator) << action;
		cout << endl;

		childrenList = "";
		action = "";
	}
}


void abacaba(int n, int* abracadabra) {
	if (n == 1) {
		abracadabra[n-1] = 0;
	}
	else {
		abacaba(n-1, abracadabra);
		abracadabra[(int) (pow(2,n-1))-1] = n-1;
		for (int i = 0; i < (int) pow(2,n-1)-1; i++) {
			abracadabra[i + (int) pow(2,n-1)] = abracadabra[i];
		}

	}
}
