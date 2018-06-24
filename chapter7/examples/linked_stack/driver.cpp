/*
 * 驱动程序
 */
#include <iostream>
#include "LStack.h"

int main(int argc, char *argv[])
{
	char again;

	do
	{
		LStack stack;
		cout << "新建的栈是否为空：" << boolalpha << stack.isEmpty() << endl;

		cout << "往栈中压入多少元素：";
		int num;
		cin >> num;
		
		for(int i = 0; i < num; i++)
			stack.push(i);

		cout << "栈<" << &stack << ">：" << stack << endl;

		cout << "\n测试复制、赋值：" << endl;
		LStack s1;
		LStack s2 = s1 = stack;
		cout << "栈<" << &s1<< ">：" << stack << endl;
		cout << "栈<" << &s2<< ">：" << stack << endl;
		cout << "结束测试复制、赋值\n" << endl;

		while(!stack.isEmpty())
		{
			cout << "栈顶元素：" << stack.top() << endl;
			stack.pop();
		}

		cout << "栈是否为空：" << boolalpha << stack.isEmpty() << endl;

		cout << "是否继续测试？(y/n)）";
		cin >> again;

	}while ('y' == again);

	return 0;
}
