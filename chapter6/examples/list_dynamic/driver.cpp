/*
 * List类的驱动程序
 */
#include <iostream>
#include "list_array.h"

using namespace std;

int main()
{
	List list(3);

	// 测试插入
	list.insert(7, 0);
	cout << list << endl;
	list.insert(8, 1);
	cout << list << endl;
	list.insert(9, 2);
	cout << list << endl;
	list.insert(10, 3);
	cout << list << endl;
	list.insert(11, 4);
	cout << list << endl;

	// 测试删除
	list.erase(3);
	cout << list << endl;

	list.erase(3);
	cout << list << endl;
	list.erase(1);
	cout << list << endl;
	list.erase(0);
	cout << list << endl;
	return 0;
}
