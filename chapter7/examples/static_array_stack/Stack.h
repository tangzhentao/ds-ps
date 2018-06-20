/*
 * 静态数组实现的栈
 */
#include <iostream>

#ifndef STACK
#define STACK

using namespace std;

typedef int ElementType;
const int CAPACITY = 32;

class Stack
{
public:
	/* 构造函数 */
	Stack();

	/* 判空 */
	bool isEmpty() const;

	/* 判满 */
	bool isFull() const;

	/* 压栈 */
	void push(const ElementType &value);

	/* 访问栈顶元素 */
	ElementType getTop() const;

	/* 访问栈底元素 */
	ElementType getBottom() const;

	/* 弹出栈 */
	void pop ();

	/* 显示栈中数据 */
	void display(ostream &out) const;

private:
	int top;
	ElementType array[CAPACITY];
};

ostream & operator << (ostream &out, const Stack &stack);

#endif
