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

/*
 * 4.1 转成大写字符串
 */
string upper (const string str);


/*
 * 4.2 转成小写字符串
 */
string lower(const string str);

/*
 * 5. 遇到的所有substr都替换为newSubstr
 */
string replace_all(const string str, const string substr, const string newSubstr);

/*
 * 6. 接收名字、中名和姓这三个字符串，返回一个字符串
 * 前置条件：
 *	三个组成部分都是有效的字符串，否则未定义
 * 后置条件：
 *	返回一个包含三个部分的名字
 */
string formatName1(const string name, const string mName, lName);

/*
 * 7.接收一个包含名字、中名和姓的字符串，返回另外一种形式的一个字符串
 * 
 * 前置条件：
 *	name包含以空格分割的三个部分
 * 后置条件：
 *  返回格式化的名字
 */
string formartName2(const string name);
