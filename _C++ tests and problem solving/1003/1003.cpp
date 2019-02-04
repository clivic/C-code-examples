#include <iostream>

using namespace std;

int main()
{
	int count;	
	cin >> count;	//read one row numbers
	int sum;
	int current(0);	//later number
	while (count != 0)
	{
		sum = 0;	//initialize
		for (int i(1); i <= count; i++)
		{				
			cin >> current;
			sum += current;
		}
		cout << sum << endl;
		cin >> count;
	}
	return 0;
}