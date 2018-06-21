/*
 * 驱动程序
 */
#include <iostream>
#include <time.h>
#include "List.h"

using namespace std;

int randomIndex(int size)
{
	int index = 0;
	if (size != 0)
	{
		// 先设置随机数种子
		srand( (int)time(0) );
		index = rand () % size;
	}

	return index;
}

int main(int argc, char *argv[])
{
	List list;
	// 检查使用情况
	cout << "空链表的内存池使用情况：" << endl;
	list.checkNodesPool();

	for (int i = 0; i < 20; i++)
	{
		// 随机生成要出入的位置
		int size = list.getSize();
		int index = randomIndex(size);
		//cout << "随机插入位置：" << index << "(" << size << ")" << endl;

		list.insert(i, index);
	}

	cout << list << endl;

	// 检查使用情况
	list.checkNodesPool();

	for (int i = 0; i < 16; i++)
	{
		// 随机生成要出入的位置
		int size = list.getSize();
		int index = randomIndex(size);
		//cout << "随机删除的位置：" << index << "(" << size << ")" << endl;

		list.remove(index);
	}

	cout << list << endl;

	// 检查使用情况
	list.checkNodesPool();

	return 0;
}
