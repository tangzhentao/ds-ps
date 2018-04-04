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
		
		for (int x = 1; ; x++)
		{
			int right = x * p1 * p2 + 1;
			for (int e1 = 2; ; )
		}
	}
	cout << "hello" << endl;
	return 0;
}
