/*
 * 求最大公约数和互质函数的驱动程序
 */
#include <iostream>
#include "gcd.h"

using namespace std;

int main()
{
	int a, b;
	while(1)
	{
		cout << "calculate greatest common divisor." << endl;
		cout << "Type two integers(0, quit): ";
		cin >> a >> b;
		if (0 == a)
			break;

		int result = gcd(a, b);
		cout << a << " and " << b << " gcd is " << result << endl;
	}
	cout << "end gcd" << endl;

	while(1)
	{
		cout << "coprime" << endl;
		cout << "Type two integers(0, quit): ";
		cin >> a >> b;
		if (0 == a)
			break;

		bool result = coprime(a, b);
		cout << "Is " << a << " and " << b << " coprime? " << boolalpha << result << endl;

	}
	return 0;
}
