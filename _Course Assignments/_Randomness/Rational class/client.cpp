//*************************************************************************************************
//Client codes
//*************************************************************************************************
#include "rational.h"
#include <iostream>

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