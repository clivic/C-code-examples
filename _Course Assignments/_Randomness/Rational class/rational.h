/**************************************************************************************************
Rational type (rational.h)
Specification
store data in such formation: numerator / denominator. To ensure the accuracy of calculating
**************************************************************************************************/

#include <iostream>

using namespace std;

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
	//					meanwhile only numerator has its sign information.

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