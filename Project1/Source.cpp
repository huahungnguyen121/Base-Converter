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
				if (buffer == binToHex[j]) {
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
	for (int i = 0; i < bin.length(); i++) {
		int check = stoi(bin.substr(i, 1));
		if (check != 1 && check != 0)
			return "INPUT ERROR";
	}

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
		bool flag = false;

		for (int i = 0; i < hex.length(); i++) {
			string buffer = hex.substr(i, 1);
			for (size_t j = 0; j < 16; j++) {
				if (buffer == HexSign[j]) {
					value += binToHex[j];
					flag = true;
				}
			}
			if (!flag)
				return "INPUT ERROR";
			flag = false;
		}

		size_t pos = value.find("1", 0);
		value = value.substr(pos, value.length() - pos);

		return value;
	}
}

void runMenu()
{
	while (true) {
		system("cls");
		cout << "[Converter v1.0]\n\n";

		cout << "=============Choose-Input-Base============\n";
		cout << "1. Decimal\n";
		cout << "2. Hexadecimal\n";
		cout << "3. Binary\n";
		cout << "4. Exit Program\n";
		cout << "==========================================\n";
		cout << "--> Your choice: \n";
		string in = "";
		getline(cin, in, '\n');

		while (in.length() > 1 || (int)in[0] > 52 || (int)in[0] < 48) {
			cout << "==========================================\n";
			cout << "WRONG OPTION!!! Please Try Again\n";
			cout << "--> Your choice: \n";
			in = "";
			getline(cin, in, '\n');
		}

		int fromBase = (int)in[0] - 48;

		if (fromBase == 4)
			break;

		system("cls");
		cout << "[Converter v1.0]\n\n";

		cout << "========Choose-Base-Want-To-Convert=======\n";
		cout << "1. Decimal\n";
		cout << "2. Hexadecimal\n";
		cout << "3. Binary\n";
		cout << "4. Exit Program\n";
		cout << "==========================================\n";
		cout << "--> Your choice: \n";
		in = "";
		getline(cin, in, '\n');

		while (in.length() > 1 || (int)in[0] > 52 || (int)in[0] < 48) {
			cout << "==========================================\n";
			cout << "WRONG OPTION!!! Please Try Again\n";
			cout << "--> Your choice: \n";
			in = "";
			getline(cin, in, '\n');
		}

		int toBase = (int)in[0] - 48;

		if (toBase == 4)
			break;

		system("cls");
		cout << "[Converter v1.0]\n\n";

		cout << "================Input-Data================\n";
		cout << "--> Enter your number: \n";
		in = "";
		getline(cin, in, '\n');

		cout << "==================Result==================\n";

		if (fromBase == 1) {
			if (toBase == 1)
				cout << "--> " << in << endl;
			if (toBase == 2)
				cout << "--> " << convertDec(stoull(in), false) << endl;
			if (toBase == 3)
				cout << "--> " << convertDec(stoull(in), true) << endl;
		}
		if (fromBase == 2) {
			if (toBase == 1)
				cout << "--> " << convertHex(in, true) << endl;
			if (toBase == 2)
				cout << "--> " << in << endl;
			if (toBase == 3)
				cout << "--> " << convertHex(in, false) << endl;
		}
		if (fromBase == 3) {
			if (toBase == 1)
				cout << "--> " << convertBin(in, true) << endl;
			if (toBase == 2)
				cout << "--> " << convertBin(in, false) << endl;
			if (toBase == 3)
				cout << "--> " << in << endl;
		}
		system("pause");
	}
}