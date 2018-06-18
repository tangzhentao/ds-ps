/*
 * 已数组为节点池构建一个链表
 *
 */
#include <iostream>

#ifndef LIST
#define LIST

typedef int ElementType;
const int CAPACITY = 20;
const int NULL_VALUE = -1;

using namespace std;

/* 节点结构体 */
struct Node
{
	ElementType data;
	int next;
};

/*
 * 类有哪些操作：
 * 1. 构造
 * 2. 判空
 * 3. 插入一个节点
 * 4. 删除一个节点
 * 5. 大小
 */
class List
{
public:
	/* 默认构造函数 */
	List();
	/* 析构函数 */
	/* 判空 */
	bool isEmpty() const;
	/* 插入一个节点 */
	void insert(ElementType data, int index);
	/* 删除指定节点 */
	void remove(int index);

	/* 获取列表的大小 */
	int getSize();

	/* 显示 */
	void display (ostream & out) const;

	/* 检查节点池 */
	void checkNodesPool();
private:
	int first;
	int size;

	/* 节点池相关 */
	int free; // 空闲节点链表表头
	struct Node nodes[CAPACITY];
	
	/* 初始化节点池 */
	void initNodesPool ();
	
	/* 获取一个新节点 */
	int newNode();
	
	/* 删除指定节点 */
	void deleteNode(int index);
};

ostream & operator << (ostream &out, const List &list);

#endif
