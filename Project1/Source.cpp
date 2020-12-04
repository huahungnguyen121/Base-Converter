#include "Header.h"

const string binToHex[16] = { "0000", "0001" , "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
const string HexSign[16] = { "0", "1" , "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

string convertDec(unsigned long long x, bool mode)
{
	string value = "";

	//to bin
	if (mode) {
		unsigned long long temp = x;
		vector<int> a;

		while (temp != 0) {
			a.push_back(temp % 2);
			temp = temp / 2;
		}

		a.push_back(temp % 2);

		for (unsigned long long i = a.size(); i > 0; i--)
			value += to_string(a[i - 1]);

		return value;
	}
	else { //to hex
		string binTemp = "";
		unsigned long long temp = x;
		vector<int> a;

		while (temp != 0) {
			a.push_back(temp % 2);
			temp = temp / 2;
		}

		a.push_back(temp % 2);

		int pad = (4 - a.size() % 4) % 4;

		for (int i = 0; i < pad; i++)
			a.push_back(0);

		for (unsigned long long i = a.size(); i > 0; i--)
			binTemp += to_string(a[i - 1]);

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
	if (mode) { //to decimal
		unsigned long long value = 0;
		for (int i = bin.length() - 1; i > -1 ; i--) {
			value = value + stoi(bin.substr(bin.length() - 1 - i, 1)) * pow(2, i);
		}

		return to_string(value);
	}
	else { //to hex
		string value = "";
		string temp = "";

		int pad = (4 - bin.length() % 4) % 4;

		for (int i = 0; i < pad; i++)
			temp += "0";

		temp += bin;

		for (int i = 0; i < temp.length(); i += 4) {
			string buffer = temp.substr(i, 4);
			for (size_t j = 0; j < 16; j++) {
				if (buffer == binToHex[j])
				{
					if (j != 0)
						value += HexSign[j];
					else {
						if (temp.length() > 5 && i == 0)
							continue;
						value += HexSign[j];
					}
				}
			}
		}

		return value;
	}
}

string convertHex(string hex, bool mode)
{
	if (mode) { //to decimal
		unsigned long long value = 0;
		for (int i = hex.length() - 1; i > -1; i--) {
			int temp = (int)hex[hex.length() - 1 - i];
			if (temp > 64 && temp < 71)
				temp -= 55;
			else {
				if (temp > 47 && temp < 58)
					temp -= 48;
				else return "INPUT ERROR";
			}

			value = value + temp * pow(16, i);
		}

		return to_string(value);
	}
	else { //to bin
		string value = "";

		for (int i = 0; i < hex.length(); i++) {
			string buffer = hex.substr(i, 1);
			for (size_t j = 0; j < 16; j++) {
				if (buffer == HexSign[j])
					value += binToHex[j];
			}
		}

		size_t pos = value.find("1", 0);
		value = value.substr(pos, value.length() - pos);

		return value;
	}
}
