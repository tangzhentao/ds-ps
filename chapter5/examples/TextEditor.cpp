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
