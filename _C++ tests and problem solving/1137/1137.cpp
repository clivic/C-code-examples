#include <iostream>

using namespace std;

int main()
{
	int a, b, max;
	cin >> a;
	cin.ignore(1, '\n');
	cin >> b;
	max = a > b ? a : b;
	cout << "max=" << max << endl;
	return 0;
}