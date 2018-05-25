/*
 * 多项式类的驱动程序
 */
#include <iostream>
#include "Polynomial.h" 

using namespace std;

int main()
{
	int maxDegree;
	cout << "请输入多项式的最大阶：";
	cin >> maxDegree;
	Polynomial polynomial(maxDegree);
	cout << "请先输入" << maxDegree + 1 << "个系数" << endl;
	cin >> polynomial;

	cout << "polynomial: " << endl;
	cout << polynomial << endl;

	/*
	cout << "测试赋值操作" << endl;
	Polynomial p1(1);
	p1 = polynomial;
	cout << "p1: " << p1 << endl;
	*/

	cout << "请输入多项式的最大阶：";
	cin >> maxDegree;
	Polynomial polynomial1(maxDegree);
	cout << "请先输入" << maxDegree + 1 << "个系数" << endl;
	cin >> polynomial1;

	cout << "polynomial1: " << endl;
	cout << polynomial1 << endl;

	cout << "测试加法" << endl;
	Polynomial sum = polynomial + polynomial1;
	cout << "sum: " << &sum << endl;
	cout << sum << endl;

	cout << "测试乘法：" << endl;
	Polynomial product = polynomial * polynomial1;
	cout << "乘积：" << product << endl;
	
	cout << "测试给定x的值，求多项式的值" << endl;
	cout << polynomial << endl;
	CoeficentType value = polynomial.evaluate(2);
	cout << "多项式的值为：" << value << endl;

	return 0;
}
