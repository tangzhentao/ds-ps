/*
 * 演示使用new操作符实现动态数组；
 * 静态数组是指在程序编译期间就已经决定了容量的数组；
 * 动态数组是指在程序运行期间才决定容量的数组；
 */
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int numEntries = 0;
	
	// 从终端获取数组元素的个数
	cout << "How many entries ? ";
	cin >> numEntries;

	// 为数组分配空间
	double *array = new double[numEntries];

	cout << "the size of array: " << sizeof(array) << endl;

	// 为数组填值
	cout << "Enter you values" << endl;
	for (int i = 0; i < numEntries; i++)
	{
		cin >> array[i];
	}

	// 打印数组
	cout << "array: ";
	for (int i = 0; i < numEntries; i++)
	{
		cout << "  " << array[i];
	}
	cout << endl;

	return 0;
}
