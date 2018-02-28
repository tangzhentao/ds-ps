/*
 * 演示istream的相关操作
 * 1. cin的状态：good、bad、fail和eof(end of file)
 * 2. cin的成员函数
 */
#include <iostream>

using namespace std;

int main()
{
	// 测试cin的good,fail和eof的情况，目前bad的情况还不知道如何实现
	int number;
	for ( ; ; )
	{
		cout << "Enter an integer (Ctrl - D to stop): ";
		cin >> number;
		if(cin.good())
		{
			cout << "cin is good" << endl;
		} else if(cin.fail())
		{
			// 当cin的状态为fail的时候，就不能再提取这个istream对象
			// 中剩余的数据，除非它的good、bad、fail状态被重重为初始值
			cout << "cin is fail" << endl;

			// 是不是遇到了结束符导致了失败
			if(cin.eof())
			{// 是的
				cout << "cin eof" << endl;

				// 遇到结束符后这个istream对象就废了，再也不能从中提取数据了
				break;
			}
			// 状态重置为初始值
			cin.clear();
			cin.ignore();
			cout << "ignore a char" << endl;
		} else if(cin.bad())
		{
			cout << "cin is bad" << endl;
		}
	}

	// 检查cin遇到结束符后，还能不能使用。结果是不能使用
	int i;
	cin >> i;
	cout << "i = " << i << endl;
	return 0;
}
