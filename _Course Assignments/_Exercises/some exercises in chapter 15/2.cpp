//No.2
#include <iostream>
#include "function definitions.h"

using namespace std;

int OneDigit(/* in */ int n)
//	Caculate the sum of the digits of n, and if their sum > 10, resummate them untio a single digit
//	Precondition:	n is positive
//	Postcondition:	return a ultimate sum of digits including the previous sum
{
	if (n < 10)
		return n;
	else
		return OneDigit(DigitSum(n));
}