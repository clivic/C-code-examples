//************************************************************
//This program is to test what if setprecision is set to zero.
//************************************************************
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	float a(9.93982);
	cout << fixed << setprecision(0) << a << endl;
}
//Conclusion: the float type value will be rounded off if 
//setprecision is set to zero.