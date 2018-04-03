/*
 * TextEditor类的驱动程序
 */
#include <iostream>
#include "TextEditor.h"

using namespace std;

int main()
{
	cout << "Type input file: ";
	string inputFile;
	string outputFile;
	getline(cin, inputFile);
	outputFile = inputFile + ".out";
	cout << "Output file is " << outputFile << endl;
	cout << endl;
	TextEditor te(inputFile, outputFile);
	te.run();

	return 0;
}
