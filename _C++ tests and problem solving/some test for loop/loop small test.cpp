//***********************************************
//loop small test
//***********************************************

#include <iostream>

using namespace std;

void main()
{
	int count = 1;
	int innerCount = 1;
	while (count <= 11)
	{
		innerCount = 1;
		while (innerCount <= (12 - count) / 2)
		{
			cout << ' ';
			innerCount++;
		}
		innerCount = 1;
		while (innerCount <= count)
		{
			cout << '@';
			innerCount++;
		}
		cout << '\n';
		count++;
	}
}

