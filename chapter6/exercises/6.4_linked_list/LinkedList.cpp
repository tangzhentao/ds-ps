/*
 * 链表
 */
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	cout << "LinkedList构造函数：" << this << endl;
	first = NULL;
	size = 0;
}

LinkedList::LinkedList(const LinkedList &original)
{
	cout << "复制构造函数：" << this << ", 复制了" << &original << endl;
	size = original.size;

	Node *nodePtr = original.first;
	Node *preNodePtr = NULL;
	while(nodePtr != NULL)
	{
		// 创建一个动态内存的新节点
		Node *nodeCopyPtr = new(nothrow) Node;
		// 检查节点是否创建成功
		assert (nodeCopyPtr != NULL);
		// 复制值
		nodeCopyPtr -> data = nodePtr -> data;

		// 把新节点链接到链表上
		if (NULL == preNodePtr)
		{
			// 该节点逻辑上的前驱为空，表明该节点是头节点
			first = nodeCopyPtr;

		} else 
		{
			// 把该节点链接到前驱的后面
			preNodePtr -> next = nodeCopyPtr;
		}
		// 保存该节点为下一个节点的前驱
		preNodePtr = nodeCopyPtr;

		// 遍历original链表的下一个节点
		nodePtr = nodePtr -> next;
	}

}

LinkedList::~LinkedList()
{
	cout << "析构函数：" << this << endl;
	Node *nodePtr = first;
	while (nodePtr != NULL)
	{
		Node *tmpPtr = nodePtr;
		nodePtr = nodePtr -> next;

		// 释放
		delete tmpPtr;
	}
}

bool LinkedList::empty() const
{
	return (NULL == first);
}

void LinkedList::insert(const Node &newNode, int index)
{
	// 检查index是否合法
	if (index < 0 || index > size)
	{
		cerr << "index 不合法："  << index << endl;
		return;
	}

	Node *nodePtr = new(nothrow) Node(newNode.data);
	assert (NULL != nodePtr);
	cout << "插入node<" << nodePtr << ">: " << newNode.data << "在：" << index<< endl;

	/*
	 * 为了把节点插入到index处，需要获取index - 1处的节点
	 * 1. 如果获取的节点为NULL，则表明要插入的位置为头部
	 * 2. 节点不为NULL，表明插入的位置为非头部
	 */
	if (0 != index)
	{
		// 插入到非头部的位置
		// 获取前驱
		Node *preNodePtr = nodeAtIndex(index - 1);

		nodePtr -> next = preNodePtr -> next;
		preNodePtr -> next = nodePtr;
	} else 
	{
		// 插入到头部
		if (NULL == first)
		{
			// 如果头节点为NULL
			first = nodePtr;
		} else 
		{
			// 头节点非空
			nodePtr -> next = first;
			first = nodePtr;
		}
	}

	++size;
}

void LinkedList::remove(Node *node)
{
	if (node == first)
	{
		// 要删除的是头节点
		first = first -> next;
		delete node;

		// size减1
		--size;
	} else 
	{
		// 要删除的非头节点
		// 找到node的前驱
		Node *preNodePtr = first;
		while (preNodePtr -> next != NULL && preNodePtr -> next != node)
		{
			preNodePtr = preNodePtr -> next;
		}

		if (NULL == preNodePtr)
		{
			// 未找到node的前驱，则表明node不是链表的一个节点
			cerr << "非法操作, node<" << node << ">: " << node -> data << "不是链表的一个节点。" << endl; 
		} else 
		{
			// 找到了node的前驱
			preNodePtr -> next = node -> next;
			delete node;

			--size;
		}
	}
}

void LinkedList::remove(int index)
{
	// 检查index是否合法
	if (index < 0 || index > size)
	{
		cerr << "index 不合法："  << index << endl;
		return;
	}

	if (0 == index)
	{
		// 删除头节点
		Node *tmpNodePtr = first;
		first = first -> next;
		delete tmpNodePtr;
		--size;
	} else 
	{
		// 删除的是非头节点
		Node *preNodePtr = nodeAtIndex(index - 1);
		Node *nodePtr = nodeAtIndex(index);

		preNodePtr -> next = nodePtr -> next;

		delete nodePtr;

		--size;
	}
}

void LinkedList::display(ostream &out) const
{
	out << "<" << this << ">size: " << size << endl;
	Node *node = first;
	while(NULL != node)
	{
		out << node -> data << ' ';
		node = node -> next;
	}
}

ostream & operator << (ostream &out, const LinkedList &list)
{
	list.display(out);
	return out;
}

