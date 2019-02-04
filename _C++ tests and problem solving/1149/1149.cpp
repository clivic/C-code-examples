#include <iostream>

using namespace std;

int main()
{
	int i, j;
	bool isEven(0);
	for (i = 100; i < 200; i++)
	{
		isEven = 0;
		for (j = 2; j < i; j++)
		{
			
			if (i % j == 0)
			{
				isEven = 1;
				break;
			}
		}
		if (!isEven)
			cout << i << endl;
	}

	return 0;
}