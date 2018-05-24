/*
 * 多项式类的实现
 */
#include <iostream>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial(int theMaxDegree)
{
	maxDegree = theMaxDegree;
	cout << "构造函数：maxDegree = " << maxDegree << ", this = " << this << endl;
	coeficients = new(nothrow) CoeficentType[maxDegree + 1];

	// 检查动态分配内存是否成功
	assert(coeficients != NULL);
}

Polynomial::~Polynomial()
{
	cout << "析构函数：" << this << endl;
	delete [] coeficients;
}

Polynomial::Polynomial(const Polynomial &polynomial)
{
	cout << "复制构造函数, this: " << this << ", original: " << &polynomial << endl;
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
	cout << "赋值运算, this: " << this << ", right: " << &polynomial << endl;
	// 自己赋值给自己，直接返回
	if (this == &polynomial)
		return *this;


	// 如果两两者多项式最大阶数不一样
	if (maxDegree != polynomial.maxDegree)
	{
		// 先释放掉自己的数组
		delete [] coeficients;

		// 再动态分配
		coeficients = new(nothrow) CoeficentType[polynomial.maxDegree + 1];
		assert(NULL != coeficients);
	}

	// 复制数据
	maxDegree = polynomial.maxDegree;
	for (int i = 0; i < maxDegree + 1; i++)
	{
		coeficients[i] = polynomial.coeficients[i];
		//cout << "index: " << i << " = " << coeficients[i] << endl;
	}

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
			coeficient = coeficient < 0 ? -coeficient : coeficient;

			// 系数为1且阶不为零时就不输出了
			if (1 != coeficient || 0 == i) 
			{
				out<< coeficient;
			}

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

Polynomial Polynomial::operator + (const Polynomial & polynomial)
{
	cout << "多项式加法" << endl;
	int letterDegree = maxDegree;
	int greaterDegree = polynomial.maxDegree;
	const Polynomial *longerPoly = &polynomial;
	if (maxDegree > polynomial.maxDegree)
	{
		letterDegree = polynomial.maxDegree;
		greaterDegree = maxDegree;
		longerPoly = this;
	}
	Polynomial sum(greaterDegree);
	for (int i = 0; i < letterDegree + 1; i++)
	{
		sum.coeficients[i] = coeficients[i] + polynomial.coeficients[i];
	}
	
	for (int i = letterDegree + 1; i < greaterDegree + 1; i++)
	{
		sum.coeficients[i] = longerPoly->coeficients[i];
	}

	cout << "多项式加法将要返回……" << endl;
	return sum;
}

Polynomial Polynomial::operator * (const Polynomial &polynomial)
{
	// 计算乘积的最大阶
	int theMaxDegree = maxDegree + polynomial.maxDegree;
	Polynomial product(theMaxDegree + 1); // 积
	
	// 把初始化后product数组置零
	for (int i = 0; i < theMaxDegree + 1; i++)
		product.coeficients[i] = 0;

	// 计算多项式乘积
	for (int i = 0; i < maxDegree + 1; i++)
	{
		CoeficentType left = coeficients[i];
		for (int j = 0; j < polynomial.maxDegree + 1; j++)
		{
			CoeficentType right = polynomial.coeficients[j];
			
			product.coeficients[i + j] += left * right;
		}
	}

	return product;
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

