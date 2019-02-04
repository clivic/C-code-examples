#include <iostream>

using namespace std;

bool Judge(int n);

int main()
{
	int n;
	cin >> n;

	//sentinel
	while (n >= 0)
	{	
		//judge 0
		if (n == 0)
			cout << "NO" << endl;
		else if (Judge(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		cin >> n;
	}
	return 0;
}

//***********************************************

bool Judge(int n)
{
	int count(1);
	int i(1);
	int num[11];
	int large = 11;
	int biggest;
	num[0] = 1;

	//num[n] == n!
	for (;i < 11; i++)
	{
		num[i] = num[i - 1] * count;
		count++;
	}
	for (i = 1; i <= large; i++)
	{
		if (num[i] > n)
		{
			biggest = num[i - 1];
			large = i - 1;
			n -= biggest;
			i = 0;
		}
	}

	if (n != -1)
		return 0;
	else 
		return 1;
}


		
