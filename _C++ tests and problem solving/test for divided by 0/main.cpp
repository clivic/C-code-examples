/************************************************
This program is to test what consequence a num o-
ver an identifier contains 0 will cause.
************************************************/

#include <iostream>

using namespace std;

void main()
{
	int num(0);
	cout << 9 / num;
}
//The result is:
//If we divide a number!=0 by 0, we will not pass
//the compilation.
//If we divide a number!=0 by identifier equals 0
//the program will bog down 
//in a buglike termination.