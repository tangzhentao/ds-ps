/*
 * 驱动程序
 */
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	char userResponse;
	do
	{
		Stack stack;

		// 测试栈判空
		cout << "栈是否为空？" << boolalpha << stack.isEmpty() << endl;
		// 测试 压栈
		int count = 0;
		cout << "输入要压入多少个元素：";
		cin >> count;

		for (int i = 0; i < count; i++)
			stack.push(i);

		// 测试栈判空
		cout << "栈是否为空？" << boolalpha << stack.isEmpty() << endl;
		// 测试访问栈顶元素
		cout << "栈顶元素是：" << stack.getTop() << endl;
		// 测试输出操作符
		cout << "栈内容：" << stack << endl;
		// 测试弹栈
		cout << "输入弹出元素的个数：" ;
		cin >> count;

		for (int i = 0; i < count; i++)
			stack.pop();

		// 测试栈判空
		cout << "栈是否为空？" << boolalpha << stack.isEmpty() << endl;
		// 测试输出操作符
		cout << "栈内容：" << stack << endl;

		cout << "还要进行下一轮测试吗？";
		cin >> userResponse;
	} while ('y' == userResponse);

	return 0;
}
