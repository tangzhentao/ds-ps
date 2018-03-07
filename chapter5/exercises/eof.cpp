/*
 * 读到文件末尾后继续读写输入缓冲区的内容
 */
#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv) {
	char input;
	int count = 0;	

	while(cin >> input)
	{
		
		cout<<input<<flush;
		count++;
		
	}
	cout<<count<<" End."<<endl;
	
	
	
	cout<<"failbit "<<( cin.rdstate() & ios::failbit )<<endl;
	cout<<"eofbit "<<( cin.rdstate() & ios::eofbit )<<endl;
	cout<<"badbit "<<( cin.rdstate() & ios::badbit )<<endl;
	
	if((cin.fail() && cin.eof()))
	{
		int ch;
		
		cin.clear();
		
		cout<<"failbit "<<( cin.rdstate() & ios::failbit )<<endl;
		cout<<"eofbit "<<( cin.rdstate() & ios::eofbit )<<endl;
		cout<<"badbit "<<( cin.rdstate() & ios::badbit )<<endl;
		
		bool bl = !isspace(cin.get());
		
		while(bl)
		{
			continue;
		}
	}
	else
	{
		cout<<"can't go on.\n";
		exit(1);
	}
	
	while(cin >>input)
	cout<<input<<flush;
	
	return 0;
}
