/*
 * 链式栈实现文件
 */
#include <iostream>
#include "LStack.h"

LStack::LStack(): myTop(NULL)
{
}

LStack::~LStack()
{
	Node *nodePtr= myTop;
	while(nodePtr != NULL)
	{
		Node *tmp = nodePtr;
		nodePtr = tmp -> next;
		delete tmp;
	}
}

LStack::LStack(const LStack &original)
{
	cout << "把 " << &original << " 复制为 " << this << endl;

	myTop = NULL;
	if (!original.isEmpty())
	{
		// 复制第一个节点
		myTop = new Node(original.top());

		// 复制剩下的节点
		Node *originalPtr = original.myTop -> next;
		Node *lastPtr = myTop;
		while(originalPtr != NULL)
		{
			// 创建一个新节点并把节点链接到栈上
			lastPtr -> next = new Node(originalPtr -> data);

			// 遍历下一个节点
			originalPtr = originalPtr -> next;
			lastPtr = lastPtr -> next;
		}
	}
}

const LStack & LStack::operator = (const LStack &right)
{
	cout << "把 " << &right<< " 赋值给 " << this << endl;

	// 如果是自我赋值，直接返回
	if (this == &right)
		return *this;

	// 先释放当前栈占用的空间
	this -> ~LStack();

	myTop = NULL;
	if (!right.isEmpty())
	{
		// 复制第一个节点
		myTop = new Node(right.top());

		// 复制剩下的节点
		Node *rightPtr = right.myTop -> next;
		Node *lastPtr = myTop;
		while(rightPtr != NULL)
		{
			// 创建一个新节点并把节点链接到栈上
			lastPtr -> next = new Node(rightPtr -> data);

			// 遍历下一个节点
			rightPtr = rightPtr -> next;
			lastPtr = lastPtr -> next;
		}
	}

	return *this;
}
bool LStack::isEmpty() const
{
	return (NULL == myTop);
}

void LStack::push(ElementType element)
{
	// 先创建一个节点
	Node *newNodePtr = new Node(element, myTop);

	assert(newNodePtr != NULL);

	// 再把新节点链接到栈上
	myTop = newNodePtr;
}

void LStack::pop()
{
	if (isEmpty())
	{
		cerr << "栈为空，无元素可弹" << endl;
		return ;
	}

	Node *elementToPop = myTop;
	// 过桥
	myTop = elementToPop -> next;
	// 释放被弹出节点
	delete elementToPop;
}

ElementType LStack::top() const
{
	if (isEmpty())
	{
		cerr << "栈为空，将返回一个垃圾数据" << endl;
		ElementType garbage;
		return garbage;
	}

	return myTop -> data;
}

void LStack::display(ostream &out) const
{
	Node *nodePtr = myTop;
	while(nodePtr != NULL)
	{
		out << nodePtr -> data << "  ";
		nodePtr = nodePtr -> next;
	}
}

ostream & operator << (ostream &out, const LStack &stack)
{
	stack.display(out);
	return out;
}
