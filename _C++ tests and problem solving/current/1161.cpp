#include <iostream>

using namespace std;

int main()
{
	int a, n;
	cin >> a >> n;
	a %= (n %= 2);
	cout << a << endl;
	return 0;
}