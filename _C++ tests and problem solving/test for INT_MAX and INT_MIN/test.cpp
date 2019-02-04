/************************************************
This program is to test what values INT_MAX, 
INT_MIN and the max of string::size_type contain.
************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string::size_type a=pow(2,32)-1;
	cout << "The \"INT_MAX\" is: "
		 << INT_MAX << endl;
	cout << "The \"INT_MIN\" is: "
		 << INT_MIN << endl;
	cout << a << endl;
	return 0;
}
//The result is the INT_MAX == -INT_MIN == 2^31-1
//== 2147483647
//And the max of a string::size_type value 
//== pow(2,32)-1 == 4294967295