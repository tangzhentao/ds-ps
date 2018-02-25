/*
 * Time.h中声明的Time类的函数成员的定义，以及在军用格式时间和标准格式
 * 时间之间进行转换的工具函数的定义
 */
#include <iostream>

using namespace std;

#include "Time.h"

/*** 工具函数 -- 原型 ***/

int toMilitary(unsigned hours, unsigned minutes, char am_pm);

// --- 构造函数
Time::Time():myHours(0), myMinutes(0), myAm_pm('A'), myMilTime(0)
{
}

Time::Time(unsigned hours, unsigned minutes, char am_pm)
{
	myHours = hours;
	myMinutes = minutes;
	myAm_pm = am_pm;
	myMilTime = toMilitary(hours, minutes, am_pm);
}

// --- set函数的定义
void Time::set(unsigned hours, unsigned minutes, char am_pm)
{
	// 检查类不变式 ?啥意思
	if (hours >= 1 && hours <= 12 &&
		minutes >= 0 && minutes <= 59 &&
		('A' == am_pm || 'P' == am_pm))
	{
		myHours = hours;
		myMinutes = minutes;
		myAm_pm = am_pm;
		myMilTime = toMilitary(hours, minutes, am_pm);
	}
	else 
	{
		cerr << "*** Can't set time with these values ***\n";
		// 对象的数据成员未被改变
	}
}

// --- dispaly 函数的定义
void Time::display(ostream &out) const
{
	out << myHours << ':'
		<< (myMinutes < 10 ? "0" : " ") << myMinutes
		<< " " << myAm_pm << ".M. ("
		<< myMilTime << " mil. time)";
}

/*** 工具函数-- 定义***/
int toMilitary(unsigned hours, unsigned minutes, char am_pm)
{
	if(0 == hours)
		hours = 0;

	return hours * 100 + minutes + ('P' == am_pm ? 1200 : 0);
}
