/*
 * 测试返回局部变量时，是不是被释放了，然后返回的是副本
 *
 * 结论：
 * 返回的副本，参数值传递的也是副本
 * 局部变量有没有被释放这段程序测试不出来，得实现析构函数才知道
 */
#include <iostream>

using namespace std;

class person
{
	string name;
};

int addOne(int a)
{
	cout << "addOne begin." << endl;
	cout << "参数a地址：" << &a << endl;
	int b = a + 1;
	cout << "参数b地址：" << &b << endl;

	cout << "addOne will end." << endl;
	return b;
}

int main()
{
	int i = 2;
	cout << "参数i地址：" << &i << endl;
	int j = addOne(i);
	cout << "参数j地址：" << &j << endl;
	cout << "hello" << endl;
	return 0;
}
