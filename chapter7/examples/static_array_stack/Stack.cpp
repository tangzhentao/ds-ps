/*
 * 数据存储方式为静态数组的栈的实现文件
 */
#include "Stack.h"

/*
 * 默认构造函数
 *
 * 前置条件：无
 * 后置条件：创建一个空栈，其中top为-1
 */
Stack::Stack(): top(-1)
{
}

/*
 * 判断栈是不是空
 */
bool Stack::isEmpty() const
{
	return (-1 == top);
}

/*
 * 判断栈是不是满了
 */
bool Stack::isFull() const
{
	return (CAPACITY - 1 == top);
}

/*
 * 压入栈
 */
void Stack::push(const ElementType &value)
{
	// 检查栈是不是满了
	if (top == CAPACITY - 1)
	{
		cerr << "栈已满，无法再压入数据" << endl;
		exit(1);
	}

	++top;
	array[top] = value;
}

/* 访问栈顶元素 */
ElementType Stack::getTop() const
{
	// 检查是不是空栈，如果是空栈则返回新创建的垃圾数据
	if (isEmpty())
	{
		cerr << "当前栈为空，返回的是垃圾数据" << endl;
		ElementType garbage;
		return garbage;
	}

	return array[top];
}

/* 
 * 访问栈底元素
 *
 * 前置条件：无
 * 后置条件：如果栈不为空则返回栈底的元素即，array[0]
 *			 如果栈为空，则返回一个垃圾数据
 */
ElementType Stack::getBottom() const
{
	// 检查是不是空栈，如果是空栈则返回新创建的垃圾数据
	if (isEmpty())
	{
		cerr << "当前栈为空，返回的是垃圾数据" << endl;
		ElementType garbage;
		return garbage;
	}

	return array[0];
}
/* 
 * 弹出栈
 *
 * 前置条件：栈不为空
 * 后置条件：弹出栈顶元素，top减1
 */
void Stack::pop()
{
	// 检查栈是否为空，若为空，提示
	if (isEmpty())
	{
		cerr << "栈为空，无元素可弹出" << endl;
		return ;
	}

	--top; 
}

void Stack::display(ostream &out) const
{
	for (int i = top; i >=0; i--)
	{
		out << array[i] << "  ";
	}
}

ostream & operator << (ostream &out, const Stack &stack)
{
	stack.display(out);
	return out;
}

