//*******************************************************************
//	This program tests if it will be a problem when double is coerced 
//	into int.
//*******************************************************************

#include <iostream>

using namespace std;

void main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << a << b << c << d << e << '\n' << flush;
	if (cin)
		cout << "oyeah" << endl;
	else
		cout << "not optimistic\n" << flush;
}

//	Result:
//	There is a failure when double in int and char in int 
//	perhaps