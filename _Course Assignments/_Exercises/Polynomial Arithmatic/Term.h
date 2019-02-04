//*******************************************************************
//	This is the specification of Term.h which means every "member" in
//	a polynomial.
//*******************************************************************
#ifndef TERM
#define TERM

//#include "Polynomial.h"

struct Term
{
	//only public to Polynomial class
	//friend Polynomial;

	//data in a term
	int degree;
	double coefficient;
	Term(/* in */ int exponent = 0, /* in */ double scalar = 0);
};

#endif