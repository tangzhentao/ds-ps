/*
 * 链表
 */
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	cout << "LinkedList构造函数：" << this << endl;
	first = NULL;
	size = 0;
}

LinkedList::~LinkedList()
{
	cout << "析构函数：" << this << endl;
	Node *nodePtr = first;
	while (nodePtr != NULL)
	{
		Node *tmpPtr = nodePtr;
		nodePtr = nodePtr -> next;

		// 释放
		delete tmpPtr;
	}
}

bool LinkedList::empty() const
{
	return (NULL == first);
}

void LinkedList::insert(const Node &newNode, int index)
{
	// 检查index是否合法
	if (index < 0 || index > size)
	{
		cerr << "index 不合法："  << index << endl;
		return;
	}

	Node *nodePtr = new(nothrow) Node(newNode.data);
	assert (NULL != nodePtr);
	cout << "插入node<" << nodePtr << ">: " << newNode.data << "在：" << index<< endl;

	/*
	 * 为了把节点插入到index处，需要获取index - 1处的节点
	 * 1. 如果获取的节点为NULL，则表明要插入的位置为头部
	 * 2. 节点不为NULL，表明插入的位置为非头部
	 */
	if (0 != index)
	{
		// 插入到非头部的位置
		// 获取前驱
		Node *preNodePtr = nodeAtIndex(index - 1);

		nodePtr -> next = preNodePtr -> next;
		preNodePtr -> next = nodePtr;
	} else 
	{
		// 插入到头部
		if (NULL == first)
		{
			// 如果头节点为NULL
			first = nodePtr;
		} else 
		{
			// 头节点非空
			nodePtr -> next = first;
			first = nodePtr;
		}
	}

	++size;
}

void LinkedList::remove(Node *node)
{
	if (node == first)
	{
		// 要删除的是头节点
		first = first -> next;
		delete node;

		// size减1
		--size;
	} else 
	{
		// 要删除的非头节点
		// 找到node的前驱
		Node *preNodePtr = first;
		while (preNodePtr -> next != NULL && preNodePtr -> next != node)
		{
			preNodePtr = preNodePtr -> next;
		}

		if (NULL == preNodePtr)
		{
			// 未找到node的前驱，则表明node不是链表的一个节点
			cerr << "非法操作, node<" << node << ">: " << node -> data << "不是链表的一个节点。" << endl; 
		} else 
		{
			// 找到了node的前驱
			preNodePtr -> next = node -> next;
			delete node;

			--size;
		}
	}
}

void LinkedList::remove(int index)
{
	// 检查index是否合法
	if (index < 0 || index > size)
	{
		cerr << "index 不合法："  << index << endl;
		return;
	}

	if (0 == index)
	{
		// 删除头节点
		Node *tmpNodePtr = first;
		first = first -> next;
		delete tmpNodePtr;
		--size;
	} else 
	{
		// 删除的是非头节点
		Node *preNodePtr = nodeAtIndex(index - 1);
		Node *nodePtr = nodeAtIndex(index);

		preNodePtr -> next = nodePtr -> next;

		delete nodePtr;

		--size;
	}
}

void LinkedList::display(ostream &out) const
{
	out << "size: " << size << endl;
	Node *node = first;
	while(NULL != node)
	{
		out << node -> data << ' ';
		node = node -> next;
	}
}

ostream & operator << (ostream &out, const LinkedList &list)
{
	list.display(out);
	return out;
}

Node * LinkedList::nodeAtIndex(int index)
{
	// 检查index是否合法
	if (index < 0 || index > size)
	{
		cerr << "index 不合法："  << index << endl;
		return NULL;
	}

	int i = 0;
	Node *pNode = first;
	for (int i = 1; i <= index; i++)
	{
		pNode = pNode -> next;
		if (NULL == pNode)
		{
			break;
		}
	}

	return pNode;
}
