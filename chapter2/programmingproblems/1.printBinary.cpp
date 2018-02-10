#include <iostream>

using namespace std;
/*
 * 打印一int型变量的二进制形式。通过按位与和右移操作来实现
 */
void printBinary (int x)
{
	unsigned int mask = 0x80000000;
	int count = sizeof(x) * 8;
	cout << x << "'s binary: ";
	for (int i = 0; i < count; i++)
	{
		int b = x & mask;
		if (0 == b)
		{
			cout << 0;
		} else 
		{
			cout << 1;
		}
		mask = mask >> 1;
	}
	cout << endl;
}
