//*******************************************************************
//	test for the value of string::npos, we compare it with INT_MAX
//*******************************************************************
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void main()
{
	unsigned int a;
	string::size_type b;
	cout << (a = UINT_MAX) << endl; 
	cout << (b = string::npos) << endl;
	cout << "They are equal?\n";
	if (a == b)
		cout << "Y" << endl;
	else
		cout << "N" << endl;
}

//	Result:	string::npos == UINT_MAX
//	and string::size_type is almost equal to unsigned int, begins from 0