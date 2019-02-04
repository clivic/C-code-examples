#include <iostream>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;	//positive interger number
	int min;		//min between m && n
	int result;
	switch(m > n)
	{
		case (true) :	min = n;	break;
		case (false):	min = m;	break;
	}
	for (int i(1); i <= min; i++)
	{
		if (m % i == 0 && n % i == 0)
		{
			result = i;
		}
	}
	cout << result << endl;
	return 0;
}