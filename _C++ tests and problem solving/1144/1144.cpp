#include <iostream>

using namespace std;

int main()
{
	long n, i(3);
	bool state;
	cin >> n; //3 <= n <= 10000
	if (!(n % 2) && n != 2)
		cout << "not prime" << endl;
	else if (n == 2)
		cout << "prime" << endl;
	else 
	{
		while (i < n)
		{
			if (n % i == 0)
			{
				cout << "not prime" << endl;
				return 0;
			}
			else
				i = i + 2;
		} 
		cout << "prime" << endl;
	}
	return 0;
}


