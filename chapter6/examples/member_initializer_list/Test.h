/*
 * 定义该类，来测试当构造函数的成员初始值设定项和
 * 构造函数的参数默认值冲突时以谁为准。
 *
 * 初步结论：
 * 构造函数的成员初始值设定项只对构造函数参数列表没有覆盖的成员函数起作用。
 * 当成员初始值设定项和默认参数冲突时，以默认参数为准。
 * 并且成员初始值设定项只在能出现在构造函数定义中不能出现在构造函数声明中；
 */
#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
	Test(string age = "22");
	void display(ostream &out) const;
	
private:
	string myName;
	string myAge;
};

ostream & operator << (ostream & out, const Test & test);
