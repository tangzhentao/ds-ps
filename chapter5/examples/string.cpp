/*
 * 演示C++字符串string的操作
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ca[] = "sdfsaf";
	string s("abcdefgh");
	string s1(ca, 3);
	string s2(s);
	string s3(s,2);
	string s4(s, 2, 5);
	string s5(10, '*');

	cout << s << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << "hello" << endl;
	return 0;
}
