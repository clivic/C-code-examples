/**************************************************************************************************
This program tests the trancation when storing long type variavles into short type one. 
**************************************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

void main()
{
	long a = pow(2, 18);
	short b = a;
	cout << b << endl;
}

//	Result:
//	It indeed trancates the leftmost digits in binary code.