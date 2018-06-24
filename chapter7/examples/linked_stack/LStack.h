/*
 * 链式栈
 */
#include <iostream>

#ifndef LSTACK
#define LSTACK

typedef int ElementType;

using namespace std;

class LStack
{
public:
	LStack();
	~LStack();

	LStack(const LStack &original);

	const LStack & operator = (const LStack &right);

	bool isEmpty() const;
	
	void push(ElementType element);

	void pop();

	ElementType top() const;

	void display(ostream &out) const;

private:
	/* 节点类 */
	class Node
	{
	public:
		Node(ElementType element, Node *nxt = NULL)
		{
			data = element;
			next = nxt;
		}

		ElementType data;
		Node *next;
	};

	Node *myTop;
};

ostream & operator << (ostream &out, const LStack &stack);

#endif

