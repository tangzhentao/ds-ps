/*
 * 多项式类的驱动程序
 */
#include <iostream>
#include "Polynomial.h" 

using namespace std;

int main()
{
	Polynomial polynomial(4);
	cout << "请先输入5个系数" << endl;
	cin >> polynomial;

	cout << "polynomial: " << endl;
	cout << polynomial << endl;

	cout << "测试赋值操作" << endl;
	Polynomial p1(1);
	p1 = polynomial;
	cout << "p1: " << p1 << endl;

	Polynomial polynomial1(6);
	cout << "请先输入7个系数" << endl;
	cin >> polynomial1;

	cout << "polynomial1: " << endl;
	cout << polynomial1 << endl;

	cout << "测试加法" << endl;
	Polynomial sum = polynomial + polynomial1;
	cout << "sum: " << &sum << endl;
	cout << sum << endl;

	return 0;
}
