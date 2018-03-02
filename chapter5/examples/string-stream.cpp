/*
 * 演示字符串流sstream的使用
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>

using namespace std;

int main()
{
	string date = "U.S. independence: July 4, 1776";

	istringstream istr(date);

	string word1;
	string word2;
	string month;
	int day;
	int year;
	char comma;
	istr >> word1 >> word2 >> month >> day >> comma >> year;
	cout << "Contents of string stream istr, one word per line: \n"
		 << word1 << '\n' << word2 << '\n' << month << '\n'
		 << day << comma << '\n' << year << '\n' << endl;
	const int Y2K = 1999;
	ofstream outfile("file5-2.out");
	assert(outfile.is_open());

	ostringstream ostr;
	ostr << word1 << "bicentennial: " << month
		 << setw(2) << day << ", " << year + 200 << endl;

	cout << "Contents of string stream ostr:\n" << ostr.str();
	outfile << ostr.str();

	return 0;
}
