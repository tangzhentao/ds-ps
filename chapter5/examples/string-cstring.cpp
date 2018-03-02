/*
 * 演示string转换成cstring时两种方法的区别：s.data()和s.c_str():
 */
#include <iostream>

using namespace std;

void printCstring(const char *ca)
{
	for (int i = 0; i <= strlen(ca); i++)
	{
		char c = ca[i];
		int ci = c;
		cout <<"<" << c << "," << ci << ">" << endl;
	}
}

int main()
{
	string s = "hello";
	printCstring("hello");
	printCstring(s.c_str());
	printCstring(s.data());
	return 0;
}
