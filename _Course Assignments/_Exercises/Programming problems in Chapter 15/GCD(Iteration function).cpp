//*********************************************************************************************************************
//Greatest common divisor (Iteration function version), to compare with the Recursive one :)
//*********************************************************************************************************************
#include "declarations.h"

int GCD2(
	/* in */ int a,
	/* in */ int b)
	//	Calculate the greatest common divisor of two arguments using iterative method
	//	Preconditions:	a, b are positive (including 0)
	//	Postconditions:	return value is the greatest common divisor of a, b
{
	int min;				//minimum between a and b
	int max(1);				//greatest common divisor
	if (a - b > 0)
		min = b;
	else
		min = a;

	for (int i(2); i <= min; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			max = i;
		}
	}
	
	return max;
}