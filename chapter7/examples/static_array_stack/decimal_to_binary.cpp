/*
 * 把十进制转换成二进制，使用栈来存储
 */
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	char userResponse;
	
	do
	{
		cout << " 输入一个十进制正整数: " << endl;
		unsigned num = 0;
		cin >> num;

		cout << num << "的二进制形式是：";
		Stack stack;
		while (0 != num)
		{
			unsigned remander = num % 2;
			stack.push(remander);
			num /= 2;
		}

		cout << stack << endl;

		cout << "继续？";
		cin >> userResponse;
	} while ('y' == userResponse);

	return 0;
}
