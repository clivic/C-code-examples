/************************************************
This program tests the availability of bool 
artithmatic expressions.
************************************************/

#include <iostream>

using namespace std;

void main()
{
	bool a = -1;
	bool b = 3;
	if (a)	cout << "a" << endl;
	if (b)	cout << "b" << endl;
	cout << a + b << endl;
}

//Result: 
//Haha, bool also can be involved in arithmatic 
//calculations perhaps! :)
//and a, b are both "true".