/*
 * 统计文中元音字母的个数，即，a、e、i、o、u的个数
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "输入文件名：";
	string filename;
	getline(cin, filename);

	ifstream infile(filename.data());
	if (!infile.is_open())
	{
		cout << "打开文件 " << filename << " 失败" << endl;
		return 0;
	}

	string line;
	long count = 0;
	while(getline(infile, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			char c = line.at(i);
			c = tolower(c);
			if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
			{
				++count;
			}
		}
	}

	infile.close();

	cout << "文中共有" << count << "个元音字母" << endl;
	return 0;
}
