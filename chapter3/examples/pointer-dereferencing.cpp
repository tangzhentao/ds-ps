/*
 * 演示 对空指针做去引用操作会怎么样
 * 结果运行时会报段错误：Segmentation fault: 11
 */
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int *iptr = 0;
	cout << "will dereference iptr." << endl;
	cout << "*iptr = " << *iptr << endl;
	cout << "did dereference iptr." << endl;
	cout << "hello" << endl;
	return 0;
}
