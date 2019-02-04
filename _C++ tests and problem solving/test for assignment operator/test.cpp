/************************************************
test for assignment operator
this program tests the combination rule of 
the assignment operator
************************************************/

#include <iostream>

using namespace std;

void main()
{
	int i, j;
	i = j = 10;
	cout << i << ' ' << j << endl;

	(i = 10) = 100;
	cout << i << endl;
}

//	Result: 10 10 100
//	combined from right to left
//	and an assingment operation's return value
//	perhaps is a reference of the left variable:)