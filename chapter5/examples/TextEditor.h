/*
 * 文本编辑器的头文件
 */
#include <iostream>
#include <fstream>
using namespace std;

class TextEditor
{
	public:
		// 默认构造函数
		TextEditor();
		TextEditor(const string &inFilename, const string &outFilename);
		string nextLine();

	private:
		string myInFilename;
		string myOutFilename;
		ifstream in;
		string myLine;
		ofstream out;
};
