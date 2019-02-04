#include <iostream>

using namespace std;

int main()
{
	int countN;		//numbers one row contains
	int countR;		//how many rows
	cin >> countR;	//read how many rows
	int sum;
	int current(0);	//later number
	
	//outer control
	for (int h(1); h <= countR; h++)
	{
		//in one row
		cin >> countN;	//read one row numbers
		
		sum = 0;		//initialize
		for (int i(1); i <= countN; i++)
		{				
			cin >> current;
			sum += current;
		}
		cout << sum << endl;
	}
		
	return 0;
}