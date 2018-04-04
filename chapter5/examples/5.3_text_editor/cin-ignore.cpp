/*
 * 演示cin.ignore(1, '\n')会不会丢弃'\n'
 * 通过使用其他终止符如a，来推断会不会丢弃'\n'
 *
 * 结论：
 *	会丢弃终止符'\n'
 */
#include <iostream>

using namespace std;

int main()
{
	string s1;
	cin.ignore(1, 'a');
	cin >> s1;
	cout << "s1: " << s1 << endl; 
	return 0;
}
