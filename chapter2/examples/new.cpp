#include <iostream>

using namespace std;

int main()
{
	int *iptr = new int;
	*iptr = 12;
	cout << "*iptr = " << *iptr << endl;
	cout << "hello" << endl;
	return 0;
}
