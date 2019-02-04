//*********************************************************************************************************************
//Drivers to test functions iteratively
//*********************************************************************************************************************

#include <iostream>
#include "declarations.h"

void main()
{
	/*
	//Driver for No.1
	int a, b;		//numbers for comparision
	do
	{
		std::cout << "Please input two innagetive numbers, seperated by space:" << std::endl
				  << "(numbers negative or alphabets or punctuations to terminate)" << std::endl;
		std::cin >> a >> b;
		if (std::cin && a >= 0 && b >= 0)
		{
			std::cout << "So the greatest common divisor is:  " << GCD(a, b) << std::endl << std::endl;
			std::cout << "So the greatest common divisor is:  " << GCD2(a, b) << std::endl << std::endl;
		}
	} while (std::cin && a >= 0 && b >= 0);
	
	std::cout << "Thank you for using!" << std::endl;
	*/

	//Driver for No.2
	int c;			//decimal number 
	do
	{
		std::cout << "Please input a positive decimal number:" << std::endl
				  << "(numbers negative or alphabets or punctuations to terminate)" << std::endl;
		std::cin >> c;
		if (std::cin && c >= 0)
		{
			std::cout << "Then the binary number corresponding to " << c << " is:" << std::endl;
			PrintDecToBin2(c);
			std::cout << std::endl << std::endl;
		}
	} while (std::cin && c >= 0);

	std::cout << "Thank you for using!" << std::endl;
}