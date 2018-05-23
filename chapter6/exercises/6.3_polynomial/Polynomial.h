/*
 * 多项式类
 */
#include <iostream>

#ifndef POLYNOMIAL
#define POLYNOMIAL

typedef double CoeficentType;

using namespace std;
class Polynomial
{
public:
	/* 构造函数*/
	Polynomial(int theMaxDegree);

	/* 析构函数 */
	~Polynomial();

	/* 复制构造函数*/
	Polynomial(const Polynomial & polynomial);

	/* 赋值操作符 */
	const Polynomial & operator = (const Polynomial & polynomial);

	/* 输入操作 */
	void input(istream &in);

	/* 输出操作 */
	void output(ostream &out) const;

	/* 加法操作符重载 */
	Polynomial operator + (const Polynomial &polynomial);

	/* 乘法操作符重载 */
private:
	int maxDegree; // 多项式最大的阶
	CoeficentType *coeficients; // 多项式的系数
};

/* 输入操作符重载 */
istream & operator >> (istream & in, Polynomial &polynomial);

/* 输出操作符重载 */
ostream & operator << (ostream & out, const Polynomial &polynomial);

#endif
