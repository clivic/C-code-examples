//*****************************************************************************
//Driver:
//Test the functions.
//*****************************************************************************
#include <iostream>
#include "function definitions.h"

using namespace std;

void main()
{
	cout << "No.1" << endl;
	cout << DigitSum(12345) << endl;

	cout << endl << "No.2" << endl;
	cout << OneDigit(12345) << endl;

	cout << endl << "No.3" << endl;
	
	//initialization
	int data[50];
	for (int i(0); i < 50; i++)
	{
		data[i] = i + 1;
	}				
	cout << BinarySearch(35, data, 0, 50);

	cout << endl << "No.4" << endl;
	ReverseOutPut();
}
