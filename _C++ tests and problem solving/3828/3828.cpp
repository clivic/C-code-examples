#include <iostream>

using namespace std;

int main()
{
	int a, b, c, min;
	cin >> a >> b >> c;

	//compare
	min = a;
	if (b < min)
		min = b;
	else if (c < min)
		min = c;

	//output
	cout << min << endl;

	return 0;
}