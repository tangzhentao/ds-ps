/*
 * 读取一个文本文件：
 * 1、统计文件中每一行字符的个数并显示行号
 * 2、统计最短、最长行的长度以及平均每行的字符个数
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "输入文件名：";
	string filename;
	getline(cin, filename);
	ifstream file(filename.data());
	if(!file.is_open())
	{
		cerr << "打开文件 " << filename << " 失败。" << endl;
		return 0;
	}

	unsigned min = INT_MAX;
	unsigned max = 0;
	unsigned sum = 0;
	unsigned lineNum = 0;
	string line;
	while (getline(file, line))
	{
		++lineNum;
		unsigned len = line.length();

		cout << "第" << lineNum << "行：" << len << "个字符" << endl;
		sum += len;
		if (len < min)
			min = len;

		if (len > max)
			max = len;
	}
	cout << endl;
	cout << "最短的行有" << min << "个字符" << endl;
	cout << "最长的行有" << max << "个字符" << endl;
	cout << "平均每行有" << (double)sum / lineNum << "个字符" << endl;

	return 0;
}
