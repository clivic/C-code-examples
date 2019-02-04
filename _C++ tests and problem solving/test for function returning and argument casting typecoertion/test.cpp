/**************************************************************************************************
This program tests the trancation when storing long type variavles into short type one. 
**************************************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

short TestForReturn();				//for testing the type coertion of return
void TestForArgument(short n);		//for testing the type coertion of argument casting

void main()
{	
	int a;
	a = TestForReturn();
	cout << a << endl;
	TestForArgument(pow(2, 18));
}

//*************************************************************************************************

short TestForReturn()
{
	//just return a value
	return pow(2, 18);
}

//*************************************************************************************************

void TestForArgument(short n)
{
	//just cout a value
	cout << n << endl;
}

/*	Result:
	Both is comformed to the type precedence.
*/