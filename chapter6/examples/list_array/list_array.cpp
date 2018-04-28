/*
 * 实现文件
 */
#include <iostream>
#include "list_array.h"

using namespace std;

List::List()
{
	size = 0;
}

List::List(ElementType a[], int theSize)
{
	cout << __func__ << endl;
	size = theSize;
	for (int i = 0; i < theSize; i++)
	{
		array[i] = a[i];
	}
	cout << "List end" << endl;
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

	if (size == CAPACITY)
		return ;

	if (pos > size || pos < 0)
		return ;

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
	out << "List: " << endl;
	for (int i = 0; i < size; i++)
	{
		out << array[i] << "  ";
	}
	out << endl;
}

ostream & operator << (ostream &out, const List &list)
{
	if (list.isEmpty())
		return out;

	list.display(out);

	return out;
}
