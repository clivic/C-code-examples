//No.1
#include <iostream>

using namespace std;

int Summation(/* in */ int n)
//	Calculate summation of 1 .. n
//	Precondition:	n is positive
//	Postcondition:	return summation of them using recursion method
{
	if (n == 1)
		return 1;
	else
		return n + Summation(n - 1);
}

int DigitSum(/* in */ int n)
//	Caculate the sum of the digits in the argument number
//	Precondition:	n is positive
//	Postcondition:	return summation of the digits
{
	if (n / 10 == 0)	//judge if single digit
		return n;
	else
		return n % 10 + DigitSum(n / 10);
}

