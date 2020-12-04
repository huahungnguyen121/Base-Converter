#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
mode = true: convert x in decimal to binary
mode = false: convert x in decimal to hex
*/
string convertDec(int x, bool mode);
/*
mode = true: convert bin to decimal
mode = false: convert bin to hex
*/
string convertBin(string bin, bool mode);

#endif