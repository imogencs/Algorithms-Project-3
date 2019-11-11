#include <iostream> 
using namespace std;


char* toLowerCase (char* oldStr) {
	char* newStr = new char[256];
	int newStrIndex = 0;
	int oldStrIndex = 0;
	while (*(oldStr+oldStrIndex) != '\0') {
		if (isalpha(*(oldStr+oldStrIndex))) {
			*(newStr+newStrIndex) = tolower(*(oldStr+oldStrIndex));
			newStrIndex++;
		}
		oldStrIndex++;
	}
	*(newStr+newStrIndex) = '\0'; // null terminate the string
	return newStr;
}

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

	if (isPalindrome(effectiveStr, len)) {
		cout << "\"" << originalStr << "\"" << " is a palendrome!" << endl;
	}
	else {
		cout << "\"" << originalStr << "\"" << " is not a palendrome :(" << endl;
	}
	return 0;
}
		
