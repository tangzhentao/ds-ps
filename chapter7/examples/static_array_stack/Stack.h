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

	/* 练习7.2 第8题
	 * 提取栈中的第n个元素(从栈顶开始)
	 * 提取后，这n个元素将被删除
	 */
	ElementType nthElement(int n);

	/* 练习7.3 第9题
	 * 提取栈中的第n个元素(从栈顶开始)
	 */
	ElementType nthElementReadOnly(int n) const;

private:
	int top;
	ElementType array[CAPACITY];
};

ostream & operator << (ostream &out, const Stack &stack);

#endif
