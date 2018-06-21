/*
 * List类的实现
 */
#include "List.h"

/*
 * 初始化节点池：
 * 1、节点的数据都值成0
 * 2、free指向第一个节点
 * 3、每个节点的next都指向紧挨着的下一个节点，最后一个节点next指向NULL_VALUE
 */
void List::initNodesPool()
{
	free = 0;
	for (int i = 0; i < CAPACITY - 1; i++)
	{
		nodes[i].data = 0;
		nodes[i].next = i + 1;
	}

	nodes[CAPACITY - 1].next = NULL_VALUE;
}

List::List()
{
	first = NULL_VALUE;
	size = 0;

	initNodesPool();
}

/* 
 * 从节点池中取一个空闲节点
 *
 * 前置条件：节电池中还存在空闲节点
 * 后置条件：返回空闲节点的在节点池中的索引
 */
int List::newNode()
{
	int newNodeIndex = free;
	free = nodes[free].next;
	return newNodeIndex;
}

/*
 * 删除指定节点
 * 即，把指定节点设置成空闲状态
 *
 * 前置条件：0 <= index < CAPACITY
 * 后置条件：指定节点被置成空闲状态
 */
void List::deleteNode(int index)
{
	// 检查index是否合法
	if (index < 0 || index >= CAPACITY)
	{
		cerr << "位置不合法：" << index << endl;
		return ;
	}

	nodes[index].next = free;
	free = index;
}

/* 检查节点池
 * 打印已经使用的节点index
 * 打印空闲的节点index
 */
void List::checkNodesPool()
{
	// 打印已经使用的节点index
	cout << "使用的节点index：" << endl;
	int usedIndex = first;
	while(usedIndex != NULL_VALUE)
	{
		cout << usedIndex << "->" << nodes[usedIndex].next<< " ";
		usedIndex = nodes[usedIndex].next;
	}
	cout << endl;

	// 打印空闲的节点index
	cout << "空闲的节点index：" << endl;
	int idleIndex = free;
	while(idleIndex != NULL_VALUE)
	{
		cout << idleIndex << "->" << nodes[idleIndex].next << " ";
		idleIndex = nodes[idleIndex].next;
	}
	cout << endl;
}

bool List::isEmpty() const
{
	return (NULL_VALUE == first);
}

/* 
 * 在指定位置插入一个节点
 *
 * 前置条件：index要合法，0 <= index <= size
 * 后置条件：在index出插入了一个新节点
 */
void List::insert(ElementType data, int index)
{
	// 检查index是否合法
	if (index < 0 || index > size)
	{
		cerr << "插入位置不合法：" << index << endl;
		return ;
	}

	// 获取一个新节点
	int newNodeIndex = newNode ();
	assert (newNodeIndex != NULL_VALUE);


	// 为新节点赋值
	nodes[newNodeIndex].data = data;

	// 把新节点插入到index处
	if (0 == index)
	{// 插入到表头
		nodes[newNodeIndex].next = first;
		first = newNodeIndex;
	} else 
	{// 插入到非表头位置
		int preIndex = first;
		for (int i = 1; i < index; i++)
		{
			preIndex = nodes[preIndex].next;
		}

		nodes[newNodeIndex].next = nodes[preIndex].next;
		nodes[preIndex].next = newNodeIndex;
	}

	// 累加size
	++size;
}

void List::remove(int index)
{
	// 检查index是否合法
	if (index < 0 || index >= size)
	{
		cerr << "删除节点的位置不合法：" << index << endl;
		return ;
	}

	// 删除节点
	if (0 == index)
	{// 删除表头节点
		int tmpIndex = first;
		first = nodes[tmpIndex].next;

		// 释放该节点到节点池
		deleteNode(tmpIndex);
	} else
	{// 删除的节点不是头节点

		// 先获取要删除节点的前驱
		int preIndex = first;
		for (int i = 1; i < index; i++)
			preIndex = nodes[preIndex].next;
		// 获取要删除的节点index
		int tmpIndex = nodes[preIndex].next;
		// 过桥
		nodes[preIndex].next = nodes[tmpIndex].next;
		// 释放要删除的节点
		deleteNode(tmpIndex);
	}

	// 累减size
	--size;
}

int List::getSize()
{
	return size;
}

void List::display(ostream &out) const
{
	out << "size: " << size << endl;
	
	int index = first;
	while (index != NULL_VALUE)
	{
		out << nodes[index].data << "  ";
		index = nodes[index].next;
	}
}

ostream & operator << (ostream &out, const List & list)
{
	list.display(out);
	return out;
}
