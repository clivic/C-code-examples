#include <iostream>

using namespace std;

int Power(int x, int pow);		//function calculates x^pow

int main(int x,		
		 int pow)
{
	cout << "Please enter the power: ";
	cin >> pow;
	cout << "Please enter the value to be raised to the power: ";
	cin >> x;
	cout << Power(x, pow);
	return 0;
}

//*************************************************************************************************

int Power(int x, int pow)
{
	int result(1);
	for (; pow > 0; pow--)
	{
		result *= x;
	}
	return result;
}