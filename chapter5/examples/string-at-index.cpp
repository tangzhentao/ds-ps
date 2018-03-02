/*
 * 演示string中的下标运算符[]和at成员函数
 * []：索引越界时不抛出异常
 * at：索引越界时抛出异常
 */
#include <iostream>

using namespace std;

int main()
{
	string s = "abcde";
	int i = 6;
	try
	{
		cout << s.at(i) << endl;
		//cout << s[i] << endl;
	}
	catch (exception rangeExc)
	{
		cout << "Error in s.at(i) for i = " << i << endl
			 << rangeExc.what() << endl;
	}
	cout << "Done checking" << endl;
	return 0;
}
