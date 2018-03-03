/*
 * 演示cin和提出操作符>>是怎样从键盘提取字符流的
 */
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "hello" << endl;
	int age;
	int num;
	int i = 6;
	char c;
	cin >> age >> num >> i >> c;
	cout << "age: " << age << " num: " << num << " i: " << i 
		<<" c: " << c << endl;
	return 0;
}
