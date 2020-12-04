#include "Header.h"

const string binToHex[16] = { "0000", "0001" , "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
const string HexSign[16] = { "0", "1" , "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

string convertDec(int x, bool mode)
{
	string value = "";

	//to bin
	if (mode) {
		int temp = x;
		vector<int> a;

		while (temp != 0) {
			a.push_back(temp % 2);
			temp = temp / 2;
		}

		a.push_back(temp % 2);

		for (int i = a.size() - 1; i > -1; i--)
			value += to_string(a[i]);

		return value;
	}
	else { //to hex
		string binTemp = "";
		int temp = x;
		vector<int> a;

		while (temp != 0) {
			a.push_back(temp % 2);
			temp = temp / 2;
		}

		a.push_back(temp % 2);

		int pad = (4 - a.size() % 4) % 4;

		for (int i = 0; i < pad; i++)
			a.push_back(0);

		for (int i = a.size() - 1; i > -1; i--)
			binTemp += to_string(a[i]);

		for (int i = 0; i < a.size(); i += 4) {
			string buffer = binTemp.substr(i, 4);
			for (size_t j = 0; j < 16; j++) {
				if (buffer == binToHex[j])
				{
					if (j != 0)
						value += HexSign[j];
					else {
						if (a.size() > 5 && i == 0)
							continue;
						value += HexSign[j];
					}
				}
			}
		}

		return value;
	}
}

string convertBin(string bin, bool mode)
{
	return string();
}
