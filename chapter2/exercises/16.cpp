#include <iostream>

using namespace std;

int main()
{
	int *foo, *goo;

	foo = new int;
	*foo = 1;
	cout << (*foo) << endl;
	goo = new int;
	*goo = 3;
	cout << (*foo) << (*goo) << endl;
	*foo = *goo + 3;
	cout << (*foo) << (*goo) << endl;

	return 0;
}
