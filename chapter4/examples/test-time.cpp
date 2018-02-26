/*
 * 类Time的测试驱动程序
 */
#include <iostream>

using namespace std;
#include "Time.h"

int main()
{
	Time mealTime;
	// 测试set
	mealTime.set(5, 30, 'P');

	// 测试display
	cout << "We will be eating at ";
	mealTime.display(cout);
	cout << endl;

	cout << "\nNow trying to set time with illegal hours (13) " << endl;
	mealTime.set(13, 0, 'A');

	cout << "\nNow trying to set time with illegal minutes (60) " << endl;
	mealTime.set(5, 60, 'A');

	cout << "\nNow trying to set time with illegal am/pm ('X') " << endl;
	mealTime.set(5, 0, 'X');

	// 测试操作符重载<<
	cout << "<< " << mealTime << endl;

	return 0;
}
