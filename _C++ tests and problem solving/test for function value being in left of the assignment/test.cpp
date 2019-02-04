//*************************************************************************************************
// test: the return value being left of the assignment
//*************************************************************************************************

#include <iostream>

using namespace std;

int value[10];
int improper(-1);				//could only be global variable perhaps				
 
int& Pos(/* in */ int val = 0)		//position of array
{
	if (val <= 9 && val >= 0)
	{
		return value[val];
	}
	else
	{
		cout << "Improper" << endl;
		return improper;
	}
}

void main()
{
	Pos() = 9;
	Pos(9) = 0;
	Pos(-11) = 2;
	cout << value[0] << endl
		 << value[3] << endl
		 << value[9] << endl
		 << improper << endl;
}