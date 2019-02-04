#include <iostream>
#include <sstream>
#include <string>

void PrintDecToBin2(/* in */ int n)
//	convert decimal number to binary number in iterative method
//	Preconditions:	n is positive
//	Postconditions:	binary number corresponding to n is output
{
	bool flag(true);
	std::ostringstream ReverseStr;
	while (flag)
	{
		if (n / 2 == 0)
		{
			ReverseStr << n % 2;
			flag = false;
		}
		else
		{
			ReverseStr << n % 2;
			n /= 2;
		}
	}
	std::string str = ReverseStr.str();
	for (int i(str.length() - 1); i >= 0 ; i--)
	{
		std::cout << str[i];
	}
}