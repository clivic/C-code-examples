/***************************************************************************************************************************************************
This program is to calculate the monthly payment for the mortgage of the house.
Written date: 9/30/2013
Operation list:getting the data, calculate, output(in fixed and 2-precision results).
***************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

const float LOAN_AMOUNT = 50000.00f;
const int NUMBER_OF_YEARS = 7;
const float INTEREST_RATE = 0.0524f; //Yearly interest

void main()
{
	int numberOfPayments = NUMBER_OF_YEARS * 12;
	float monthlyInterest = INTEREST_RATE / 12;
	cout << "With the remaining loan amount of $" << fixed << setprecision(2)
		<< LOAN_AMOUNT		
		<<" "<< "and the remaining " << NUMBER_OF_YEARS << " years"
		<<"\n"<<"with a yearly interest of " << setprecision(4) 
		<< INTEREST_RATE << " ,"<<"you will have to pay "<<"\n"<<'$'
		<<fixed<<setprecision(2)	
		<<LOAN_AMOUNT*pow((1+monthlyInterest),numberOfPayments)*monthlyInterest
		/(pow((1+monthlyInterest),numberOfPayments)-1)<<"\n"
		<<"per month."<<endl;
		

}
