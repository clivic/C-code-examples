/*************************************************************************************************
This program tests the typedef array's type coercion.
*************************************************************************************************/

#include <iostream>

using namespace std;

typedef int Week[7];

void print(/* in */ Week arr); 

void main()
{
	Week type[2] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5}; 
	print(1);
}

//*************************************************************************************************

void print(/* in */ Week arr)
{
	for (int i(0); i < 7; i++)
		cout << '#' << i + 1 << ' ' << arr[i] << endl;
}

//Result:	type coercion is not allowed.	