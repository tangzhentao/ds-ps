/*
 * 演示结构体的定义和初始化
 * 只有在定义的同时可以使用花括号进行初始化，
 * 要初始化定义后的结构体变量，必须使用struct.member = xx;的形式
 */
#include <iostream>

using namespace std;

struct Temperature 
{
	double degrees; // 度数
	char scale; // 温度的温标(F, C, K)）
};

int main(int argc, char *argv[])
{
	// 花括号赋值
	struct Temperature temp1 = {11, 'C'};
	// 圆括号赋值
	Temperature temp2;
	temp2.degrees = 22;
	temp2.scale = 'F';

	cout << "temp1: " << "{" << temp1.degrees << ", " << temp1.scale << "}" << endl;  
	cout << "temp2: " << "{" << temp2.degrees << ", " << temp2.scale << "}" << endl;  
	cout << "hello" << endl;
	return 0;
}
