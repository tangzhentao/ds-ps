/*
 * 演示：
 * 1.数组的数组的声明
 * 2.多为数组的初始化
 */
#include <iostream>

using namespace std;

const int NUM_ROWS = 2;
const int NUM_COLUMNS = 3;

typedef int IntArray[NUM_ROWS][NUM_COLUMNS];

int main(int argc, char *argv[])
{
	// 声明一个三维数组a，并初始化
	IntArray a[2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	
	// 打印三维数组a
	cout << "a:" << endl;
	for (int d1 = 0; d1 < 2; d1++)
	{
		for (int d2 = 0; d2 < NUM_ROWS; d2 ++)
		{
			for (int d3 = 0; d3 < NUM_COLUMNS; d3++)
			{
				cout << "  " << a[d1][d2][d3]; 
			}
		}
	}
	cout << endl;
	cout << "hello" << endl;
	return 0;
}
