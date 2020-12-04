#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void convertToUpper(string& s);
/*
mode = true: convert x in decimal to binary
mode = false: convert x in decimal to hex
*/
string convertDec(string in, bool mode);
/*
mode = true: convert bin to decimal
mode = false: convert bin to hex
*/
string convertBin(string bin, bool mode);
/*
mode = true: convert hex to decimal
mode = false: convert hex to bin
*/
string convertHex(string hex, bool mode);
void runMenu();

#endif