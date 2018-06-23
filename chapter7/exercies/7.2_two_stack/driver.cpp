/*
 * 驱动程序
 */
#include <iostream>
#include "TwoStack.h"

int main(int argc, char *argv[])
{
	char again;
	do
	{
		TwoStack ts;
		cout << "栈1是否为空" << boolalpha << ts.isEmpty(1) << endl;

		cout << "压入几个元素到栈1中：";
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			ts.push(i, 1);
		}
		ts.display(1);
		cout << "栈1是否为空" << boolalpha << ts.isEmpty(1) << endl;
		cout << "ts是否已满" << boolalpha << ts.isFull() << endl;
		
		cout << "压入几个元素到栈2中：";
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			ts.push(i, 2);
		}
		ts.display(2);
		cout << "栈2是否为空" << boolalpha << ts.isEmpty(2) << endl;
		cout << "ts是否已满" << boolalpha << ts.isFull() << endl;

		cout << "从栈1中弹出几个元素：";
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "栈顶元素：" << ts.top(1) << endl;
			ts.pop(1);
		}
		ts.display(1);
		cout << "栈1是否为空" << boolalpha << ts.isEmpty(1) << endl;
		cout << "ts是否已满" << boolalpha << ts.isFull() << endl;

		cout << "从栈2中弹出几个元素：";
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "栈顶元素：" << ts.top(2) << endl;
			ts.pop(2);
		}
		ts.display(2);
		cout << "栈2是否为空" << boolalpha << ts.isEmpty(2) << endl;
		cout << "ts是否已满" << boolalpha << ts.isFull() << endl;

		cout << "再测试一遍？";
		cin >> again;

	} while ('y' == again);

	return 0;
}
