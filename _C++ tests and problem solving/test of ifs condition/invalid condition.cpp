/****************************************************
This program is intended to test if the if consition 
contains invalid expression, what will happen.
****************************************************/

#include <iostream>
#include <string>

using namespace std;

void main()
{
	int x(5);
	if (x < 1 / 0)
	{
		cout << "You are in if condition." << endl;
	}
	else
	{ 
		cout << "You are in else condition." << endl;
	}
}

/*Conclusion: It seems that the program will not exe-
cuted for the improper expression in if condition.*/