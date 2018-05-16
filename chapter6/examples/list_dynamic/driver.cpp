/*
 * List类的驱动程序
 */
#include <iostream>
#include "list_array.h"

using namespace std;

List addOne(List list)
{
	cout << "addOne begin...." << endl;
	
	list.insert(100, 0);

	cout << "addOne will end." << endl;

	return list;
}

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

	cout << "开始测试构造函数、赋值构造函数、赋值运算符" << endl;

	List list1(4);
	cout << "list1: " << list1 << endl;
	list1.insert(1, 0);
	list1.insert(2, 1);
	list1.insert(3, 2);
	cout << "list: " << list << endl;
	cout << "list1: " << list1 << endl;

	List list2;
	cout << "list2: " << list2 << endl;

	// 测试赋值运算符
	list2 = list;

	cout << "list2: " << list2 << endl;

	// 测试初始化时的复制构造函数
	List list3 = list1;
	cout << "list3: " << list3 << endl;

	// 测试值传递和return局部变量
	List list4 = addOne(list3);
	cout << "list4: " << list4 << endl;

	return 0;
}
