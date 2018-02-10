#include <iostream>

using namespace std;

void swap (int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void cswap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 1;
	int b = 2;

	// use swap 
	cout << "&a = " << &a << ", &b = " << &b << endl;
	cout << "a = " << a <<", b = " << b << endl;
	swap (a, b);
	cout << "&a = " << &a << ", &b = " << &b << endl;
	cout << "a = " << a <<", b = " << b << endl;
	cout << "hello" << endl;

	// use cswap
	cswap (&a, &b);
	cout << "&a = " << &a << ", &b = " << &b << endl;
	cout << "a = " << a <<", b = " << b << endl;
	return 0;
}
