/*
 * 带入数值验证如下公式：
 * 已知公钥(e1, n), 私钥(e2, n)，A为明文，B为密文，则：
 * B = A^e1 mod n
 * A = B^e2 mod n
 * 
 */
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
	long long e1;
	long long e2;
	long long n;
	long long a, b;

	while (1)
	{
		cout << "输入公钥e1、私钥e2、还有n" << endl;
		cin >> e1 >> e2 >> n;
		cout << "输入明文数字A ";
		cin >> a;
		cout << endl;
		b = pow(a, e1);
		b = b % n;
		cout << "B = " << b << endl;

		a = pow(b, e2);
		a = a % n;
		cout << "A = " << a << endl;
	}

	return 0;
}
