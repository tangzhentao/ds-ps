/*
 * RSA算法 公钥密钥生成器
 *
 * 给定两个素数，生成公钥和私钥；
 *
 * 生成规则：
 * 公钥和私钥都是整数对，设为(e1, n)和(e2, n)
 * 其中n为两个素数的乘积，设为p和q
 * 要求e1与(p-1)、(q-1)互质，即，最大公约数是1
 * e1和e2是一对相关的值
 * 要求(e1 * e2) mod ((p-1) * (q-1)) = 1
 *
 * RSA加密算法和解密算法完全相同，设A为明文，B为密文，则有：
 * A = B^e1 mod n
 * B = A^e2 mod n
 */
#include <iostream>
#include "gcd.h"


using namespace std;

int main(int argc, char *argv[])
{
	while (1)
	{
		int p;
		int q;
		cout << "输入两个素数: ";
		cin >> p >> q;

		int n = p * q;
		int p1 = p - 1;
		int q1 = q - 1;

		// e1 * e2 = x * p1 * p2 + 1;
		
		int e1, e2;
		e1 = e2 = 0;
		bool found = false;
		for (int x = 1; ; x++)
		{
			int right = x * p1 * q1 + 1;
			for (e1 = 3; e1 < right / 2 ; e1++)
			{
				cout << "log: x = " << x << " e1 = " << e1 << endl;
				// e1 不能等于p1、q1
				if (e1 == p1 || e1 == q1)
				{
					cout << "e1(" << e1 << ") is equal to p1(" << p1 << ")" << " or q1(" << q1 << ")" << endl;
					continue;
				} else if (false == coprime(e1, p1))
				{// e1 要和p1、q1互质
					cout << "e1(" << e1 << ") and p1(" << p1 << ") are not coprime" << endl;
					continue;
				} else if (false == coprime(e1, q1))
				{
					cout << "e1(" << e1 << ") and q1(" << q1 << ") are not coprime" << endl;
					continue;
				}

				// 判断right能不能被e1整除
				// 如果能整除商就是e2
				e2 = right / e1;
				if (right == e1 * e2 && e1 != e2)
				{
					found = true;
					break;
				}
			}

			if (found)
			{
				cout << "public key: (" << e1 << ", " << n << ")" << endl; 
				cout << "secret key: (" << e2 << ", " << n << ")" << endl; 
				break;
			}
		}
	}
	cout << "hello" << endl;
	return 0;
}
