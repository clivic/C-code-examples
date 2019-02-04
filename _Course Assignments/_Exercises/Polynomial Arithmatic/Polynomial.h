//*******************************************************************
//	Polynomial class specification 
//	representing a polynomial expression with private inheritance 
//	of LinkedQueue
//*******************************************************************
#ifndef POLY
#define POLY
#include "Linked_Queue.h"
#include "Term.h"

class Polynomial: private Queue <Term>
{
public:
	void Read();
	void Print() const;
	void SumPoly(/* in */ Polynomial p, /* in */ Polynomial q);
	void DifferencePoly(/* in */ Polynomial p, /* in */ Polynomial q);
	void ProductPoly(/* in */ Polynomial p, /* in */ Polynomial q);
	int Degree() const;
private:
	void MultiTerm(/* in */ Polynomial p, /* in */ Term t);
};


#endif