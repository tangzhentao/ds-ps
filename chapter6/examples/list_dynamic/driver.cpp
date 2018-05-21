/*
 * List类的驱动程序
 */
#include <iostream>
#include <unistd.h>
#include "list_array.h"

using namespace std;

List addOne(List list)
{
	cout << "addOne begin...." << endl;
	
	list.insert(100, 0);

	cout << "addOne will end." << endl;

	return list;
}

List & removeOne(List list)
{
	cout << "removeOne begin...." << endl;
	
	list.erase(0);

	cout << "removeOne will end." << endl;

	return list;
} 

List & deleteOne(List & list)
{
	cout << "deleteOne begin...." << endl;
	
	list.erase(0);

	cout << "deleteOne  will end." << endl;

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

	// 测试返回对象时是不是走的赋值运算符
	List list5;
	cout << "list5: " << list5 << endl;
	list5 = addOne(list1);
	cout << "list5: " << list5 << endl;

	// 测试把局部变量使用引用传递的方式返回出去
	list5 = removeOne(list4);
	cout << "list5: " << list5 << endl;

	// 测试把局部变量使用引用传递的方式返回出去
	cout << "******" << endl;
	List list6 = removeOne(list4);
	cout << "list6: " << list5 << endl;

	// 测试引用传参
	List list7 = deleteOne(list4);
	cout << "list7: " << list7 << endl;
	
	cout << "测试返回类型是引用的函数不会返回变量的副本。即，返回变量时不会调用复制构造函数" << endl;

	removeOne(list4);
	cout << "测试返回类型是引用的函数，返回局部变量时会不会产生野指针，会不造成crash" << endl;
	List *plist8 = &(removeOne(list4));
	cout << "list8: " << *plist8 << endl;
	
	cout << "使用一个对象初始化另一个对象" << endl;
	List list9(list7);
	cout << "list9: " << list9 << endl;

	return 0;
}
