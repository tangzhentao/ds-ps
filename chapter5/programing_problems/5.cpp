/*
 * 将一个文本文件复制到另一个文本文件，要求目标文件中
 * 在每行的左侧添加行号1，2，……
 */
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	cout << "输入文件名：" ;
	string infilename;
	getline(cin, infilename);

	ifstream infile(infilename.data());
	if (!infile.is_open())
	{
		cerr << "打开文件 " << infilename << " 失败" << endl;
		return 0;
	}

	string outfilename = infilename + ".out";

	cout << "输出文件为：" << outfilename << endl;

	ofstream outfile(outfilename.data());
	if (!outfile.is_open())
	{
		cerr << "打开文件 " << outfilename << " 失败" << endl;
		return 0;
	}

	string line;
	string newline;
	unsigned count = 0;
	while(getline(infile, line))
	{
		++count;
		ostringstream oss;
		oss << count << ", " << line;
		outfile << oss.str() << endl;
	}

	return 0;
}
