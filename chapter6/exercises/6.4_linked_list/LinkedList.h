/*
 * 链表类
 */
#include <iostream>
#include "Node.h"

#ifndef LINKED_LIST
#define LINKED_LIST

using namespace std;

class LinkedList
{
public:
	/* 构造函数 */
	LinkedList();

	/* 复制构造函数 */
	LinkedList(const LinkedList &original);

	/* 析造函数 */
	~LinkedList();
	
	/* 判空 */
	bool empty() const;
	/* 插入一个节点
	 * 1. 在指定的位置插入一个节点；
	 * 2. 在给定的节点前插入一个节点；
	 * 3. 在给定的节点后插入一个节点；
	 * 4. 在链表的第一个节点前插入一个节点；
	 * 5. 在链表的最后一个节点后插入一个节点；
	 */
	void insert(const Node &newNode, int index);

	/* 删除指定的节点
	 * 1. 删除指定位置的节点；
	 * 2. 删除指定节点后的节点；
	 * 3. 删除指定节点前的节点;
	 * 4. 删除第一个节点；
	 * 5. 删除最后一个节点；
	 */

	/* 删除指定位置的节点 */
	void remove(int index);

	/* 删除指定节点 */
	void remove(Node *node);

	/* 遍历链表 */
	void display(ostream &out) const;

	/* 获取指定位置的节点 */
	Node * nodeAtIndex(int index);

	/* 练习题函数 */

	// 平均值
	double average();

	// 是否是升序
	bool isAscending();

	/*
	 * 返回遇到的第一个data为给定指定值的节点的前驱，如果data所属的节点是first，则直接null
	 */
	Node *preNodeForData(DataType value);

	/*
	 * 把给定的节点插入到给定位置index之后
	 */
	void insertNext(Node newNode, int index);

	/* 
	 * 删除给定索引index的节点
	 */
	void removeNodeAt(int index);

	/* 
	 * 交错合并
	 */
	LinkedList shuffleMerge(const LinkedList &list) const;

private:
	Node *first;
	int size;
};

ostream & operator << (ostream &out, const LinkedList &list);

#endif
