/************************************************
This program we cant find problem inwhile
the teacher say the answers are inobjective.
************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Part one: while loop
	int n;
	double result, modResult;
	cin >> n;
	//n = 1000; //new
	while (n != 0)
	{
		//Part teo: min spense.
		if (n < 4)
			result = 10; //Total money
		else if (n <=8)
			result = 10 + (n -4) * 2;
		else 
		{
			if ((n % 8) <= 4)
				modResult = 2.4 * (n % 8);
			else 
				modResult = 10 + 2 * (n % 8 - 4);
			result = (n / 8) * 18 + modResult;
		}

		cout << result << endl;
		cin >> n;
		//n--; //new
	}
}

