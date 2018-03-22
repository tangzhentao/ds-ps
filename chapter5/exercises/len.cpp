/*
 * 检查未定义string的长度
 */
#include <iostream>

using namespace std;

int main()
{
	string s;
	cout << "s length: " << s.length() << endl;
	cout << "is empty ? " << boolalpha << s.empty() << endl;  
	return 0;
}
