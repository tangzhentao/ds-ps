#include <iostream>

using namespace std;

typedef char * CharPoint;

int main()
{
	CharPoint a, b;
	char c1 = 'a';
	char c2 = 'b';

	a = &c1;
	b = &c2;
	cout << "*a = " << *a << endl;
	cout << "*b = " << *b << endl;

	cout << "a size: " << sizeof (a) << ", b size: " << sizeof (b) << endl;
	cout << "hello" << endl;
	return 0;
}
