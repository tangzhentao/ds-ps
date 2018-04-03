/*
 * 文本编辑器实现文件
 */
#include <iostream>
#include "TextEditor.h"

using namespace std;

TextEditor::TextEditor()
{
}

TextEditor::TextEditor(const string &inFilename, const string &outFilename)
{
	myInFilename = inFilename;
	myOutFilename = outFilename;
	myState = 0;

	cout << "in flile: " << inFilename << endl;
	cout << "out file: " << outFilename << endl;
	in.open(myInFilename.data());
	if (in.is_open())
	{
		cout << "Open input file <" << myInFilename << "> success" << endl;
		out.open(myOutFilename.data());
		if (out.is_open())
		{
			cout << "Open output file <" << myOutFilename << "> success" << endl;
		} else 
		{
			myState = 2;
			cout << "Open output file <" << myOutFilename << "> failed" << endl;
		}
	} else 
	{
		myState = 1;
		cout << "Open input file <" << myInFilename << "> failed" << endl;
	}
}

string TextEditor::line()
{
	return myLine;
}

string TextEditor::nextLine()
{
	getline(in, myLine);
	return myLine;
}

void TextEditor::saveCurrentLine()
{
	if (myLine.empty())
		return;
	out << myLine << endl;
}

int TextEditor::state ()
{
	return myState;
}

void TextEditor::replace(const string &str, const string &newStr)
{
	// 先查找str所在的位置
	int pos = myLine.find(str);
	cout << "pos: " << pos << endl;
	if (string::npos == pos)
		return;

	// 替换指定位置开始的指定长度的字符串替换为newStr
	myLine.replace(pos, str.length(), newStr);
	cout << myLine << endl;
}

void TextEditor::insert(const string &strToInsert, const string &posStr)
{
	if (strToInsert.empty())
	{
		return;
	}

	int pos = myLine.find(posStr);
	if (string::npos == pos)
		return;

	string tmp = myLine.insert(pos, strToInsert);
	cout << "tmp: " << tmp << endl;
	cout << "myLine: " << myLine << endl;
}

void TextEditor::remove(const string &str)
{
	int pos = myLine.find(str);
	if (string::npos != pos)
	{
		myLine.erase(pos, str.length());
	} else 
	{
		cout << "Can not found " << str << endl;
	}
}
