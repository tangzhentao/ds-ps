/*
 * 读取一个文本文件并在程序执行时输入一个字符串，然后
 * 统计此给定的字符串在文中出现的次数
 */
#include <iostream>
#include <fstream>

using namespace std;

unsigned appearTimes(string str, string substr)
{
	unsigned count = 0;

	int pos = 0;
	do
	{
		pos = str.find(substr, pos);
		cout << "pos = " << pos << endl;
		if (string::npos != pos)
		{
			pos += substr.length();
			++count;
		}

	} while (string::npos != pos);

	return count;
}

int main()
{
	cout << "输入文件名: ";
	string filename;
	getline(cin, filename);
	
	ifstream file(filename.data());
	if (!file.is_open())
	{
		cerr << "打开 " << filename << " 失败." << endl;
		return 0;
	}

	cout << "输入要搜索的字符串: ";
	string substr;
	getline(cin, substr);

	cout << "搜索字符串: "  << substr << endl;

	unsigned count = 0;
	string line;
	while (getline(file, line))
	{
		cout << "搜索: "  << line << endl;
		unsigned cnt = appearTimes(line, substr);
		count += cnt;
		cout << "搜到：" << count << "次" << endl;
	}


	cout << "'" << substr << "'" << "在文中出现" << count << "次。" << endl;
	
	return 0;
}
