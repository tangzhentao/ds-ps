#include <iostream>

using namespace std;

enum Wtype {who, what, where, when, why};

int main()
{
	cout << "int size: " << sizeof (int) << endl;
	cout << "float size: " << sizeof (float) << endl;
	cout << "double size: " << sizeof (double) << endl;
	cout << "short int size: " << sizeof (short int) << endl;
	cout << "enum size: " << sizeof (enum Wtype) << endl;

	int *iptr;
	float *fptr;
	double *dptr;
	short *sptr;
	enum Wtype *wptr;
	cout << "int prt size: " << sizeof (iptr) << endl;

	return 0;
}
