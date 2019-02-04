/*******************************************************************************************************************************************
Mortgage Payment Calculator program
This program determines the monthly payment according to prestored loan amount, number of years, and the yearly interest rate.
(This program uses the file i/oput.
*******************************************************************************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void main()
{
	ifstream fin;
	ofstream fout;
	float loanAmount, numberOfYears, interestRate;

	fin.open("loan.txt");
	fout.open("result.out");

	fin >> loanAmount >> numberOfYears >> interestRate; //Yearly interest
	int numberOfPayments = numberOfYears * 12;
	float monthlyInterest = interestRate / 12;
	float payment = loanAmount*pow((1+monthlyInterest),numberOfPayments)
					*monthlyInterest/(pow((1+monthlyInterest),numberOfPayments)-1);
	fout << "With the remaining loan amount of $" << fixed << setprecision(2)
		<< loanAmount << " "<< "and the remaining " << numberOfYears << " years"
		<< "\n"<<"with a yearly interest of " << setprecision(4) 
		<< interestRate << " ," << "you will have to pay " << "\n" << '$'
		<< fixed<<setprecision(2) << payment << "\n" << "per month." << endl;
	cout << "The monthly payment has been output successfully!" << endl;
	fin.close();
	fout.close();
}
