/************************************************
This program is to test how an assert function 
works.
************************************************/

#include <cassert>
#include <iostream>

using namespace std;

void main()
{
	double num1, num2, result;
	cout << "Please input two numbers, "
		 << "and we output the result of the "
		 << "second devided by the first."
		 << endl
		 << "And you're supposed to input them "
		 << "in one line." << endl;
	cin >> num1 >> num2;
	assert(num2 != 0);
	result = num1 / num2;
	cout << "Then the result is: " << result 
		 << "." << endl;
}
//Then wo made the second number equal to 0,
//and see what it will happen.

/*Result: it reports that:
Assertion failed: num2 != 0, file D:\Visual C++ 
programs\test for assert function\test for 
assert fuction.cpp, line 21.
So the line refers to the assert function call.
And it will abnormally terminate the program
on this compuuter at least.

And also, the #define NDEBUG could either be put 
in the next line of #include <cassert> or in the
last line of it. It will ignore assert function.*/