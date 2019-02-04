/*******************************************************************************************************************************************
This is a test to confirm whether we can dim two distinct valuable while in one identical identifier in two different functions.
*******************************************************************************************************************************************/ 

#include <iostream>
#include <iomanip>//seem no use in this cpp ... perhaps just to remember the name of iomanip
#include <string>

using namespace std;

float Function(int);

float Function(int n)
{
	float a = 15.5;
	return float(a*n*n);
}
void main()
{   
	int a =5;
	cout<<float(a*Function(5))<<endl;
}

//the results turn to the availablity of it.