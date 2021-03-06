/*
 * 链表的测试驱动程序
 */
#include <iostream>
#include "LinkedList.h"

using namespace std;


void testPreNodeForData(LinkedList &list)
{
	cout << endl;
	cout << "测试根据data找前驱：" << endl;
	cout << list << endl;

	DataType data;
	while (1)
	{
		cout << "输入data：" ;
		cin >> data;
		if (-1 == data)
		{
			cout << "测试结束" << endl;
			break;
		}

		Node *node = list.preNodeForData(data);
		if (node)
		{
			cout << "前驱是：" << node << ": " << node -> data << endl;
		} else 
		{
			cout << "没找到，换一个data试试" << endl;
		}
	}

	return;
}

void testRmoveNodeAt()
{
	cout << endl;
	cout << "开始测试删除指定位置的节点" << endl;
	LinkedList list;
	Node n0(0);
	Node n1(1);
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	Node n6(6);

	list.insert(n0, 0);
	list.insert(n1, 1);
	list.insert(n2, 2);
	list.insert(n3, 3);
	list.insert(n4, 4);
	list.insert(n5, 5);
	list.insert(n6, 6);

	list.removeNodeAt(8);
	cout << list << endl;
	list.removeNodeAt(0);
	cout << list << endl;
	list.removeNodeAt(1);
	cout << list << endl;
	list.removeNodeAt(2);
	cout << list << endl;
	list.removeNodeAt(3);
	cout << list << endl;
	list.removeNodeAt(4);
	cout << list << endl;

	cout << "测试结束" << endl;
	cout << endl;
}

LinkedList aLinkedList(DataType start, int size)
{
	LinkedList list;
	for(int i = 0; i < size; i++)
	{
		Node n(start + i);
		list.insert(n, i);
	}
	return list;
}

LinkedList aLinkedList()
{
	LinkedList list = aLinkedList(0, 6);

	return list;
}

void testCopyLinkedList()
{
	cout << endl;
	cout << "测试复制构造函数：" << endl;
	LinkedList a = aLinkedList();
	cout << "a: " << a << endl;
	LinkedList b = a;
	cout << "b: " << b << endl;
	cout << "测试结束" << endl;
	cout << endl;
}

void testInsertNext()
{
	cout << endl;
	cout << "测试把节点插入到指定位置之后：" << endl;
	LinkedList list;
	Node n0(0);
	Node n1(1);
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	Node n6(6);

	list.insert(n0, 0);
	cout << list << endl;
	list.insertNext(n1, 0);
	cout << list << endl;
	list.insertNext(n2, 1);
	cout << list << endl;
	list.insertNext(n3, 1);
	cout << list << endl;
	list.insertNext(n4, 2);
	cout << list << endl;
	list.insertNext(n5, 0);
	cout << list << endl;
	list.insertNext(n6, 5);
	cout << list << endl;

	cout << "测试结束" << endl;
}

void testShuffleMerge()
{
	cout << endl;
	cout << "测试合并" << endl;

	LinkedList a = aLinkedList();

	LinkedList b;
	Node node0(10);
	Node node1(11);
	Node node2(12);
	Node node3(13);
	Node node4(14);

	b.insert(node0, 0);
	b.insert(node1, 1);
	b.insert(node2, 2);
	b.insert(node3, 3);
	b.insert(node4, 4);

	LinkedList m1 = a.shuffleMerge(b);
	cout << "m1: " << m1 << endl;
	LinkedList m2 = b.shuffleMerge(a);
	cout << "m2: " << m2 << endl;

	cout << "测试合并结束" << endl;
	cout << endl;
}

void testShuffleMergeNoCopy()
{
	cout << endl;
	cout << "开始测试不复制的合并" << endl;
	LinkedList a1 = aLinkedList(0, 6);
	LinkedList b1 = aLinkedList(7, 4);
	LinkedList m1 = a1.shuffleMergeNoCopy(b1);
	cout << "a1: " << a1 << endl;
	cout << "m1: " << a1 << endl;
	
	cout << "结束测试不复制的合并" << endl;
}

void testAscendingMerge()
{
	cout << endl;
	cout << "开始测试升序合并" << endl;
	LinkedList l1 = aLinkedList(0, 4);
	LinkedList l2 = aLinkedList(2, 6);
	LinkedList l3 = aLinkedList(3, 6);
	LinkedList l4 = aLinkedList(1, 4);

	LinkedList m1 = l1.ascendingMerge(l2);
	cout << "m1: " << m1 << endl;
	LinkedList m2 = l2.ascendingMerge(l1);
	cout << "m2: " << m2 << endl;
	LinkedList m3 = l3.ascendingMerge(l4);
	cout << "m3: " << m3 << endl;
	LinkedList m4 = l4.ascendingMerge(l3);
	cout << "m4: " << m4 << endl;
	cout << "结束测试升序合并" << endl;
	cout << endl;
}

void testReverse()
{
	cout << endl;
	cout << "开始测试反转" << endl;
	LinkedList l1 = aLinkedList(1, 6);
	LinkedList l2 = aLinkedList(8, 2);
	LinkedList l3 = aLinkedList(11, 1);
	LinkedList l4;

	cout << "l1: " << l1 << endl;
	l1.reverse();
	cout << "l1: " << l1 << endl;

	cout << "l2: " << l2 << endl;
	l2.reverse();
	cout << "l2: " << l2 << endl;

	cout << "l3: " << l3 << endl;
	l3.reverse();
	cout << "l3: " << l3 << endl;

	cout << "l4: " << l4 << endl;
	l4.reverse();
	cout << "l4: " << l4 << endl;

	cout << "结束测试反转" << endl;
	cout << endl;


}

int main(int argc, char *argv[])
{
	LinkedList list;
	Node n0(0);
	Node n1(1);
	Node n2(2);
	Node n3(3);

	bool isAsc = list.isAscending();

	list.insert(n0, 0);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.insert(n1, 0);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.insert(n2, 1);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.insert(n3, 3);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;

	clock_t start = clock();
	cout << "测试平均值" << endl;
	double average = list.average();
	cout << "平均值：" << average << endl;
	clock_t end = clock();

	clock_t duration = end - start;
	cout << "计算平均值耗时：" << duration << "ms" << endl;

	cout << endl;
	cout << "测试删除" << endl;
	list.remove (3);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.remove (0);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.remove (1);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.remove (0);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;

	list.insert(n0, 0);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.insert(n1, 1);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.insert(n2, 2);
	isAsc = list.isAscending();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	list.insert(n3, 3);
	start = clock();
	isAsc = list.isAscending();
	end = clock();
	cout << (isAsc ? "是升序" : "不是升序") << endl;
	cout << "list: " << list << endl;
	cout << "判断是不是升序耗时：" << end - start << "ms" << endl;

	// testPreNodeForData(list);

	// testInsertNext();
	
	// testRmoveNodeAt();
	
	//testCopyLinkedList();
	
	//testShuffleMerge();
	//testShuffleMergeNoCopy ();
	
	//testAscendingMerge();

	testReverse();

	return 0;
}
