/*
 * 演示new操作符申请内存失败,使用nothrow版的new
 * 并检查new是否返回了空地址
 */
#include <iostream>
#include <new>

using namespace std;

int main(int argc, char *argv[])
{
	const int NUM_ARRAYS = 100000;
	cout << "How large should the arrays of doubles be ? ";
	int capacity;
	cin >> capacity;

	double *arrayPtr[NUM_ARRAYS];
	for (int i = 0; i < NUM_ARRAYS; i++)
	{
		arrayPtr[i] = new(nothrow) double[capacity];
		if (0 == arrayPtr[i]) 
		{
			cout << "Allocation failed for i = " << i << endl;
			exit (1);
		}
		cout << "Allocated " << capacity 
			<< " doubles for i = " << i << endl;
	}
	cout << "All " << NUM_ARRAYS << " arrays of "
		<< capacity << " doubles were allocted successfully." << endl;

	return 0;
}
