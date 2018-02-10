#include <iostream>

using namespace std;

typedef bool logic;

enum WeekDays {SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

int main ()
{
	logic l = 1;
	cout << boolalpha;
	cout << l << endl;
	logic l1 = 0;
	cout << l1 << endl;
	
	cout << noboolalpha;
	cout << l << endl;

	cout << "hello world." <<endl;
}
