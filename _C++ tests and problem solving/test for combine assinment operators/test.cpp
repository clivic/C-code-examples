/************************************************
This program tests for /= -= %=
************************************************/

#include <iostream>

using namespace std;

void main()
{
	float a(3.0);
	a -= 2.0;
	cout << fixed << a << endl;
	a = 3.0;
	a /= 2.0;
	cout << a << endl;
	int b(3);
	b %= 2;
	cout << b << endl;
}

/*	Result: the literal number behind is always 
	the right operand of +, -, *, /.		
	and %= is als vailable for int				*/