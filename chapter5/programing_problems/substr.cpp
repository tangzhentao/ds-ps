/*
 * 测试substr (int pos, int n)，当string长度小于n的情况
 */
#include <iostream>

using namespace std;

int main()
{
	cout << "hello" << endl;
	string str = "he";
	string substr = str.substr(1, 10);
	cout << substr << endl;
	return 0;
}
