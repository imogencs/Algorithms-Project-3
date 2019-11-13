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
		//		cout << "after recursive call" << endl;
		//		for (int i = 0; i < (int)pow(2,n-1); i++) {
		//			for (int j = 0; j < n-1; j++) {
		//				cout << grayCodesUpper[i][j];
		//			}
		//			cout << endl;
		//		}

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
	//return grayCodes;
}



void printTable(int n, char** grayCodes) {
	char* currentGrayCode = new char[4];
	int* abacadabra = new int[(int) pow(2,n)];
	abacaba(n, abacadabra);
	//	for (int i = 0; i < (int) pow(2,n); i++) {
	//		cout << abacadabra[i];
	//	}
	//	cout << endl;

	cout << "Index \tGray Code \tChild(ren) in Photo \t Action" << endl;
	for (int i = 0; i < (int) pow(2,n); i++) {
		cout << i << "\t";
		for (int j = n-1; j >= 0; j--) {
			cout << grayCodes[i][j];
		}
		cout << "\t\t";
		for (int j = n-1; j >= 0; j--) {
			if (grayCodes[i][j] == '1') {
				switch (j) {
				case 0 :
					cout << "Alice ";
					break;
				case 1 :
					cout << "Bob ";
					break;
				case 2 :
					cout << "Chris ";
					break;
				case 3 :
					cout << "Dylan ";
					break;
				}
				cout << "\t";
			}

		}
		switch (abacadabra[i]) {
		case 0 :
			cout << "Alice ";
			if (grayCodes[i][0] == '1') {
				cout << "out";
			}
			else {
				cout << "in";
			}
			break;
		case 1 :
			cout << "Bob ";
			if (grayCodes[i][1] == '1') {
				cout << "out";
			}
			else {
				cout << "in";
			}
			break;
		case 2 :
			cout << "Chris ";
			if (grayCodes[i][2] == '1') {
				cout << "out";
			}
			else {
				cout << "in";
			}
			break;
		case 3 :
			cout << "Dylan ";
			if (grayCodes[i][3] == '1') {
				cout << "out";
			}
			else {
				cout << "in";
			}
			break;
		}
		cout << endl;
	}

	cout << endl;
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
