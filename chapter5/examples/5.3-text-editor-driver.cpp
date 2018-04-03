/*
 * 文本编辑器的驱动程序
 */
#include "TextEditor.h"

using namespace std;

int main()
{
	cout << "Enter the name of the input file: ";
	string inputFile;
	cin >> inputFile;
	string outputFile = inputFile + ".out";
	cout << "The out file is " << outputFile << endl;
	
	TextEditor te(inputFile, outputFile);
	if (te.state())
	{
		// 打开文件失败
		return 0;
	}

	// 先获取一行
	te.nextLine();

	cout << "Editing commands are:" << endl;
	cout << "\tI str:	Insert string str before another string" << endl; 
	cout << "\tD str:	Delete string str" << endl; 
	cout << "\tR str:	Replace string str with another string" << endl; 
	cout << "\tN :	Get next line of text" << endl; 
	cout << "\tQ :	Quit editing" << endl; 
	cout << "Enter an editing command following each prompt>" << endl;


	while (1)
	{
		cout << '\n' << "TEXT: " << te.line() << endl;

		cout << "> ";
		char command;
		cin >> command;

		bool complete = false;
		switch (command)
		{
			case 'I':
				{
					string strToInsert;
					cin >> strToInsert;

					cout << "Insert before what string ? ";
					string posStr;
					cin >> posStr;
					te.insert(strToInsert, posStr);
					cout << '\n' << "TEXT: " << te.line() << endl;
				}
				break;

			case 'D':
				{
					cout << "Delete what string ? ";
					string strToDelete;
					cin >> strToDelete;
					te.remove(strToDelete);
					cout << '\n' << "TEXT: " << te.line() << endl;
				}
				break;

			case 'N':
				{
					// 在获取下一行前，保存当前行到输出文件
					te.saveCurrentLine();

					string line = te.nextLine();
					if (line.empty())
					{
						cout << "end of file." << endl;
						complete = true;
					}
				}
				break;

			case 'Q':
				{
					cout << 'Q' << endl;
					complete = true;
					// 退出前，先保存当前行
					te.saveCurrentLine();
				}
				break;

			case 'R':
				{
					cout << "Type what you want to repace: ";
					string strToReplace;
					cin >> strToReplace;
					cout << "\nwith: ";
					string newStr;
					cin >> newStr;

					te.replace(strToReplace, newStr);
					cout << "replaced line: " << te.line() << endl;
				}
				break;
		}

		if (complete)
		{
			break;
		}
	}

	return 0;
}
