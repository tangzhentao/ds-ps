/*
 * 演示string的编辑操作
 */
#include <iostream>

using namespace std;

int main()
{
	string s("hello world");
	string s1("nice day");
	string s2;
	char ca[] = "wake up early";

	// 将字符数组ca的前7个字符添加到s2的尾部
	s2.append(ca, 7);
	cout << "s2: " << s2 << endl;
	// 将字符串s从第4个字符开始的子串添加到s2的尾部
	s2.append(s, 4);
	cout << "s2: " << s2 << endl;

	string name = "michigan";
	string greatLake;
	cout << "\nname: " << name << endl;

	// --- 连接“Lake” 和name的值并将结果赋给greatLake
	greatLake = "Lake" + name;
	cout << "(concatenate)\n\tgreatLake:"
		 << greatLake << endl;

	// --- 将“der”添加到name值的后面
	name.append("der");
	cout << "(append)\n\tname: " << name << endl;

	// -- 删除name的前6个字符串，对产生的结果再删除其中从位置3开始的2个字符
	name.erase(0, 6);
	cout << "(erase)\n\t" << "name: " << name << endl;
	name.erase(3, 2);
	cout << "(erase)\n\t" << "name: " << name << endl;

	// -- 将“Gr” 插入到name中位置0处
	name.insert(0, "Gr");
	cout << "(insert)\n\t" << "name: " << name << endl;

	// 交换name和greatLake
	name.swap(greatLake);
	cout << "(swap)\n\t" << name + " " + greatLake << endl;
	 return 0;
}
