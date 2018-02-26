/*
 * 演示数组、结构体和类的赋值的区别和联系；
 *
 * 结论：对于形式a = b; 的赋值而言：
 * 数组:
 *		不支持直接赋值，赋值的话需要遍历每个元素单个赋值
 * 结构体:
 *		结构体可以直接赋值，赋值时是把结构体中的每个成员逐个赋值。
 * 类赋值：
 *		类赋值和结构体赋值类似，都是逐个成员赋值。
 */
#include <iostream>
#include <iomanip>

using namespace std;

struct Date
{
	unsigned year;
	unsigned month;
	unsigned day;
};

class Time
{
public:
	Time(unsigned theHour = 0, unsigned theMinute = 0)
	{
		hour = theHour;
		minute = theMinute;
		display();
	}

	void display()
	{
	cout << "Time<" << this << ">: " 
		 << setw(2) << setfill('0') << hour << ":"
		 << setw(2) << setfill('0') << minute << endl;
	}

private:
	unsigned hour;
	unsigned minute;
};

int main()
{
	// 数组赋值：不支持
	/*
	int a[4] = {1, 2, 3, 4};
	int b[4] = a;
	*/

	// 结构体赋值
	Date date1 = {1900, 1, 1};
	Date date2;
	date2 = date1;
	cout << "date1<" << &date1 << ">: " << date1.year << "-" << date1.month << "-" << date1.day << endl;
	cout << "date2<" << &date2 << ">: " << date2.year << "-" << date2.month << "-" << date2.day << endl;

	// 类赋值
	Time midnight;

	Time mealTime(12, 0);
	Time workTime = Time(9, 30);
	cout << "workTime: " << &workTime << endl;

	Time sleepTime = workTime;
	sleepTime.display();

	return 0;
}