Node * LinkedList::nodeAtIndex(int index)
{
	// 检查index是否合法
	if (index < 0 || index > size)
	{
		cerr << "index 不合法："  << index << endl;
		return NULL;
	}

	int i = 0;
	Node *pNode = first;
	for (int i = 1; i <= index; i++)
	{
		pNode = pNode -> next;
		if (NULL == pNode)
		{
			break;
		}
	}

	return pNode;
}

/* 为练习题而写的函数，和多项式本身没有关系 */
double LinkedList::average()
{
	double average = 0;
	Node *nodePtr = first;
	int count = 0;
	double sum = 0;
	while(nodePtr != NULL)
	{
		sum += nodePtr -> data;
		++ count;
		nodePtr = nodePtr -> next;
	}

	if (count > 0)
		average = sum / count;
	
	return average;
}

bool LinkedList::isAscending()
{
	bool isAscending = true;
	
	/*
	 * 1. 链表为空时，看作不是升序
	 * 2. 链表只有一个元素时，看作是升序
	 * 3. 其他情况照旧
	 */

	// 判空
	if (empty())
	{
		isAscending = false;
	} else if (first -> next == NULL)
	{
	} else if (first -> next != NULL)
	{
		Node *nodePtr = first;
		while (NULL != nodePtr)
		{
			Node *nextNodePtr = nodePtr -> next;
			if (NULL == nextNodePtr)
			{
				break;
			} else 
			{
				DataType preData = nodePtr -> data;
				DataType nextData = nextNodePtr -> data;
				if (preData > nextData)
				{
					isAscending = false;
					break;
				}

				nodePtr = nextNodePtr;
			}
		}
	}

	return isAscending;
}

Node *LinkedList::preNodeForData(DataType value)
{
	Node *preNode = NULL;
	Node *nodePtr = first;
	while (nodePtr -> next)
	{
		if (value == nodePtr -> next -> data)
		{
			preNode = nodePtr;
			break;
		}

		nodePtr = nodePtr -> next;
	}

	return preNode;
}

void LinkedList::insertNext(Node newNode, int index)
{
	insert(newNode, index + 1);
}

void LinkedList::removeNodeAt(int index)
{
	cout << "删除第" << index << "个节点" << endl;
	// 检查index是否合法
	if (index < 0 || index >= size)
	{
		cerr << "index 不合法："  << index << endl;
		return ;
	}

	// 删除头节点
	if (0 == index)
	{
		Node *nodeToDelete = first;
		first = first -> next;

		// 释放要删除节点的内存
		delete nodeToDelete;

		// size减1
		--size;
		
		return ;
	}

	// 先找到第index-1个节点
	int i = 0;
	Node *pNode = first;
	for (int i = 1; i <= index - 1; i++)
	{
		pNode = pNode -> next;
	}

	Node *nodeToDelete = pNode -> next;
	pNode -> next = nodeToDelete -> next;

	// 释放要删除节点的内存
	delete nodeToDelete;

	// size减1
	--size;

	return ;
}

LinkedList LinkedList::shuffleMerge(const LinkedList &list) const
{
	// 先创建一个空链接
	LinkedList mergedList;

	/* 处理特殊情况 */
	if (0 == size && 0 == list.size)
	{
		// 如果两个链表都为空，则返回一个空链表
		return mergedList;
	} else if (0 == size)
	{
		// 如果自己为空，list不为空，则返回list
		return list;

	} else if (0 == list.size)
	{
		// 如果list为空自己不为空，则返回自己
		return *this;
	}

	/* 处理都不为空的情况 */
	Node *mePtr = first;
	Node *otherPtr = list.first;
	Node *preNodePtr = NULL; // 合成链接的前驱
	bool insertMe = false; // 交替插入的标记

	while (mePtr != NULL || otherPtr != NULL)
	{
		// 先动态创建一个空节点
		Node *newNodePtr = new(nothrow) Node;
		// 判断是否创建成功
		assert (newNodePtr != NULL);

		if (NULL == preNodePtr)
		{// 如果前驱为空，则表明将要插入的节点是合并链表的头节点

			// 复制me的头节点为合并列表的头节点
			newNodePtr -> data = mePtr -> data;
			mergedList.first = newNodePtr;

			// 遍历me的下一个节点
			mePtr = mePtr -> next;

			// 更新前驱
			preNodePtr = newNodePtr;

			// 切换为下次插入other节点
			insertMe = false;
		} else 
		{// 如果前驱不是空，则表明将要插入的不是头节点

			// 先把新节点连接到前驱的next上，再复制对应的data
			preNodePtr -> next = newNodePtr;
			// 更新前驱
			preNodePtr = newNodePtr;

			// 判断要插入谁的节点
			if (insertMe)
			{// 应该插入me的节点

				// me的链表是否到了末尾
				if (NULL == mePtr)
				{// 到了末尾，没有节点可插入了

					// 复制other节点data
					newNodePtr -> data = otherPtr -> data;
					// 遍历下一个节点
					otherPtr = otherPtr -> next;
				} else 
				{// 还没到末尾

					// 复制data
					newNodePtr -> data = mePtr -> data;
					// 遍历下一个节点
					mePtr = mePtr -> next;
				}
				// 切换为插入other的节点
				insertMe = false;
			} else 
			{// 应该插入other的节点

				// other的链表是否到了末尾
				if (NULL == otherPtr)
				{// 到了末尾，没有节点可插入了

					// 复制me节点data
					newNodePtr -> data = mePtr -> data;
					// 遍历下一个节点
					mePtr = mePtr -> next;
				} else 
				{// 还没到末尾

					// 复制data
					newNodePtr -> data = otherPtr -> data;
					// 遍历下一个节点
					otherPtr = otherPtr -> next;
				}
				// 切换为插入me的节点
				insertMe = true;
			}

		}

		// mergedList的size加1
		++mergedList.size;
	}

	return mergedList;
}

