/*
 *通过演示数组越界问题来来说明
 *数组的下标运算是简单的基地址+偏移量来实现的
 *需要注意的是Mac OS是按从高地址到低地址的方式来给你变量分配地址的
 */
#include <iostream>
#include <cassert>

using namespace std;

const int CAPACITY = 4;

typedef int IntArray[CAPACITY];

void read(IntArray theArray, int capacity, int numValues);
void display(IntArray theArray, int numValues);

int main(int argc, char *argv[])
{
	// 定义三个元素类型为int容量为4数组
	IntArray a, b, c;

	cout << "Enter " << CAPACITY << "integer values for:" << endl;
	cout << "Array a:";
	read (a, CAPACITY, CAPACITY);

	cout << "Array b:";
	read (b, CAPACITY, CAPACITY);

	cout << "Array c:";
	read (c, CAPACITY, CAPACITY);
	cout << "\n----- Part I of the demonstration -----\n\n";
	cout << "the arrays are:"<< endl;
	cout << "a: ";
	display (a, CAPACITY);

	cout << "b: ";
	display (b, CAPACITY);

	cout << "c: ";
	display (c, CAPACITY);

	// 现在改变数组b中的元素，但是使用一些越界的索引
	int below = -3;
	int above = 6;
	b[below] = -999;
	b[above] = 999;

	cout << "\n----- Part II of the demonstration -----\n\n";
	cout << "the arrays after out-of-range error are:"<< endl;
	cout << "a: ";
	display (a, CAPACITY);

	cout << "b: ";
	display (b, CAPACITY);

	cout << "c: ";
	display (c, CAPACITY);

	return 0;
}

void read (IntArray theArray, int capacity, int numValues)
{
	/*
	 * 从键盘输入值到一个整数数组中
	 *
	 * 前置条件：0 <= numValues <= capacity, capacity是数组的容量
	 * 后置条件：从键盘输入numValues个整数并存储到theArray在的前numValues位置
	 */

	assert (numValues >= 0 && numValues <= capacity);

	for (int i = 0; i < numValues; i++)
	{
		cin >> theArray[i];
	}

}

/*
 * 显示一个整数数组中的值
 *
 * 前置条件：0 <= numValues <= 数组容量
 * 后置条件：theArray数组中的前numValues个值被输出到cout
 */
void display (IntArray theArray, int numValues)
{
	for (int i = 0; i < numValues; i++)
	{
		cout << theArray[i] << "<" << &(theArray[i]) << ">"<< "  ";
	}
	cout << endl;
}

