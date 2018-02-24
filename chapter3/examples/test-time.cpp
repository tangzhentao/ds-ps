/*
 * 测试Time的驱动程序
 */
#include <iostream>

using namespace std;

#include "Time.h"

int main(int argc, char *argv[])
{
	Time mealTime;
	Time goToWorkTime;
	set(mealTime, 5, 30, 'P');
	cout << "We will be eating at ";
	display(mealTime, cout);
	cout << endl;
	cout << "hello" << endl;
	
	set(goToWorkTime, 5, 30, 'P');
	cout << "You leave for work at ";
	display(goToWorkTime, cout);
	cout << endl;

	// 比较
	if(lessThan(mealTime, goToWorkTime))
	{
		cout << "If you hurry, you can eat first.\n";
	}
	else
	{
		cout << "Sorry, you can't eat with us.\n";
	}

	// 提前
	advance(goToWorkTime, 0, 30);
	
	// 比较
	if(lessThan(mealTime, goToWorkTime))
	{
		cout << "If you hurry, you can eat first.\n";
	}
	else
	{
		cout << "Sorry, you can't eat with us.\n";
	}

	return 0;
}
