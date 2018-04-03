/*
 * TextEditor类的实现文件
 */
#include "TextEditor.h"

using namespace std;

TextEditor::TextEditor(string inputFile, string outputFile)
{
	myInstream.open(inputFile.data());
	if (myInstream.is_open())
	{// 打开输入成功
		myOutstream.open(outputFile.data());
		if (!myOutstream.is_open())
		{// 打开输出文件成功
			cerr << "Faild to open " << outputFile << endl;
			exit(-1);
		}
	} else 
	{
		cerr << "Faild to open " << inputFile << endl;
		exit(-2);
	}
}

void eatBlanks()
{
	char blank;
	while (cin.peek() == ' ')
	{
		cin.get(blank);
	}
}

void TextEditor::run()
{
	// 显示编辑菜单
	showMenu();

	cout << "Enrer an editing command following each prompt >\n\n";
	getline(myInstream, myLine);
	cout << "TEXT: " << myLine << endl;

	char command;
	string str1, str2;

	while (1)
	{
		if (myInstream.eof())
			break;

		cout << '>';
		cin >> command;
		cin.ignore(1, '\n');
		switch(toupper(command))
		{
			case 'I' :
				{
					eatBlanks();
					getline(cin, str1);
					cout << "Insert before what string? ";
					getline(cin, str2);
					insert(str1, str2);
					cout << "TEXT after insert: " << myLine << endl;
				}
				break;

			case 'D':
				{
					eatBlanks();
					getline(cin, str1);
					erase(str1);
					cout << "TEXT after delete: " << myLine << endl;
				}
				break;

			case 'Q' :
				{
					quit();
				}
				break;

			default:
				{
					cout << "\n*** Illegal command ***\n";
					showMenu();
					cout << "TEXT: " << myLine << endl;
				}
		}
	}
}

void TextEditor::showMenu()
{
	cout << "Editing commands are:" << endl;
    cout << "\tI str:   Insert string str before another string" << endl;
    cout << "\tD str:   Delete string str" << endl;
    cout << "\tR str:   Replace string str with another string" << endl;
    cout << "\tN :  Get next line of text" << endl;
    cout << "\tQ :  Quit editing" << endl;
}

void TextEditor::insert(string str1, string str2)
{
	int pos = myLine.find(str2);
	if (string::npos != pos)
	{
		myLine.insert(pos, str1);
	} else
	{
		cout << "Can not find " << str2 << endl;
	}
}

void TextEditor::erase(string str)
{
	int pos = myLine.find(str);
	if (string::npos != pos)
	{
		myLine.erase(pos, str.length());
	} else
	{
		cout << str << " not found." << endl;
	}
}

void TextEditor::quit()
{
	exit(0);
}
