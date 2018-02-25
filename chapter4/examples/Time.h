/*
 * 这个头文件定义了用于处理时间的数据类型Time
 * 基本操作有
 * set：设置时间
 * display：显示时间
 */
#include <iostream>

class Time
{
public:
	/******* 成员函数 *******/

	/*
	 * 构造函数
	 */
	Time();
	Time(unsigned hours, unsigned minutes, char am_pm);

	/*
	 * 设置一个Time对象的数据成员为一个特定的值
	 * 前置条件：1 <= hours <= 12, 0 <= minutes <= 59, am_pm为‘A’或'P'.
	 * 后置条件：数据成员myHours、myMinutes和myAm_pm被分别设置成
	 *			 hours、minutes和am_pm，myMilTime成员被设
	 *			 置为等价的军用格式时间
	 */
	void set(unsigned hours, unsigned minutes, char am_pm);

	/*
	 * 使用输出流out显示标准格式以及军用格式的时间
	 * 前置条件：ostream out已经被打开
	 * 后置条件：这个Time对象所表示的时间已经被插入ostream out
	 */
	void display (ostream &out) const;

private:
	/******* 数据成员 *******/
	unsigned myHours;
	unsigned myMinutes;
	char myAm_pm; // 'A' or 'P'
	unsigned myMilTime;
};
