// Recursive power function.cpp : �������̨Ӧ�ó������ڵ㡣
// �@����ʽ�������纯���Ĝyԇ���K�������A���g�^

#include "stdafx.h"
#include <iostream>
//#include <iomanip>			//set precision but now needn't

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

double Power(double x, int n)

//  Precondition:	n >= 0 && x is not zero when n <= 0.
//  Postcondition:	Function value == x raised to the power n.
{
	if (n == 0)
		return  1.0;	
	else if (n > 0)
		return (x * Power(x, n - 1));
	else
	{
		double deno;			//denominator
		n = -n;
		deno = x * Power(x, n - 1);
		return (1.0 / deno);
	}
}

void main()
{
	cout << Power(2.0, -5) << endl;
}
