//****************************************************************************
//Mortgage Payment Calculator program
//This program determines the montyly payments on a mortgage given
//the loan amount, the yearly interest rate, and the number of years.
//****************************************************************************

#include <fstream>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string filename;
	//Input variables
    float loanAmount;
    float yearlyInterest;
    int numberOfYears;
    ofstream outData;
    ifstream inData;

    //Local variables
    float monthlyInterest;
    int numberOfPayments;
    float payment;

    //Enter openfile
	cout << "Please enter the input file name : " << endl;
	cin >> filename;
	inData.open(filename.c_str());
    outData.open ("loan.out");

 	//Read values from the file
    inData>>loanAmount>>yearlyInterest>>numberOfYears;

    //Calculate values
    monthlyInterest = yearlyInterest/12;
    numberOfPayments = numberOfYears*12;

    payment = (loanAmount* 
                      pow(1+monthlyInterest , numberOfPayments)*monthlyInterest )
                      /(pow(1+monthlyInterest , numberOfPayments)-1);
    
    //Output results
    outData<<fixed <<setprecision(2)<<"For a loan amount of  "
               <<loanAmount
              <<"   with an interest rate  of  "<<setprecision(4)
              <<yearlyInterest  << "   and  a  " 
              <<numberOfYears<<"  year mortage,  "<<endl;
   outData<<fixed <<setprecision(2)
              <<"your monthly payments are $ "<<payment
              <<" . "  << endl;

   inData.close();
   outData.close();

   return 0;

}