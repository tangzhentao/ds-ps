/*
 * 练习7.2第12题
 * 使用一个动态数组来表示两段式栈 * 该类包含以下操作：
 * 1、初始化
 * 2、析构
 * 3、判空
 * 4、判满
 * 5、压入一个元素
 * 6、弹出一个元素
 * 7、访问栈顶元素
 * 8、显示栈内容
 */
#include <iostream>

#ifndef TWO_STACK
#define TWO_STACK

typedef int Element;

using namespace std;

class TwoStack 
{
public:
	/* 默认构造函数 */
	TwoStack(int cap = 16);

	/* 析构函数 */
	~TwoStack();

	/*
	 * 判断指定的栈是否为空
	 *
	 * 前置条件：stackIndex的取值范围为1或者2，代表第一个栈或第2个栈
	 * 后置条件：返回指定的栈是否为空
	 * */
	bool isEmpty(int stackIndex) const;

	/* 
	 * 判断栈是否已满
	 *
	 * 前置条件：无
	 * 后置条件：只有当数组满的时候栈才满
	 */
	bool isFull()const;

	/* 
	 * 压入一个元素到指定的栈中
	 * 前置条件：stackIndex的取值范围为1或者2，代表第一个栈或第2个栈
	 * 后置条件：如果指定的栈未满，把元素value压入其中。否则，提示
	 *			 指定的栈已满
	 * */
	void push(Element value, int stackIndex);

	/* 
	 * 从指定的栈中弹出一个元素
	 * 前置条件：stackIndex的取值范围为1或者2，代表第一个栈或第2个栈
	 * 后置条件：如果指定的栈不为空，则弹出一个元素。否则，提示
	 *			 指定的栈为空，没有元素可以弹出
	 */
	void pop(int stackIndex);

	/* 访问栈顶元素 */
	Element top(int stackIndex) const;

	/* 显示栈内容 */
	void display(int stackIndex) const;

private:
	int top1; // 第1个栈的栈顶
	int top2; // 第2个栈的栈顶
	Element *array;
	int capacity;
};

#endif
