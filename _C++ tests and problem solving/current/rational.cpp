#include <iostream>
#include <cstdlib>		//for abs()

using namespace std;

/**************************************************************************************************
Rational type (rational.h)
Specification
store data in such formation: numerator / denominator. To ensure the accuracy of calculating
**************************************************************************************************/

class Rational
{
public:
	Rational();
	//	Default
	//	Postconditions:	initialized of 0 / 1.

	Rational(int numerator, int denominator);
	//	initialization by client
	//	Precondition:	denominator couldn't be 0.
	//	Postconditions:	initialized of numerator / denominator.

	void Add		(/* in */ Rational another);
	//	add the another rational number and assign itself the result.
	//	result is simplified.
	//	Postconditions:	they are added &&
	//					Reduction function is called to simplify the result.

	void Substruct	(/* in */ Rational another);
	//	substract the another rational number and assign itself the result.
	//	result is simplified.
	//	Postconditions:	result equals itself off another &&
	//					Reduction function is called to simplify the result.

	void Multiply	(/* in */ Rational another);
	//	multiply the another rational number and assign itself the result.
	//	result is simplified.
	//	Postconditions:	result equals itself multiplying another &&
	//					Reduction function is called to simplify the result.
	
	void Divide		(/* in */ Rational another);
	//	divide itself by the another rational number and assign itself the result.
	//	result is simplified.
	//	Postconditions:	result equals itself devided by another &&
	//					Reduction function is called to simplify the result.

	void Output();
	//  output the rational number.
	//	Postconditions:	the retional number is output in this form: XX/XX(XX represents a number).

private:
	int son;							//numerator
	int mum;							//denominator
	void Reduction(int son, int mum);	//simplify the fraction number
};

/**************************************************************************************************
Rational type (Rational.cpp)
Implementation
store data in such formation: numerator / denominator. To ensure the accuracy of calculating
**************************************************************************************************/

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
		mum1 = 0;
		son1 = 1;
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

//*************************************************************************************************
//Client codes
//*************************************************************************************************

int main()
{
	int son1, son2, mum1, mum2;
	cin >> son1 >> mum1 >> son2 >> mum2;

	//judge to assure the precondition
	if (!mum1 || ! mum2)
	{
		cout << "The denomination couldn't be 0..." << endl;
		return 1;
	}
	
	Rational num1(son1, mum1);
	Rational num2(son2, mum2);
	Rational num1I = num1;		//Initialization
	Rational num2I = num2;		//Initialization
	
	num1.Add(num2);
	num1.Output();
	cout << endl;
	num1 = num1I;				//restoration
	
	num1.Substruct(num2);
	num1.Output();
	cout << endl;
	num1 = num1I;				//restoration

	num1.Multiply(num2);
	num1.Output();
	cout << endl;
	num1 = num1I;				//restoration

	num1.Divide(num2);
	num1.Output();
	cout << endl;
	num1 = num1I;				//restoration

	return 0;
}