/*
 * 
 */
#include <iostream>
#include "Test.h"

Test::Test(string age): myName("jobs"), myAge("33")
{
	cout << "test" << endl;
	myAge = age;
}

void Test::display(ostream &out) const
{
	out << "name: " << myName << ", " << "age: " << myAge << endl;
}

ostream & operator << (ostream &out, const Test &test)
{
	test.display(out);
	return out;
}
