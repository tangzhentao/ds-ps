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
	cout << "Please type a string: " << endl;
	cin >> str;
	cout << "Please type a substring: " << endl;
	cin >> substr;

	int times = appearTimes(substr, str);
	cout << substr << '\n'
		 << "appears " << times << " times in \n"
		 << str << endl;

	cout << endl;

	cout << "Test function: string monthName(unsigned month);" << endl;
	unsigned monthNum;
	while (100 != monthNum) 
	{
		cout << "Type the number of month(100 to end): ";
		cin >> monthNum;
		string name = monthName(monthNum);
		cout << "The " << monthNum << " month is " << name << endl;
	}

	return 0;
}
