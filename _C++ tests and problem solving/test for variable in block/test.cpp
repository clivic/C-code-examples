/************************************************
This program is to test whether a variable 
declared in any block is irrelated to outer 
variable.
************************************************/

#include <iostream>
#include <string>

using namespace std;

void main()
{
	int c = 1;
	
	if (1)
	{
		int c = 2;
		cout << c << endl;
	}
	cout << c << endl;
	
	c = 1;
	while (c)
	{
		c = 3;	   //this c is outer c.
		//int c = 3; //this c is inner c!
		cout << c << endl;
		c = 0;
	}
}

/*Conclusion:
Ahhhhhhhhhhhhhhh!
variables declared in any block -- not only in 
function blocks but also in while or if and so on
... -- are all LOCAL VARIABLES!!!
Please remember:)*/

