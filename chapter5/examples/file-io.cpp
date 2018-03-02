/*
 * 演示文件I/O：
 * 从一个文件中读取所有整数，计算它们的最大值、最小值和平均值。
 * 然后把计算结果保存到另一个文件中。输入文件名和输出文件名
 * 都是从交互获取的。
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cfloat>

using namespace std;

int main()
{
	cout << "This program couputes the nunmber, maximum, minimum, and \n"
			"average of an input list of numbers in one file,\n"
			"and place its results in another file.\n\n";
	// ----------------输入部分
	cout << "Enter the name of input file: ";
	string inputFileName;
	getline(cin, inputFileName); // 获取输入文件的名字

	ifstream fin;
	fin.open(inputFileName.data());
	assert(fin.is_open()); // 检查打开文件是否成功

	int count = 0; // 输入文件中整数的个数
	double reading; // 正在读取的值
	double maximum = DBL_MIN; // 目前为止最大的值
	double minimum = DBL_MAX; // 目前为止最小的值
	double sum = 0; // 总和

	for ( ; ; )
	{
		fin >> reading; // 从文件中读取一个值
		if (fin.eof()) 
			break; // 如果到达文件结尾，退出
		count++;

		sum += reading;
		if (reading < minimum)
			minimum = reading;
		if (reading > maximum)
			maximum = reading;
	}
	fin.close(); // 关闭文件

	// --------------- 输出部分
	cout << "Enter the name of output file: ";
	string outputFileName;
	getline(cin, outputFileName);

	ofstream fout; // 创建一个文件输出流
	fout.open(outputFileName.data()); // 和一个文件建立联系
	assert(fout.is_open()); // 检查联系是否建立成功

	fout << "\n--> There were " << count << " values";
	if (count > 0)
	{
		fout << "\n ranging from " << minimum << " to " << maximum << "\n"
			 << "and their average is " << sum / count << endl;
	}
	fout.close (); // 关闭流
	cout << "Processing complete.\n";
	return 0;
}
