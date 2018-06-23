/*
 * 两段氏栈的实现文件
 */
#include "TwoStack.h"

TwoStack::TwoStack(int cap)
{
	capacity = cap;
	array = new(nothrow) Element[capacity];
	
	// 检查内容是否分配成功
	assert (array != NULL);

	top1 = -1;
	top2 = capacity;
}

TwoStack::~TwoStack()
{
	delete []array;
}

bool TwoStack::isEmpty(int stackIndex) const
{
	if (1 == stackIndex)
	{
		return (-1 == top1);
	} else if (2 == stackIndex)
	{
		return (capacity == top2);
	} else
	{
		cerr << "参数非法：" << stackIndex << endl;
		return false;
	}
}

bool TwoStack::isFull() const
{
	return (top1 + 1 == top2);
}

void TwoStack::push(Element value, int stackIndex)
{
	if (isFull())
	{// 栈已满
		cerr << "栈已满，不能再压入元素" << endl;
		return ;
	}

	if (1 == stackIndex)
	{
		++top1;
		array[top1] = value;
	} else if(2 == stackIndex)
	{
		--top2;
		array[top2] = value;
	} else 
	{
		cerr << "参数非法：" << stackIndex << endl;
	}
}

void TwoStack::pop(int stackIndex)
{
	if (isEmpty(stackIndex))
	{// 栈为空
		cerr << "栈为空，没有元素可以弹出" << endl;
		return ;
	}

	if (1 == stackIndex)
	{
		--top1;
	} else if(2 == stackIndex)
	{
		++top2;
	} else 
	{
		cerr << "参数非法：" << stackIndex << endl;
	}
}

Element TwoStack::top(int stackIndex) const
{
	if (isEmpty(stackIndex))
	{// 栈为空
		cerr << "栈为空，将返回垃圾值" << endl;
		Element garbage;
		return garbage;
	}

	if (1 == stackIndex)
	{
		return array[top1];
	} else if(2 == stackIndex)
	{
		return array[top2];
	} else 
	{
		cerr << "参数非法，将返回垃圾值" << endl;
		Element garbage;
		return garbage;
	}
}

void TwoStack::display(int stackIndex) const
{
	if (isEmpty(stackIndex))
	{// 栈为空
		cout << "栈为空" << endl;
	}

	if (1 == stackIndex)
	{
		for (int i = top1; i >= 0; i--)
			cout << array[i] << "  ";
		cout << endl;
	} else if(2 == stackIndex)
	{
		for (int i = top2; i < capacity; i++)
			cout << array[i] << "  ";
		cout << endl;
	} else 
	{
		cerr << "参数非法" << endl;
	}
}

