//*************************************************************************************************
//this program tests how to use str.erase(pos, length)
//*************************************************************************************************
#include <iostream>
#include <string>

using namespace std;

void main()
{
	string hello = "hello";
	hello.erase(3,2);
	cout << hello << endl;
}

//Results: void str.erase(pos, num); 	//erase the chars for position pos and remove num chars.