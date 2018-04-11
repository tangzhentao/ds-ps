/*
 * 演示ostringstream的使用
 */
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	ostringstream ost;
	int i = 9;
	string s = "hello world.";
	ost << i << ", " << s;
	cout << ost.str() << endl;
	return 0;
}