LinkedList LinkedList::shuffleMergeNoCopy(LinkedList &list) 
{
	size += list.size;

	/* 处理特殊情况 */
	if (0 == size && 0 == list.size)
	{
		// 如果两个链表都为空，则返回一个空链表
		return *this;
	} else if (0 == size)
	{
		// 如果自己为空，list不为空，则返回list
		first = list.first;
		return *this;

	} 

	/* 处理都不为空的情况 */
	Node *mePtr = first; // 当前插入点
	Node *otherPtr = list.first; // 待插入点
	while (mePtr != NULL && otherPtr != NULL)
	{
		cout << mePtr -> data << ", " << otherPtr -> next << endl;
		// 获取当前节点的下一个节点
		Node *meNextPth = mePtr -> next;
		// 获取下一个待插入的节点
		Node *otherNextPtr = otherPtr -> next;

		// 如果当前节点的下一个节点不为空，让待插入节点的next指向当前节点的下一个节点
		// 如果为空，则不改变待插入后的next, 完成本次插入后也就完成了整个合并操作
		if (meNextPth != NULL)
		{
			otherPtr -> next = meNextPth;
		}
		// 让当前节点的next指向待插入节点
		mePtr -> next = otherPtr;

		// 
		mePtr = meNextPth;
		otherPtr = otherNextPtr;
	}

	return *this;
}

LinkedList LinkedList::ascendingMerge(const LinkedList &list) const
{
	if (!isAscending() || !list.isAscending())
	{
		cout << "存在不是升序的链表" << endl;
		return NULL;
	}

	LinkedList mergedList;
	Node *mePtr = first;
	Node *otherPtr = list.first;
	Node *mPtr = NULL;

	while (mePtr && otherPtr)
	{
		// 创建一个新节点
		Node *newPtr = new Node;
		if (NULL == mPtr)
		{
			mergedList.first = newPtr;
		} else
		{
			mPtr -> next = newPtr;
		}

		// 
		mPtr = newPtr;
		if (mePtr -> data <= otherPtr)
		{
			newPtr -> data = mePtr -> data;
			mePtr = mePtr -> next;
		} else 
		{
			newPtr -> data = otherPtr -> data;
			otherPtr = otherPtr -> next;
		}
	}
	/*
	 实现一个Student类，包含以下功能：
	 1、包含的属性有：姓名、学号和包含成绩的一个数组(成绩的个数不定,三五个成绩就行)
	 2、实现默认构造函数、自定义构造函数(以姓名、序号、和成绩数组为参数)
	 3、实现输出操作符重载
	 4、实现复制构造函数
	 5、实现赋值运算符重载
	 6、实现析构函数
	 7、实现一个比较成绩好坏的函数(比较两学生的平均成绩，返回成绩好的学生)
	 
	 实现测试驱动程序，内容如下：
	 1、创建一个Student对象
	 2、输出该对象(使用cout也就是使用输出操作符重载)
	 3、
	 要求：
	 为了清楚的看到每个函数的调用时机，在每个函数中打印这些信息：
	 1、对象地址
	 2、函数名
	 3、对于复制构造函数，打印被复制的对象地址和复制对象的地址
	 4、对于赋值运算，打印左值对象地址和右值对象地址

	实现类以后，测试每个函数。观察打印信息
	 /
}
