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
		string line();
		string nextLine();
		void saveCurrentLine();
		void replace(const string &str, const string &newStr);
		int state();

	private:
		string myInFilename;
		string myOutFilename;
		ifstream in;
		string myLine;
		ofstream out;
		int myState; // 0：打开输入、输出文件成功，1：打开输入文件失败，2：打开输出文件失败
};
