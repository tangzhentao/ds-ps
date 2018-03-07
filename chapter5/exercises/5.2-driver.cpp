/*
 * 5.2-string-manipulation的驱动程序
 */
#include <iostream>
#include "5.2-string-manipulation.h"

using namespace std;

int main()
{
			char c = cin.get();
			int ic = c;
			cout << "[" << c << "]" << ic << endl;
			return 0;

	string str;
	string substr; 
	cout << "Test function: unsigned appearTimes(const string &substr, const string &str);" << endl;
	for ( ; ; )
	{
		cout << "ctrl - d to end" << endl;
		cout << "Please type a string: " << endl;
		cin >> str;
		cout << "Please type a substring: " << endl;
		cin >> substr;

		if (cin.eof())
		{
			cin.clear();
			cin.sync();
			if (cin.good())
				cout << "*** cin good ***" << endl;

			if (cin.fail())
				cout << "*** cin fail ***" << endl;

			if (cin.eof())
				cout << "*** cin eof" << endl;

			cin.ignore();
			char c = cin.get();
			int ic = c;
			cout << "[" << c << "]" << ic << endl;
			return 0;

			break;
		}

		int times = appearTimes(substr, str);
		cout << substr << '\n'
			 << "appears " << times << " times in \n"
			 << str << endl;

		cout << endl;
	}

	cout << "\nTest function: string monthName(unsigned month);" << endl;
	unsigned monthNumber;

	for ( ; ; )
	{
		cout << "Type the number of month(100 to end): ";
		cin >> monthNumber;
		if (100 == monthNumber)
			break;

		string name = monthName(monthNumber);
		cout << "The " << monthNumber << " month is " << name << endl;
	}

	cout << "\nTest function: nsigned monthNum(const string &month);" << endl;
	string monthName = "";
	for ( ; ; )
	{
		cout << "Type the name of month(e to end): ";
		cin >> monthName;
		if ("e" == monthName)
			break;

		unsigned num = monthNum(monthName);
		cout << "The number of " << monthName << " is " << num << endl;
	}
	return 0;
}
