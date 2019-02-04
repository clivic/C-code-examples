//*******************************************************************
//	Polynomial terms' implementation
//*******************************************************************
#include "Term.h"

Term::Term(/* in */ int exponent, /* in */ double scalar)
{
	degree = exponent;
	coefficient = scalar;
}