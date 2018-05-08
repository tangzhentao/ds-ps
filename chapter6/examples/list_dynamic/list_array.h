/*
 * 列表的动态数组实现
 * 实现列表的如下功能
 * 创建一个空列表
 * 判断是不是空链表
 * 添加元素
 * 删除元素
 * 遍历列表
 */
#include <iostream>

#ifndef LIST
#define LIST

typedef int ElementType;

using namespace std;

class List
{
public:

	/*
	 * 默认构造函数
	 *
	 * 前置条件：
	 *	无
	 *
	 * 后置条件：
	 *	创建一个空列表
	 */
	List();

	/*
	 * 带列表容量构造函数
	 *
	 * 前置条件：
	 *	无
	 *
	 * 后置条件：
	 *	创建一个指定容量的空列表
	 */
	List(int maxSize): myCapacity(1024);
	/*
	 * 自定义构造函数
	 *
	 * 前置条件：
	 *	提供一个数组
	 *
	 * 后置条件：
	 *	创建一个元素为给定数组的列表
	 */
	List(ElementType a[], int size);

	/*
	 * 判断是不是空链表
	 */
	bool isEmpty() const;

	/*
	 * 在指定位置插入一个元素
	 * 前置条件:
	 *	链表还没满，位置要合法：0 =< pos <= size 
	 * 后置条件：
	 *  item被插入到指定的位置
	 */
	void insert(ElementType item, int pos);
	
	/*
	 * 删除给定的元素
	 * 前置条件：
	 *  列表不为空？
	 * 后置条件：
	 *  返回有没删除成功？返回失败原因？
	 */
	void erase(int pos);

	/*
	 * 遍历列表
	 *
	 * 前置条件：
	 *  无
	 * 后置条件：
	 *  打印列表的所有元素
	 */
	void display(ostream &out) const;


private:
	int myCapacity;
	ElementType array[CAPACITY];
	int size;
};

/*
 * 重载输出操作符
 *
 * 前置条件：输出流已经打开
 */
ostream & operator << (ostream &out, const List &list);

#endif
