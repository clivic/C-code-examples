/************************************************
This program is to output the stars, whose number
is determined by th user.
************************************************/
#include <iostream>

using namespace std;

void main()
{
	int i(1), num;
	cout << "This program is to output the "
		 << "stars, and the number of it is "
		 << "dependent on the number you've "
		 << "input." << endl;
	cout << "Please input the number of star."
		 << endl;
	cin >> num;

	while (i <= num)
	{
		cout << '*' ;
		i++;
	}
	cout << endl;
}
