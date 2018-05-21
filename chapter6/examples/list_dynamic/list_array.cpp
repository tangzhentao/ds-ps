/*
 * 实现文件
 */
#include <iostream>
#include <cassert>
#include "list_array.h"

using namespace std;

List::List(int maxSize): size(0), myCapacity(maxSize)
{
	cout << "构造函数" << "<"  << this << ">" <<  endl;
	array = new(nothrow) ElementType[maxSize];
	assert(array != 0);
	// size = 0;
	// myCapacity = maxSize;
}

List::~List()
{
	cout << "析构函数"  << "<"  << this << ">" <<  endl;
	delete [] array;
}

List::List(const List &origion): size(origion.size), myCapacity(origion.myCapacity)
{
	cout << "访问私有变量：" << origion.size << endl;
	cout << "复制构造函数" << "<"  << this << ">" << "被赋值的对象<" << &origion << ">" <<  endl;
	array = new(nothrow) ElementType[myCapacity];
	assert(NULL != array);

	for (int i = 0; i < size; i++)
	{
		array[i] = origion.array[i];
	}
}

const List & List::operator=(const List &rightSide)
{
	cout << "赋值运算符" << "<"  << this << ">" << " &rightSide<" << &rightSide << ">" << endl;

	// 判断是不是自己赋值给你自己
	if (this != &rightSide)
	{
		// 判断容量是否一样
		if (myCapacity != rightSide.myCapacity)
		{
			// 不一样，则删除旧数组，新建一个容量一样的新数组
			delete [] array;
			array = new(nothrow) ElementType[rightSide.myCapacity];
			assert(array != NULL);
			size = rightSide.size;
			myCapacity = rightSide.myCapacity;

		}

		// 用rightSide的数据覆盖自己的数据
		for (int i = 0; i < myCapacity; i++)
		{
			array[i] = rightSide.array[i];
		}
	}

	return *this;
}

bool List::isEmpty() const
{
	return (0 == size);
}

void List::insert(ElementType item, int pos)
{
	/*
	 * 1、先判断还有没有容量
	 * 2、再判断pos是否合法
	 * 3、移动相关元素
	 */
	cout << "insert " << item << " at " << pos << endl;

	if (size == myCapacity)
	{
		cerr << "插入失败，没有空间了" << endl;
		return ;
	}

	if (pos > size || pos < 0)
	{
		cerr << "插入失败，插入位置不合法" << endl;
		return ;
	}
	

	// 首先右移数组元素为item腾出空间
	for (int i = size; i > pos; i--)
	{
		array[i] = array[i - 1];
	}

	// pos以及之后的元素移动完成，此时插入新元素
	array[pos] = item;

	// 列表大小加一
	++size;
}

void List::erase(int pos)
{
	cout << "erase " << pos << endl;
	if (isEmpty())
		return;
	
	// 判断位置是否合法
	if (pos < 0 || pos > size - 1)
		return ;

	// 把要删除的位置置0
	array[pos] = 0;

	// 
	for (int i = pos; i < size - 1; i++)
	{
		array[i] = array[i+1];
	}

	// 减少size
	--size;
}

void List::display(ostream &out) const
{
	out << "<" << this << ">: " << "size = " << size << ", myCapacity = " << myCapacity  << endl;
	for (int i = 0; i < size; i++)
	{
		out << array[i] << "  ";
	}
	out << endl;
}

ostream & operator << (ostream &out, const List &list)
{
	list.display(out);

	return out;
}
