/**************************************************************************************************
This program tests the precendence mainly on unsined type and type itself.
**************************************************************************************************/

#include <iostream>

using namespace std;

void main()
{
	unsigned int a(15);
	a = a - 15;				//0		
	cout << a << endl;
	a = 15;					//reset
	a = a - 16;				//2 ^ 32 - 1
	cout << a << endl;
}

/*	Result:
	a is of type unsigned int, and 15 or 16 is of int, first a was substracted by them in normal 
	arithmatics( for 15, 16 are coerced to unsigned int type), then coerced again to unsigned int.
	so the result is above.																		*/