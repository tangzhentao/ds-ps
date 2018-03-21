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

string formatName1(const string name, const string mName, const string lName)
{
	if (0 == name.length() || 0 == mName.length() || 0 == lName.length())
	{
		cout << "有一个或多个参数为空" << endl;
		return "";
	}

	string newName = lName + ',' + name + ' ' + mName[0];
	return newName;
}

string formatName2(const string name)
{
	if (0 == name.length())
	{
		cout << "姓名为空" << endl;
		return "";
	}

	unsigned oldPostion = 0;
	unsigned newPosition = name.find(' ', oldPostion);
	cout << "newPosition: " << newPosition <<" oldPostion: " << oldPostion << endl;
	unsigned nameLen = newPosition - oldPostion;
	string fName = name.substr(oldPostion, nameLen);
	cout << "name: " << '['  << fName <<']'  << endl;

	// LeBron Raymone James
	oldPostion = newPosition + 1;
	newPosition = name.find(' ', oldPostion);
	cout << "newPosition: " << newPosition <<" oldPostion: " << oldPostion << endl;
	nameLen = newPosition - oldPostion;
	string mName = name.substr(oldPostion, nameLen);
	cout << "mName: " << '[' << mName << ']' << endl;

	oldPostion = newPosition + 1;
	newPosition = name.find(' ', oldPostion);
	cout << "newPosition: " << newPosition <<" oldPostion: " << oldPostion << endl;
	nameLen = newPosition - oldPostion;
	string lName = name.substr(oldPostion, nameLen);
	cout << "lName: " << '[' << lName << ']' << endl;

	string newName = lName + ',' + fName + ' ' + mName[0];
	cout << "newName: " << newName << endl;

	return newName;

}

int stringToI(const string & iString)
{
	string iStr = iString;
	// 空字符串直接返回0
	if (iStr.empty())
	{
		return 0;
	}

	// 如果有正负号，先删除正负号再判断是否为数字串
	// 没有符号，则直接判断是否为数字串
	char sign = iStr.at(0);
	if ('+' == sign || '-' == sign)
	{
		iStr.erase(0, 1);
	}

	bool isDigitStr = true;
	unsigned len = iStr.length();
	for (int i = 0; i < len; i++)
	{
		if (false == isdigit(iStr[i]))
		{
			isDigitStr = false;
			break;
		}
	}

	if(isDigitStr)
	{// 是数字串
		// 转成数字
		int iValue = atoi(iStr.c_str());

		// 判断符号
		if ('-' == sign)
		{
			return -iValue;
		}
		return iValue;
	} else 
	{// 不是数字串
		// 提示、返回0
	
		cout << iString << " is not integer." << endl;
		return 0;
	}
}

double stringToF(const string & fString)
{
	string fStr = fString;
	// 空字符串直接返回0
	if (fStr.empty())
	{
		return 0;
	}

	// 如果有正负号，先删除正负号再判断是否为数字串
	// 没有符号，则直接判断是否为数字串
	char sign = fStr.at(0);
	if ('+' == sign || '-' == sign)
	{
		fStr.erase(0, 1);
	}

	bool isDigitStr = true;
	int dotCnt = 0;
	unsigned len = fStr.length();
	for (int i = 0; i < len; i++)
	{
		char c = fStr[i];
		if (false == isdigit(c))
		{
			if ('.' == c)
			{
				++dotCnt;
				if (dotCnt > 1)
				{
					isDigitStr = false;
					break;
				}
			} else 
			{
				isDigitStr = false;
				break;
			}
		}
	}

	if(isDigitStr)
	{// 是数字串
		// 转成数字
		double fValue = atof(fStr.c_str());

		// 判断符号
		if ('-' == sign)
		{
			return -fValue;
		}
		return fValue;
	} else 
	{// 不是数字串
		// 提示、返回0
	
		cout << fString << " is not decimal." << endl;
		return 0;
	}
}

bool isPlalindrome(const string & str)
{
	unsigned len = str.length();
	if (len < 2)
	{
		return false;
	}

	bool isPla = true;
	unsigned head = 0;
	unsigned tail = len - 1;
	while (head < tail)
	{
		char h = str[head];
		char t = str[tail];
		cout << head << h << " <----> " << t << tail << endl;
		if (h == t)
		{
			++head;
			--tail;
		}
		else 
		{
			isPla = false;
			break;
		}
	}

	return isPla;
}

string dictionaryOrder(const string &str)
{
	unsigned len = str.length();
	if (len < 2)
	{
		return str;
	}

	cout << "length: " << len << endl;
	char *tmp = new char[len + 0];
	//tmp[len] = 0;
	for (int i = 0; i < len; i++)
	{
		tmp[i] = str[i];
		cout << tmp[i] << endl;
	}

	cout << "sort: " << tmp << endl;
	for (int i = 0; i < len; i++)
	{
		int small = i;
		for (int j = i+1; j < len; j++)
		{
			if (tmp[j] < tmp[small])
			{
				small = j;
			}
		}
		cout << i << ' ' << tmp[small] << endl;
		char mid = tmp[i];
		tmp[i] = tmp[small];
		tmp[small] = mid;
	}
	string newstr = string(tmp);

	cout << "new str: " << newstr << endl;
	return newstr;
}

bool isAnagram(const string &str1, const string &str2)
{
	bool is = false;
	unsigned len1 = str1.length();	
	unsigned len2 = str2.length();	
	if (len1 == len2)
	{
		string orderStr1 = dictionaryOrder(str1);
		string orderStr2 = dictionaryOrder(str2);
		is = (orderStr1 == orderStr2);
	}

	return is;
}
