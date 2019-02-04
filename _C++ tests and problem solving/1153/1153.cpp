#include <iostream>
#include <cmath>

using namespace std;

int i = 0;

int ConvOct(int n)
{
	
	if (n / 8 == 0)
	{
		return (n % 8) * pow(10, i);
		i = 0;		//restore i
	}
	else
	{
		i += 1;
		return (n % 8) * pow(10, i - 1) + ConvOct(n / 8);
		
	}
	
}

int main()
{
	int n;
	while(cin >> n)
	{
		cout << ConvOct(n) << endl;
	}
	return 0;
}