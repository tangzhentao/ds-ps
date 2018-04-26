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

bool List::isEmpty()
{
	return (0 == size);
}

void List::insert(int item, unsigned pos)
{
	/*
	 * 1、先判断还有没有容量
	 * 2、再判断pos是否合法
	 * 3、移动相关元素
	 */

	if (size == CAPACITY)
		return ;

	if (pos > size)
		return ;
}
