/*
 * 连接两个文件：要求将一个文件添加到另一个文件后面
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "输入文件名1: ";
	string file1;
	string file2;
	getline(cin, file1);
	cout << "输入文件名2: ";
	getline(cin, file2);

	ifstream inFile(file1.data());
	if (!inFile.is_open())
	{
		cout << "打开输入文件 " << file1 << " 失败" << endl;
		return 0;
	}

	ofstream outFile(file2.data(), ios::app);
	if (!outFile.is_open())
	{
		cout << "打开输出文件 " << file2 << " 失败" << endl;
		return 0;
	}


	string line;
	while(getline(inFile, line))
	{
		cout << "line: " << line << endl;
		outFile << line << endl;
	}
	
	return 0;
}
