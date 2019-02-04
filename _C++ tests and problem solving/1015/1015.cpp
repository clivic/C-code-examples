#include <iostream>

using namespace std;

void Output()
{
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j < n; j++)
		{
			cout << i * j << ' ';
		}
		cout << i * j << endl;
	}
}

int main()
{
	int n;	//number to input
	cin >> n;
	for (int count = 0; count < n; count++)
	{
		Output();
	}
	return 0;
}