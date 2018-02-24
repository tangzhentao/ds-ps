/*
 * 给出实现Time操作的函数定义
 */
#include <iostream>

using namespace std;
#include "Time.h"

/* 工具函数 */
int toMilitary(unsigned hours, unsigned minutes, char AmOrPm);
void toStandard(unsigned mulTime, unsigned &hours, unsigned &minutes, char &AmOrPm);

/* 函数实现 */
void set(Time &t, unsigned hours, unsigned minutes, char AmOrPm)
{
	if (hours >= 1 && hours <= 12 &&
		minutes >=0 && minutes <= 59 &&
		(AmOrPm == 'A' || AmOrPm == 'P'))
	{
		t.hour = hours;
		t.minute = minutes;
		t.AmOrPm = AmOrPm;
		t.milTime = toMilitary (hours, minutes, AmOrPm);
	}
	else 
	{
		cout << "*** Can't set time with these values *** " << endl;
	}
}

void display(const Time &t, ostream &out)
{
	out << t.hour << ":"
		<< (t.minute < 10 ? "0" : "") << t.minute
		<< ' ' << t.AmOrPm << ".M. ("
		<< t.milTime << " mil. Time)";
}

void advance(Time &t, unsigned hours, unsigned minutes)
{
	// 使用军用格式时间前进
	t.milTime += 100 * hours + minutes;
	unsigned milHours = t.milTime / 100;
	unsigned milMinutes = t.milTime % 100;

	// 设置为正确的格式
	milHours += milMinutes / 60;
	milMinutes = milMinutes % 60;
	milHours %= 24;
	t.milTime = 100 * milHours + milMinutes;

	// 设置标准格式时间
	toStandard(t.milTime, t.hour, t.minute, t.AmOrPm);
}

bool lessThan (const Time &t1, const Time &t2)
{
	return (t1.milTime < t2.milTime);
}

int toMilitary(unsigned hours, unsigned minutes, char AmOrPm)
{
	if (12 == hours) 
	{
		hours = 0;
	}

	return (hours * 100 + minutes + ('P' == AmOrPm ? 1200 : 0));
}

void toStandard(unsigned milTime, unsigned &hour, unsigned &minute, char &AmOrPm)
{
	hour = milTime / 100;
	minute = milTime % 100;
	AmOrPm = (hour >= 12 ? 'P' : 'A');
	hour %= 12;
	if (0 == hour)
	{
		hour = 12;
	}
}
