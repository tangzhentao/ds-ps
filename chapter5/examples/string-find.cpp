/*
 * 演示string的查找操作
 */
#include <iostream>

using namespace std;

int main()
{
	string s = "abcdeabcdeabcdeABCDE";
	cout << "s: " << s << endl;

	cout << "s.find(\"cde\"): "
		 << s.find("cde") << endl;

	cout << "s.rfind(\"cde\"): "
		 << s.rfind("cde") << endl;

	cout << "s.find_first_of(\"udu\"): "
		 << s.find_first_of("ude")
		 << "\ns.find_first_of(\"ude\", 5): "
		 << s.find_first_of("udu", 5) << endl;

	cout << "s.find_last_of(\"udu\"): "
		 << s.find_last_of("udu")
		 << "\ns.find_last_of(\"udu\", 10): "
		 << s.find_last_of("udu", 10) << endl;

	cout << "s.find_fist_of(\"usurp\"): "
		 << s.find_first_of("usurp")
		 <<"\n NOTE: string::npos = " 
		 << string::npos << endl;

	cout << "s.find_first_not_of(\"udead\"): "
		 << s.find_first_not_of("udead") << endl;

	cout << "s.find_last_not_of(\"udead\"): "
		 << s.find_last_not_of("udead") << endl;

	return 0;
}
