//*********************************************************************************************************************
//Convert decimal number to binary numbers
//*********************************************************************************************************************

#include <iostream>

void PrintDecToBin(/* in */ int n)
//	convert decimal number to binary number in recursive method
//	Preconditions:	n is positive
//	Postconditions:	binary number corresponding to n is output
{
	if (n / 2 == 0)
		std::cout << n % 2;
	else
	{
		PrintDecToBin(n / 2);
		std::cout << n % 2;
	}
}

//*Another simpler virsion: please see TESTCODE in Chapter 15 by LiPing Wang

