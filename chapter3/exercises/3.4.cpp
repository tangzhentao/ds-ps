/*
 * 联系3.4相关代码
 */
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	// 1.动态获取数组的容量
	int n;
	cout << "Please input the capacity of double array: ";
	cin >> n;
	double *doublePtr = new double [n];
	// 2.给数组动态赋值
	cout << "Please assign double array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> doublePtr[i];
	}

	// 3.计算并显示数组的平均值
	double average = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += doublePtr[i];
	}
	average = sum / n;
	cout << "The average of double array is: " << average << endl;
	
	// 4.释放动态分配的地址doublePtr
	delete[] doublePtr;
	cout << "hello" << endl;
	return 0;
}
