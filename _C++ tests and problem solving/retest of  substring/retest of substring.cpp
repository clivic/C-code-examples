//***********************************************
//This program retests the substr() function,
//to find out what if the length argument is < 0.
//***********************************************

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string str("Hello world!");
	cout << str.substr(0,-5) << endl;
}

//Result:
//	its complement representation is its 
//	actual length.