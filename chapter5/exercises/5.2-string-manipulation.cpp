/*
 * 5.2-string-manipulation.h的实现文件
 */
#include "5.2-string-manipulation.h"

unsigned appearTimes(const string &substr, const string &str)
{
	unsigned appearTimes = 0;
	int postion = 0;
	while (string::npos != (postion = str.find(substr, postion)))
	{
		++appearTimes;
		cout << "The " << appearTimes << " time appear at: " << postion << endl;
		postion += substr.length();
	}

	return appearTimes;
}

string monthName(unsigned month)
{
	string name = "";
	switch (month)
	{
		case 1 :
			name = "January";
			break;

		case 2 :
			name = "February";
			break;

		case 3 :
			name = "March";
			break;

		case 4 :
			name = "April";
			break;

		case 5 :
			name = "May";
			break;

		case 6 :
			name = "June";
			break;

		case 7 :
			name = "July";
			break;

		case 8 :
			name = "August";
			break;

		case 9 :
			name = "September";
			break;

		case 10 :
			name = "October";
			break;

		case 11 :
			name = "November";
			break;

		case 12 :
			name = "December";
			break;

		default:
			break;
	}

	return name;
}

unsigned monthNum(const string &month)
{
	unsigned num = 0;
	if (month == "January")
	{
		num = 1;
	} 
	else if (month == "February")
	{
		num = 2;
	}
	else if (month == "March")
	{
		num = 3;
	}
	else if (month == "April")
	{
		num = 4;
	}
	else if (month == "May")
	{
		num = 5;
	}
	else if (month == "June")
	{
		num = 6;
	}
	else if (month == "July")
	{
		num = 7;
	}
	else if (month == "August")
	{
		num = 8;
	}
	else if (month == "September")
	{
		num = 9;
	}
	else if (month == "October")
	{
		num = 10;
	}
	else if (month == "November")
	{
		num = 11;
	}
	else if (month == "December")
	{
		num = 12;
	}

	return num;
}

string upper(const string str)
{
	string upperStr = "";
	unsigned len = str.length();
	for (int i = 0; i < len; i++)
	{
		char c = str[i];
		c = toupper(c);
		upperStr += c;
	}

	return upperStr;
}

string lower(const string str)
{
	string lowerStr = "";
	unsigned len = str.length();
	for (int i = 0; i < len; i++)
	{
		char c = str[i];
		c = tolower(c);
		lowerStr += c;
	}

	return lowerStr;
}

string replace_all(const string str, const string substr, const string newSubstr)
{
	string newStr = str;
	unsigned lenToReplace = substr.length(); // 要替换子串的长度
	int position = 0;
	unsigned count = 0;
	while (string::npos != (position = newStr.find(substr, position)))
	{
		++count;
		newStr.replace(position, lenToReplace, newSubstr);
		position += newSubstr.length(); 
		cout << count << ": " << newStr << endl;
	}

	return newStr;
}
