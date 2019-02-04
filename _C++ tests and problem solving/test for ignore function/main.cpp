#include <iostream>
#include <string>

using namespace std;

void main()
{
	int a,b,c,d;
	cout << "please enter num#num#num#num, each num is for 3 digits." << endl;
	cin >> a;
	cin.ignore(1,'#');
	cin >> b;
	cin.ignore(1,'#');
	cin >> c;
	cin.ignore(1,'#');
	cin >> d;
	cout << a << endl << b << endl << c << endl << d << endl;
}