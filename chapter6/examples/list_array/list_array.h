/*
 * 列表的数组实现
 * 实现列表的如下功能
 * 创建一个空列表
 * 判断是不是空链表
 * 添加元素
 * 删除元素
 * 遍历列表
 */
#include <iostream>

#define CAPACITY 100

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
	 * 判断是不是空链表
	 */
	bool isEmpty();

	/*
	 * 在指定位置插入一个元素
	 * 前置条件:
	 *	链表还没满，位置要合法：0 =< pos <= size 
	 * 后置条件：
	 *  item被插入到指定的位置
	 */
	void insert(int item, unsigned pos);
	
	/*
	 * 删除给定的元素
	 * 前置条件：
	 *  列表不为空？
	 * 后置条件：
	 *  返回有没删除成功？返回失败原因？
	 */
	void erase(int item);

	/*
	 * 遍历列表
	 *
	 * 前置条件：
	 *  无
	 * 后置条件：
	 *  打印列表的所有元素
	 */
	void traverse();

private:
	int array[CAPACITY];
	int size;
};
