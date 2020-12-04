#include "Header.h"

int main() {
	cout << convertDec(123456789, false) << endl;

	string test = "111010110111100110100010101";

	cout << convertBin(test, false) << endl;

	cout << convertHex(convertDec(123456789, false), false) << endl;

	return 0;
}