/*
 * 演示atoi失败时会返回什么
 */
#include <iostream>

using namespace std;

int main()
{
	int i = atoi("a12");
	int j = atoi("456");
	cout << "j = " << j << endl;
	cout << "i = " << i << endl;
	cout << "hello" << endl;
	return 0;
}
