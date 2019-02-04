#include <iostream>

using namespace std;

int main()
{
	int a, b, c, median;
	
	cin >> a >> b >> c;
	
	if (a > b)
	{
		median = a;
		a = b;
		b =median;
	}
	if (b > c)
	{
		median = b;
		b = c;
		c =median;
	}
	if (a > b)
	{
		median = a;
		a = b;
		b =median;
	}
	if (b > c)
	{
		median = b;
		b = c;
		c =median;
	}

		
	cout << a << ' ' << b << ' ' << c << endl;
}