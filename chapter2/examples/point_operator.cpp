#include <iostream>

using namespace std;

int main () 
{
	int i = 1;
	int j = 2;
	float d = 1.3;
	float e = 2.5;

	int *iptr = &i;
	int *jptr = &j;
	float *dptr = &d;

	bool b = iptr > jptr;

	cout << boolalpha << b << endl;
	
	return 0;
}
