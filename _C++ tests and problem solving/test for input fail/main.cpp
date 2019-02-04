/************************************************
This program is to test what if the input fails
resulted by invalid data.
************************************************/
#include <iostream>
#include <string>

using namespace std;
 
void main()
{
	int a(10), b(20), c(30);
	string ch;
	//Please input 1234.56 78 9
	cin >> a >> b >> ch;
	cout << a << endl
		 << b << endl
		 << ch << endl;
}