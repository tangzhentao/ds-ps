#include <iostream>

using namespace std;

void noValueInArray ()
{
	int array[2];
	int i = array[1];
	cout << i << endl;
}

int main (int argc, char *argv[])
{
	int iarray[10];
	cout << "iarray size: " << sizeof (iarray) << endl;
	cout << "iarray 0 size: " << sizeof (iarray[0]) << endl;
	cout << "hello" << endl;
	int i = iarray[3];
	cout << i << endl;

	noValueInArray();

	return 0;
}
