/************************************************
This program is to output the day corresponding 
to the number entered.
************************************************/

#include <iostream>

using namespace std;

void main()
{
	cout << "This program is to output the day "
		 << "corresponding to the number entered."
		 << endl;
	cout << "Please enter a number within 1 and"
		 << " 7: " << endl;
	int num;
	cin >> num;
	if (num > 7 || num < 1)
		cout << "The invalid input." << endl;
	else if (num == 1)
		cout << "The day is Monday." << endl;
	else if (num == 2)
		cout << "The day is Tuesday." << endl;
	else if (num == 3)
		cout << "The day is Wednesday." << endl;
	else if (num == 4)
		cout << "The day is Thursday." << endl;
	else if (num == 5)
		cout << "The day is Friday." << endl;
	else if (num == 6)
		cout << "The day is Saturday." << endl;
	else //if (num == 7)
		cout << "The day is Sunday." << endl;
}
//WARNING: = doesn't equal to == !