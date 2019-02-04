//*********************************************************************************************************************
//Greatest common divisor (Recursive function version), indeed its algorithm is not designed by myself but on thebook,
//while it is indeed terrific! :)
//*********************************************************************************************************************
#include "declarations.h"

int GCD(
	/* in */ int a,
	/* in */ int b)
	//	Calculate the greatest common divisor of two arguments using recursive function method
	//	Preconditions:	a, b are positive (including 0)
	//	Postconditions:	return value is the greatest common divisor of a, b
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}