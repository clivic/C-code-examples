#include <iostream>

using namespace std;

int Calculate(int, int, int);

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << Calculate(a, b, c) << endl;
	return 0;
}

//***********************************************

int Calculate(int a, int b, int c)
{

	for(int i = 2; ;i++)
	{
		if (i % a == 0 &&
			i % b == 0 &&
			i % c == 0 )
			return i;
	}
}
