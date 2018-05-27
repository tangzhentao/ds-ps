/*
 * 链表的测试驱动程序
 */
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
	LinkedList list;
	Node n0(0);
	Node n1(1);
	Node n2(2);
	Node n3(3);

	list.insert(n0, 0);
	cout << "list: " << list << endl;
	list.insert(n1, 0);
	cout << "list: " << list << endl;
	list.insert(n2, 1);
	cout << "list: " << list << endl;
	list.insert(n3, 3);
	cout << "list: " << list << endl;


	cout << "测试删除" << endl;
	list.remove (3);
	cout << "list: " << list << endl;
	list.remove (0);
	cout << "list: " << list << endl;
	list.remove (1);
	cout << "list: " << list << endl;
	list.remove (0);
	cout << "list: " << list << endl;
	return 0;
}
