/************************************************
This program tests for the availibility of a null
for statement.
************************************************/

#include <iostream>

using namespace std;

int main()
{
	for(;;)		//null for 
	{
		cout << "executed." << endl;
	}
	return 0;
}

//result: a null for statement seems always true,
//so it perhaps is an infinite loop.