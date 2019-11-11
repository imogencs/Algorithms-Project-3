// C2019 IMOLU!!!!!!!!!!!!!

#include <iostream> 
using namespace std;

/**
 * creates and returns a new string that contains only the letters and numbers
 * of the inputted string, and converted to lower case. 
 * (excludes whitespace and punctuation.)
 * @param oldStr the string
 * @return the new, converted string
 */
char* toLowerCase (char* oldStr) {
	char* newStr = new char[256];
	int newStrIndex = 0;
	int oldStrIndex = 0;
	while (*(oldStr+oldStrIndex) != '\0') {
		if (isalpha(*(oldStr+oldStrIndex)) || isdigit(*(oldStr+oldStrIndex))) {
			*(newStr+newStrIndex) = tolower(*(oldStr+oldStrIndex));
			newStrIndex++;
		}
		oldStrIndex++;
	}
	*(newStr+newStrIndex) = '\0'; // null terminate the string
	return newStr;
}



/** 
 * determines whether the given string is a palendrome
 * does not account for capitals, whitespace, or punctuation;
 * that must be done before passing the string in to isPalindrome().
 * uses recursion.
 * @param str the string
 * @param len the length of the string. during subsequent recursive calls to 
 *		isPalendrome(), len will correspond to the index of the char 
 * 		you need to check, rather than to the null terminator of
 * 		the actual string.
 * @return 0 if not a palendrome, 1 otherwise
 */
int isPalindrome (char* str, int len) {
	int isPal = 0;
	if (len == 0) {
		isPal = 1;
	}
	else if (len == 1) {
		isPal = 1; 
	}
	else {
		isPal = (str[0] == str[len-1]) && isPalindrome((str + sizeof(char)), len-2);
	}
	return isPal;
}



/**
 * executes isPalendrome() on the inputted string after stripping and converting it
 * using toLowerCase(); then prints the results.
 * The inputted string can be either given as a command line argument or as a std input
 * argument. 
 * @param argc number of elements in argv
 * @param argv command line arguments
 * @return 0
 */
int main (int argc, char** argv) {
	char* originalStr = new char[256];
	char* effectiveStr = new char[256];
	int len = 0;
	if (argc >= 2) {
		originalStr = argv[1];
	}
	else {
		cin >> originalStr;
	}
	
	effectiveStr = toLowerCase(originalStr);
	while (*(effectiveStr+len) != '\0') {
		len++;
	}

	cout << "Inputted String:  " << originalStr << endl;
	if (*effectiveStr == '\0') {
		cout << "Effective String: [empty]" << endl;
	}
	else {
		cout << "Effective String: " << effectiveStr << endl;
	}
	if (isPalindrome(effectiveStr, len)) {
		cout << "\"" << effectiveStr << "\"" << " is a palendrome!" << endl;
	}
	else {
		cout << "\"" << effectiveStr << "\"" << " is not a palendrome :(" << endl;
	}
	return 0;
}
		
