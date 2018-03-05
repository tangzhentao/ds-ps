/*
 * 练习5.2的实现代码
 * 演示不同类型的字符串处理
 */
#include <iostream>
#include <string>

using namespace std;

/*
 * 1. 计算字符串substr在字符串str中出现的次数
 * 前置条件：
 *		两个字符串都不为空，任意一个为空时，将返回0
 * 后置条件：
 *		返回出现的次数
 */
unsigned appearTimes(const string &substr, const string &str);

/*
 * 2. 接收月份的数字，返回月份的名字
 * 前置条件：
 *		月份数字必须大于等于1小于等于12，否者返回空字符串
 * 后置条件：
 *		返回与月份数字对应的名字
 */
string monthName(unsigned month);

/*
 * 3. 接收月份的名字，返回月份的数字
 * 前置条件：
 *		月份的名字必须是下列字符串中之一：
 *		January, February, March, April, May, June, July, 
 *		August, September, October, November, December
 *		其他情况，返回0
 * 后置条件：
 *		返回对应月份的数字
 */
unsigned monthNum(const string &month);
