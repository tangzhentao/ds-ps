#include <iostream>

using namespace std;

int main ()
{
	bool b = false;
	cout << "b = " << b << endl;
	int i = 3;
	b = i;
	cout << "b = " << b << endl;

	i = b;
	cout << "i = " << i << endl;
	cout << "bool size: " << sizeof(bool) << endl;


	cout <<boolalpha << b << endl;
}
