/*
 * 这个头文件定义了用于编辑文本文件的TextEditor数据类型
 * 基本操作包括：
 *   构造函数：	为给定文件创建一个TextEditor队形
 *   run():		运行编辑器
 *   showMenu():显示一个编辑热键菜单
 *   insert():	在一行文本插入一个字符串
 *   erase():	在一行文本中删除一个字符串
 *   replace():	将一行文本中的某个字符串替换成另一个字符串
 *   next():	输出编辑完的行并获取下一行要编辑的内容
 *   quit():	结束编辑
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class TextEditor
{
public:
	/*
	 * 为名为inputFile和outputFile的文件创建一个文本编辑器
	 *
	 * 前置条件：inputFile是将被编辑的文件
	 * 后置条件：outputFile包含编辑完的文件
	 */
	TextEditor(string inputFile, string outputFile);

	/*
	 * 显示编辑命令菜单
	 *
	 * 前置条件：无
	 * 后置条件：菜单被输出到cout
	 */
	void showMenu();

	/*
	 * 运行编辑器
	 *
	 * 前置条件：无
	 * 后置条件：inputFile中的文本被编辑好并被输出到outputFile
	 */
	void run();

	/*
	 * 在一行文本中插入一个字符串
	 *
	 * 前置条件：无
	 * 后置条件：如果myLine中能找到str2，则str1被插入到str2前面，否则myLine保持不变
	 */
	void insert(string str1, string str2);

	/*
	 * 在一行文本中删除一个字符串
	 *
	 * 前置条件：无
	 * 后置条件：如果在myLine中能找到str，则删除str，否则，myLine保持不变
	 */
	void erase(string str);

	/*
	 * 在一行文本中将某个字符串替换为另一个字符串
	 *
	 * 前置条件：无
	 * 后置条件：如果在myLine中能找到str1，则将str1替换为str2.
	 *			 否则，myLine保持不变
	 */
	void replace(string str1, string str2);

	/*
	 * 移到下一行要编辑的文本
	 *
	 * 前置条件：无
	 * 后置条件：myLine中的字符串被输出到myOutstream,
	 *			 从myInstream中读出新的一行到myLine中
	 */
	void next();

	/*
	 * 退出文本编辑器
	 *
	 * 前置条件：无
	 * 后置条件：myLine中的字符串被输出到outputFile,
	 *			 inputFile中剩余的行都被复制到outputFile中
	 */
	void quit();

private:
	ifstream myInstream;
	ofstream myOutstream;
	string myLine;
};
