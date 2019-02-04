// Chapter 15 6.cpp : 定义控制台应用程序的入口点。
//This progarm is to test the usage of recursion.

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>

using namespace std;

int F(int);

void main()
{
	int num;

	//Integrate loop input
	while (cin)
	{
		cout << "Please input the number:(alphabet or punctuation to terminate)" << endl;
		do
		{
			cin >> num;
			if (num < 0)
				cout << "number < 0, input again please:" << endl;
		} while (num < 0);
		cout << "F(number) is: " << F(num) << endl << endl;;
	}
}

int F(int a)
//Precondition:	num >= 0
{
	if (!a)
		return 1;
	else
		return F(a - 1) * 2;
}