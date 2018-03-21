/*
 * 5.2-string-manipulation的驱动程序
 */
#include <iostream>
#include "5.2-string-manipulation.h"

using namespace std;

void testIsAnagram ()
{
	cout << "Test function: bool isAnagram(const string &str1, const string &str2)" << endl;
	while (1)
	{
		cout << "Type a str.(q to end)" << endl;
		string str;
		getline(cin, str);
		if ("q" == str)
		{
			cout << "end the test." << endl;
			break;
		}

		cout << "type another str:" << endl;
		string aStr;
		getline(cin, aStr);

		cout << "You typed: \n" << str << endl;
		cout << aStr;
		bool b = isAnagram(str, aStr);
		cout << str << endl;
		cout << '&' << endl;
		cout << aStr << endl;
		cout << (b ? "are " : "are not ") << "anagram" << endl;
	}
}

void testIsPlalindrome ()
{
	cout << "Test function: bool isPlalindrome(const string & str)" << endl;
	while (1)
	{
		cout << "Type a string.(q to end)" << endl;
		string str;
		cin >> str;
		if ("q" == str)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "You typed: " << str << endl;
		bool b = isPlalindrome(str);
		cout << str << " is plalindrome ?  " << boolalpha << b << endl;
	}
}
void testStringToF ()
{
	cout << "Test function: double stringToF(const string & fString)" << endl;
	while (1)
	{
		cout << "Type a decimal string.(q to end)" << endl;
		string str;
		cin >> str;
		if ("q" == str)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "You typed: " << str << endl;
		double f = stringToF(str);
		cout << "decimal: " << f << endl;
	}
}
void testStringToI ()
{
	cout << "Test function: int stringToI(const string & iStr)" << endl;
	while (1)
	{
		cout << "Type a digit  string.(q to end)" << endl;
		string str;
		cin >> str;
		if ("q" == str)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "You typed: " << str << endl;
		int i = stringToI(str);
		cout << "digit: " << i << endl;
	}
}

void testUpper ()
{
	cout << "Test function: string upper(const string str)" << endl;
	while (1)
	{
		cout << "Type a string to upper.(q to end)" << endl;
		string str;
		cin >> str;
		if ("q" == str)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "You typed: " << str << endl;
		string upperStr = upper(str);
		cout << "upper str: " << upperStr << endl;
	}
}

void testLower ()
{
	cout << "Test function: string lower(const string str)" << endl;
	while (1)
	{
		cout << "Type a string to lower.(q to end)" << endl;
		string str;
		cin >> str;
		if ("q" == str)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "You typed: " << str << endl;
		string lowerStr = lower(str);
		cout << "lower str: " << lowerStr << endl;
	}
}

void testReplace_all ()
{
	cout << "Test function:  string replace_all(const string str, const string substr, const string newSubstr)" << endl;
	while (1)
	{
		cout << "Type a string to replace.(q to end)" << endl;
		string str;
		cin >> str;
		if ("q" == str)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "You typed string: " << str << endl;
		cout << "Type a substr" << endl;
		string substr;
		cin >> substr;
		cout << "You typed substr: " << substr << endl;
		cout << "Type a newSubstr" << endl;
		string newSubstr;
		cin >> newSubstr;
		cout << "You typed newStr: " << newSubstr << endl;
		string newStr = replace_all(str, substr, newSubstr);
		cout << "newStr: " << newStr<< endl;
	}
}

void testFormatName1 ()
{
	cout << "Test function: string formatName1(const string name, const string mName, const string lName)" << endl;
	while (1)
	{
		cout << "Type a name.(q to end): " << endl;
		string name;
		cin >> name;
		if ("q" == name)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "Type a middle name: " << endl;
		string mName;
		cin >> mName;

		cout << "Type a last name: " << endl;
		string lName;
		cin >> lName;

		string newName = formatName1(name, mName, lName);
		cout << "The formated name is: " << newName << endl;
	}
}

void testFormatName2 ()
{
	cout << "Test function: string formatName2(const string name)" << endl;
	while (1)
	{
		cout << "Type a name, formart is [name midname lastName].(q to end)" << endl;
		string name;
		getline(cin, name);
		if ("q" == name)
		{
			cout << "end the test." << endl;
			break;
		}
		cout << "You typed: " << name<< endl;
		string newName = formatName2(name);
	}
}

int main()
{
	testIsAnagram();
	cout << endl;

	testIsPlalindrome();
	cout << endl;

	testStringToF();
	cout << endl;

	testStringToI();
	cout << endl;

	testFormatName2();
	cout << endl;

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

	cout << endl;
	
	testUpper ();
	cout << endl;

	testLower();
	cout << endl;

	testReplace_all();
	cout << endl;

	testFormatName1();
	cout << endl;


	return 0;
}
