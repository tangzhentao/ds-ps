/*
 * 多项式类的实现
 */
#include <iostream>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial(int theMaxDegree)
{
	maxDegree = theMaxDegree;
	coeficients = new(nothrow) CoeficentType[maxDegree + 1];

	// 检查动态分配内存是否成功
	assert(coeficients != NULL);
}

Polynomial::~Polynomial()
{
	delete [] coeficients;
}

Polynomial::Polynomial(const Polynomial &polynomial)
{
	maxDegree = polynomial.maxDegree;
	coeficients = new(nothrow) CoeficentType[maxDegree + 1];
	assert(NULL != coeficients);

	for (int i = 0; i < maxDegree + 1; i++)
	{
		coeficients[i] = polynomial.coeficients[i];
	}
}

/* 未完待续 */
const Polynomial & Polynomial::operator = (const Polynomial &polynomial)
{
	if (this == &polynomial)
		return *this;

	return *this;
}

void Polynomial::input(istream &in)
{
	// 输入多项式的系数
	for (int i = 0; i < maxDegree + 1; i++)
	{
		in >> coeficients[i];
	}
}

void Polynomial::output(ostream &out) const
{
	bool isFirstItem = true;
	for (int i = 0; i < maxDegree + 1; i++)
	{
		CoeficentType coeficient = coeficients[i];
		string op;

		// 跳过系数为0的项
		if ( 0 != coeficient)
		{
			// 符号
			if (isFirstItem)
			{
				op = (coeficient > 0 ? "" : "-");
			} else 
			{
				op = (coeficient > 0 ? " + " : " - ");
			}
			out << op;

			// 系数
			coeficient = abs(coeficient);
			out<< coeficient;

			// 阶
			if (0 == i)
			{
				// 不输出x和阶
			} else if (1 == i)
			{
				out << 'x';
			} else
			{
				out << "x^" << i;
			}
			
			isFirstItem = false;
		}
	}
}

Polynomial & operator + (const Polynomial & polynomial)
{
	
}

istream & operator >> (istream &in, Polynomial &polynomial)
{
	polynomial.input(in);
	
	return in;
}

ostream & operator << (ostream &out, const Polynomial &polynomial)
{
	polynomial.output(out);

	return out;
}

