#include <iostream>

using namespace std;

int main()
{
	int count;			//how many numbers
	int current;		//current number
	while(cin >> count)
	{
		int sum(0);		//row sum and initialize
		for (int i(1); i <= count; i++)
		{
			cin >> current;
			sum += current;
		}
		cout << sum << endl;
	}
	return 0;
}