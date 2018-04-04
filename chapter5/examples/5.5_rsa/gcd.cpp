/*
 * 求给定的两个数是不是互质，即，两个数的最大公约数是不是1
 *
 * 求两个整数最大公约数的算法是欧几里德算法又叫辗转相除法:
 * 用两整数中较大的整数除以较小的整数，然后再用除数除以余数
 * 直到余数为0，此时最后一次的除数就是最大公约数
 *
 * gcd: greater common divisor
 */
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int dividend = a; // 被除数
	int divisor = b; // 除数
	if (b > a)
	{
		dividend = b;
		divisor = a;
	}

	int remainder; // 余数
	while((remainder = dividend % divisor))
	{
		dividend = divisor;
		divisor = remainder;
	}

	int gcd = divisor;

	return gcd;
}

bool coprime(int a, int b)
{
	int result = gcd(a, b);
	return (1== result);
}
