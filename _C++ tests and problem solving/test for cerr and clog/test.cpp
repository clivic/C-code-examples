//***********************************************
//	This program tests for cerr and clog
//***********************************************

#include <iostream>	//header and derection should
					//be in one line
using namespace std;

void main()
{ 
	int a, b;
	std::clog << "Enter two numbers: ";
	std::cin >> a >> b;
	std::clog << "Sum of " << a << " and " << b << " is: "
		 << a + b << '\n';
}

//	Results:
//	clog could replace cout, and so does cerr.