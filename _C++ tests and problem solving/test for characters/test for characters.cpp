/**************************************************************************************************
This program tests characters like '\f', '\v' and explore their uses.
And we also test about \ddd and \xddd.
By the way we will try to find out if the notation 53100I, 6.83D is available.
**************************************************************************************************/

#include <iostream>

using namespace std;

void main()
{
	int int1 = 1;		
	float float1 = 3.0;
	
	//to find out what's Form Feed	
	char formFeed = 12;			
	cout << '\f' << int1 << endl;
	cout << formFeed << endl;		//Tis a  ...
	
	//to find out what's Vertical Tab
	cout << '\v' << int1 << endl;	//Tis a  ...
	
	//to find out \ddd and \xddd
	cout << '\x07e' << '\173' << endl;

	//to check these notation
	//in1 = 53100i;
	//float1 = 6.83D;
	
	//Result: these notations are not valid.

}