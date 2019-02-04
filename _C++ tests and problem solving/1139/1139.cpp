#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a;
	cin.ignore(1, '\n');
	cin >> b;
	cin.ignore(1, '\n');
	cin >> c;
	
	if (a > b)
		if (a > c)
			cout << "max=" << a << endl;
		else 
			cout << "max=" << c << endl;
	else if (c > b)
		cout << "max=" << c << endl;
	else
		cout << "max=" << b << endl;
	return 0;
}