/*
 * 这个头文件定义了用于处理时间的数据类似Time
 * 基本操作包括：
 * set:		设置时间
 * display:	显示时间
 * advance:	将时间前进某个给定的量
 * lessThan:判断某个时间是否小于另外一个时间
 */
#include <iostream>

struct Time
{
	unsigned hour;
	unsigned minute;
	char AmOrPm; // 'A' or 'P'
	unsigned milTime; // 等价的军用格式时间
};

/*
 * 将时间设置为一个给定的值
 * AmOrPm('A' if Am, 'P' if Pm)
 */
void set (Time &t, unsigned hours, unsigned minutes, char AmOrPm);

/* 
 * 使用输出流out显示标准或者军用的时间
 */
void display (const Time &t, ostream &out);

/*
 * 将时间前进一个给定的值
 */
void advance (Time &t, unsigned hours, unsigned minutes);

/*
 * 判断一个时间是否小于另为一个时间
 */
bool lessThan(const Time &t1, const Time &t2);
