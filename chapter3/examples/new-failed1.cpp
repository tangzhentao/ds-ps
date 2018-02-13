/*
 * 演示new操作符申请内存失败
 */
#include <iostream>

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
		arrayPtr[i] = new double[capacity];
		cout << "Allocated " << capacity 
			<< " doubles for i = " << i << endl;
	}
	cout << "All " << NUM_ARRAYS << " arrays of "
		<< capacity << " doubles were allocted successfully." << endl;

	return 0;
}
