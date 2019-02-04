//***********************************************
//	test for truncating negativee float to int 
//***********************************************
#include <iostream>

using namespace std;

void main()
{
	float a = -35.76;
	cout << (int)a << endl;
}

//	Result:
//	On this computer, the result is -35, still 
//	truncated as normal. :)