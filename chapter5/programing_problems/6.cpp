/*
 * 将一个文本文件复制到另一个文本文件，要求目标文件中
 * 删除移除源文件中所有的前导空格以及空白行
 */
#include <iostream>
#include <fstream>

using namespace std;

void removeWhitespace(string &str)
{
	while(!str.empty() && isspace( str.at(0) ))
	{
		cout << "删除前：[" << str << "]" << endl;
		str.erase(0, 1);
		cout << "删除后：[" << str << "]" << endl;
	}
}

int main()
{
	cout << "输入文件名：";
	string infilename;
	getline(cin, infilename);
	ifstream infile(infilename.data());

	if(!infile.is_open())
	{
		cerr << "打开文件 " << infilename << " 失败" << endl;
	}

	string outfilename = infilename + ".out";
	ofstream outfile(outfilename.data());
	if(!outfile.is_open())
	{
		cerr << "打开文件 " << outfilename << " 失败" << endl;
	}

	string line;
	while (getline(infile, line))
	{
		removeWhitespace(line);
		// 跳过空行
		if (line.empty())
		{
			cout << "空行" << endl;
			continue;
		}
		outfile << line << endl;
	}

	return 0;
}
