/*
 * 读到文件末尾后继续读写输入缓冲区的内容
 */
#include <iostream>
#include <ios>

using namespace std;

void printCinState ()
{
	cout << "输入状态如下：" << endl;
	cout<<"failbit "<<( cin.rdstate() & ios::failbit )<<endl;
	cout<<"eofbit "<<( cin.rdstate() & ios::eofbit )<<endl;
	cout<<"badbit "<<( cin.rdstate() & ios::badbit )<<endl;
}

int main(int argc, char** argv) {
	char input;
	while(cin >> input)
	{
		cout<< "output: "<<input<<'\n';
	}
	
	cout << "输入失败，打印输入流状态：" << endl;
	printCinState();

	if(cin.eof())
	{
		cout << "你结束了输入，导致了输入流失败，并被标记为eof。" << endl;
		cout << "清除输入流的状态，包括eof，并再次打印状态：" << endl;
		
		cin.clear();
		
		

		cout << "尝试读取一个字符:" << endl;
		input = cin.get(); // 当get遇到eof的时候会返回结束标记，一般为-1
		
		cout << "打印这个字符和它的编码：" << endl;
		int code = input;
		cout << "<" << input << ">" << code << endl;

		printCinState ();

	}

	return 0;
}
