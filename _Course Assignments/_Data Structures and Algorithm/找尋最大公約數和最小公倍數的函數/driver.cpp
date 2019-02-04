//*******************************************************************
//	Driver
//*******************************************************************
#include <iostream>
#include "CBaseDev.h"

using std::cin; using std::cout; using std::endl;

void main()
{
	int a, b;
	while (cin)
	{
		cout << "Please input two numbers:" << endl;
		cin >> a >> b;
		cout << "CdevidorI:	 " << CdevidorI(a, b) << endl;
		cout << "CdevidorR:  " << CdevidorR(a, b) << endl;
		cout << "CdevidorDI: " << CdevidorDI(a, b) << endl;
		cout << "CBaseD:	 " << CBaseD(a, b) << endl;
		cout << "CBaseI:	 " << CBaseI(a, b) << endl;
		cout << endl;
	}
}
