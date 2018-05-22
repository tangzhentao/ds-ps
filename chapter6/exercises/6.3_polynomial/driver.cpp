/*
 * 多项式类的驱动程序
 */
#include <iostream>
#include "Polynomial.h" 

using namespace std;

int main()
{
	Polynomial polynomial(4);
	cout << "请先输入4个阶，再输入4个系数" << endl;
	cin >> polynomial;

	cout << "polynomial: " << endl;
	cout << polynomial << endl;

	return 0;
}
