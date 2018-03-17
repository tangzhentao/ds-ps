/*
 * 5.2-string-manipulation的驱动程序
 */
#include <iostream>
#include "5.2-string-manipulation.h"

using namespace std;

int main()
{
	string str;
	string substr; 
	cout << "Test function: unsigned appearTimes(const string &substr, const string &str);" << endl;
	for ( ; ; )
	{
		cout << "q to end" << endl;
		cout << "Please type a string: " << endl;

		cin >> str;
		// 判断是不是要结束测试
		if ("q" == str)
			break;

		cout << "Please type a substring: " << endl;
		cin >> substr;

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

	cout << "\nTest function: unsigned monthNum(const string &month);" << endl;
	string monthName = "";
	for ( ; ; )
	{
		cout << "Type the name of month(q to end): ";
		cin >> monthName;
		if ("q" == monthName)
			break;

		unsigned num = monthNum(monthName);
		cout << "The number of " << monthName << " is " << num << endl;
	}
	return 0;
}
