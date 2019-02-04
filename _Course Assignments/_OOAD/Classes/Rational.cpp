/**************************************************************************************************
Rational type (Rational.cpp)
Implementation
store data in such formation: numerator / denominator. To ensure the accuracy of calculating
**************************************************************************************************/

#include "rational.h"
#include <iostream>
#include <cstdlib>		//for abs()

using namespace std;

//Private members:
//int son;							//numerator
//int mum;							//denominator
//void Reduction(int son, int mum);	//simplify the fraction number

Rational::Rational()
{
	son = 0;
	mum = 1;
}

//*************************************************************************************************

Rational::Rational(int numerator, int denominator)
{
	son = numerator;
	mum = denominator;
}

//*************************************************************************************************

void Rational::Add(/* in */ Rational another)
{
	int sonI;		//the not simplified numerator
	int mumI;		//the not simplified denominator

	mumI = mum * another.mum;
	son = son * another.mum;
	another.son = another.son * mum;
	sonI = son + another.son;
	Reduction(sonI, mumI);
}

//*************************************************************************************************

void Rational::Substruct(/* in */ Rational another)
{
	int sonI;		//the not simplified numerator
	int mumI;		//the not simplified denominator

	another.son *= -1;
	
	mumI = mum * another.mum;
	son = son * another.mum;
	another.son = another.son * mum;
	sonI = son + another.son;
	Reduction(sonI, mumI);
}

//*************************************************************************************************

void Rational::Multiply(/* in */ Rational another)
{
	int sonI;		//the not simplified numerator
	int mumI;		//the not simplified denominator

	sonI = son * another.son;
	mumI = mum * another.mum;
	Reduction(sonI, mumI);
}

//*************************************************************************************************

void Rational::Divide(/* in */ Rational another)
{
	int sonI;		//the not simplified numerator
	int mumI;		//the not simplified denominator
	int mid;		//for reverse the numerator and denominator
	
	//reverse
	mid = another.mum;
	another.mum = another.son;
	another.son = mid;

	//mutiply
	sonI = son * another.son;
	mumI = mum * another.mum;
	Reduction(sonI, mumI);
}

//*************************************************************************************************

void Rational::Output()
{
	cout << son << '/' << mum;
}

//*************************************************************************************************

void Rational::Reduction(int son1, int mum1)
{
	int min;				//min of two numbers

	if (son1 == 0)
	{
		son = mum1 = 0;
		mum = son1 = 1;
		return;
	}
	else if (abs(son1) > abs(mum1))
		min = abs(mum1);
	else 
		min = abs(son1);
	
	for (int i(2); i <= min; i++)
	{
		if (mum1 % i == 0 && son1 % i == 0)
		{
			mum1 /= i;
			son1 /= i;
			i = 1;
			//compare again
			if (son1 > mum1)
				min = mum1;
			else 
				min = son1;
		}
	}
	son = son1;
	mum = mum1;
}


