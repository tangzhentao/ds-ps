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

	cout << "Editing commands are:" << endl;
	cout << "\tI str:	Insert string str before another string" << endl; 
	cout << "\tD str:	Delete string str" << endl; 
	cout << "\tR str:	Replace string str with another string" << endl; 
	cout << "\tN :	Get next line of text" << endl; 
	cout << "\tQ :	Quit editing" << endl; 
	cout << "Enter an editing command following each prompt>" << endl;


	while (1)
	{
		cout << "> ";
		char command;
		cin >> command;

		switch (command)
		{
			case 'N':
				{
					cout << 'N' << endl;
					string line = te.nextLine();
					cout << "line: " << line << endl;
				}
				break;

			case 'Q':
				{
					cout << 'Q' << endl;
					break;
				}
				break;
		}

		if ('Q' == command)
		{
			break;
		}
	}

	return 0;
}
