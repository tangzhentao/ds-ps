/*
 * 链表的节点
 */
#include <iostream>

#ifndef NODE
#define NODE

typedef int DataType;

using namespace std;

class Node
{
public:
	DataType data;
	Node *next;

	Node(DataType theData = 0)
	{
		//cout << "Node构造函数：" << this << endl;
		next = NULL;
		data = theData;
	}

	~Node()
	{
		//cout << "delete node<" << this << ">: " << data << endl;
	}
};

#endif
