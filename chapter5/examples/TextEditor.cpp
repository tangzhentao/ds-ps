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
			cout << "Open output file <" << myOutFilename << "> failed" << endl;
		}
	} else 
	{
		cout << "Open input file <" << myInFilename << "> failed" << endl;
	}
}

string TextEditor::nextLine()
{
	getline(in, myLine);
	return myLine;
}
