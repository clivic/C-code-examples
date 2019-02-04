//*************************************************************************************************
// test: the return value being left of the assignment
//*************************************************************************************************

#include <iostream>

using namespace std;

int value[10];				
 
int& Pos(/* in */ int val)		//position of array
{
	if (val <= 9 && val >= 0)
	{
		return value[val];
	}
	else
	{
		cout << "Improper" << endl;
		return -1;
	}
}

void main()
{
	Pos(0) = 9;
	Pos(9) = 0;
	Pos(-11) = 2;
	cout << value[0] << endl
		 << value[9] << endl;
}