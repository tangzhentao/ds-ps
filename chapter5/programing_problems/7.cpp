/*
 * 读取C++源文件、删除其中的注释行然后输出到另一个文件中
 * 注释行有两种
 * 1、单行注释： 以 //开头
 * 2、多行注释：以/ * 开头 以* /结尾
 *
 * 注意：
 * 多行注释形式的注释行，也可以只占一行。
 * 多行注释形式复杂具体有以下几种形式：
 * 1、/ * xxxxx * /
 * 
 * 2、/ * xxx
 *		xxxxx
 *	  * /
 * 
 * 3、/ * xxx
 *	     xxxxx * /
 *
 * 所以基本思路就是：
 * 1、删除每行行首的空白字符
 * 2、判断是否是单行形式注释行，是就直接删除
 * 3、是否是多行形式注释的开始行，是的话就删除接下来的行知道遇到结束符 * /
 */
#include <iostream>
#include <fstream>

using namespace std;

void removeWhitespace(string &str)
{
	while(!str.empty() &&  isspace( str.at(0) ))
	{
		str.erase(0, 1);
	}
}

// 是否是单行注释
bool isOneLineComment(string str)
{
	bool result = false;
	// 删除行首空白字符
	removeWhitespace(str);

	// 空行 直接返回
	if (str.empty())
	{
		return result;
	}
	// 截取行首的两个字符
	string substr = str.substr(0, 2);

	if ("//" == substr)
	{
		result = true;
	}

	cout << str << ": "  << boolalpha << result << endl;
	
	return result;
}

// 是否是多行注释的开始行
bool isManyLineCommentBegin(string str)
{
	bool result = false;
	// 删除行首空白字符
	removeWhitespace(str);

	// 空行 直接返回
	if (str.empty())
	{
		return result;
	}

	string substr = str.substr(0, 2);
	if ("/*" == substr)
	{
		result = true;
	}

	return result;
}

// 是否是多行注释的结束行
bool isManyLineCommentEnd(string str)
{
	bool result = false;
	// 删除行首空白字符
	removeWhitespace(str);

	// 截取行尾的两字符，判断是不是 * /
	unsigned len = str.length();
	if (len >= 2)
	{
		string substr = str.substr(len - 2, 2);
		if ("*/" == substr)
		{
			result = true;
		}
	}

	return result;
}


int main()
{
	cout << "输入文件名：";
	string infilename;
	getline(cin, infilename);
	ifstream infile(infilename.data());
	if (!infile.is_open())
	{
		cerr << "打开输入文件失败" << endl;
		return 0;
	}

	string outfilename = infilename + ".out";
	ofstream outfile(outfilename.data());
	if (!outfile.is_open())
	{
		cerr << "打开输入文件失败" << endl;
		return 0;
	}

	// 处理文件
	string line;
	bool skip = false;
	bool inManyLineComment = false;
	while (getline(infile, line))
	{
		bool comment = isOneLineComment(line);
		if (comment)
		{
			skip = true;
		} else if (isManyLineCommentBegin(line))
		{
			skip = true;
			inManyLineComment = true;
		} else if (isManyLineCommentEnd(line))
		{
			skip = true;
			inManyLineComment = false;
		} else if (inManyLineComment) 
		{
			skip = true;
		} else 
		{
			skip = false;
		}

		if (!skip)
		{
			outfile << line << endl;
		}
	}
	
	return 0;
}
