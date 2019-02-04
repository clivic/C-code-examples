//*******************************************************************
//	Polynomial class implementation
//*******************************************************************
#include "Polynomial.h"
#include "utility.h"

void Polynomial::Read()
//	Post:	The Polynomial is read from cin.
{
	Clear();
	double coefficient;
	int lastDegree, degree;
	bool isFirst = true;
	cout << "Enter the coefficients and exponents for the polynomial, according to the prompts," << endl
		<< "Exponents(>=0) should be in descending order." << endl
		<< "Enter a coefficient of 0 or an exponent of 0 to terminate." << endl;
	do
	{
		cout << "Coefficient? " << flush;
		Cin(coefficient);
		if (coefficient != 0.0)
		{
			cout << "Exponent? " << flush;
			Cin(degree);
			if (!isFirst && lastDegree <= degree || degree < 0)
			{
				degree = 0;
				cout << "Bad exponent: Polynomial terminates without its last term."
					<< endl;
			}
			else
			{
				Term temp(degree, coefficient);
				Append(temp);
				isFirst = false;
			}
			lastDegree = degree;
		}
	} while (coefficient != 0.0 && degree != 0);
}

void Polynomial::Print() const
//	Pre:	degree >= 0
//	Post:	The Polynomial is printed to cout
{
	Node<Term> *printN = front;
	bool isFirst = true;
	while (printN != NULL)
	{
		Term term = printN->entry;

		//cout the sign
		if (isFirst)
		{
			if (term.coefficient < 0)	cout << "- ";
			isFirst = false;
		}
		else if (term.coefficient < 0)	cout << " - ";
		else cout << " + ";
		double c = fabs(term.coefficient);
		if(c != 1)	cout << c;
		if (term.degree > 1)	cout << "x^" << term.degree;
		else if (term.degree == 1) cout << "x";
		else if(term.degree == 0 && c == 1) cout << "1";
		printN = printN->next;
	}
	if (isFirst == true)
		cout << "0";			//case for empty
	cout << endl;
}

void Polynomial::SumPoly(/* in */ Polynomial p, /* in */ Polynomial q)
//	Post:	The Polynomial object is reset as the sum of the two parameters
{
	Clear();
	Term pTemp, qTemp;
	while (!p.Empty() || !q.Empty())
	{	
		if (p.Degree() > q.Degree())
		{
			p.ServeAndRetrieve(pTemp);
			Append(pTemp);
		}

		else if (q.Degree() > p.Degree())
		{
			q.ServeAndRetrieve(qTemp);
			Append(qTemp);
		}

		else
		{
			p.ServeAndRetrieve(pTemp);
			q.ServeAndRetrieve(qTemp);
			double newScalar = pTemp.coefficient + qTemp.coefficient;
			if (newScalar != 0.0)
			{
				Term newTemp(pTemp.degree, newScalar);
				Append(newTemp);
			}
		}
	}
}

void Polynomial::DifferencePoly(/* in */ Polynomial p, /* in */ Polynomial q)
//	Post:	The Polynomial object is reset as the difference of the two parameters
//			p - q
{
	//q to -q
	Node<Term> *qNode = q.front;
	Polynomial qMinus;
	while (qNode != NULL)
	{
		Term temp = qNode->entry;
		temp.coefficient = -temp.coefficient;
		qMinus.Append(temp);
		qNode = qNode->next;
	}
	SumPoly(p, qMinus);
}

void Polynomial::ProductPoly(/* in */ Polynomial p, /* in */ Polynomial q)
//	Post:	The Polynomial object is reset as the production of the two parameters
{
	Clear();
	Polynomial tempPoly;
	Node<Term> *pNode = q.front;
	while (pNode != NULL)
	{
		Term tempNode = pNode->entry;
		tempPoly.MultiTerm(p, tempNode);
		SumPoly(tempPoly, *this);
		pNode = pNode->next;
	}
}

void Polynomial::MultiTerm(/* in */ Polynomial p, /* in */ Term t)
//	Post:	The Polynomial object is reset as the production of the two parameters
//	Note:	this function is a poly multi one term, not another poly
{
	Clear();
	while (!p.Empty())
	{
		Term answer;
		p.ServeAndRetrieve(answer);
		Term tTemp(answer.degree + t.degree, answer.coefficient * t.coefficient);
		if (answer.coefficient != 0.0)	Append(tTemp);
	}
}

int Polynomial::Degree() const
//	Post:	If the Polynomial is identically 0, a result of - 1 is returned.
//			Otherwise the degree of the Polynomial is returned.
{
	
	if (Empty())	return -1;
	else
	{
		Term highest;
		Retrieve(highest);
		return highest.degree;
	}
}