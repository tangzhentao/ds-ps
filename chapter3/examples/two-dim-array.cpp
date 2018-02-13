/*
 * 演示二维数组的输入和输出
 */
#include <iostream>

using namespace std;

const int NUM_ROWS = 4;
const int NUM_COLUMNS = 3;

typedef double TowDimArray[NUM_ROWS][NUM_COLUMNS];

int main(int argc, char *argv[])
{
	int numStudents;
	int numTests;
	TowDimArray scoresTable;
	cout << "# students and # of tests? ";
	cin >> numStudents >> numTests;

	// 输入二维数组
	cout << "Enter " << numTests << " test scores for student\n";
	for (int r = 0; r < numStudents; r++)
	{
		cout << "# " << r + 1 << ": ";
		for (int c = 0; c < numTests; c++)
		{
			cin >> scoresTable[r][c];
		}
	}

	// 输出二维数组
	cout << "print " << numStudents << " students's " << numTests << " test scors." << endl;
	for (int r = 0; r < numStudents; r++)
	{
		cout << "# " << r + 1 << " :";
		for (int c = 0; c < numTests; c++)
		{
			cout << "  " << scoresTable[r][c];
		}
		cout << endl;
	}
	cout << "hello" << endl;
	return 0;
}
