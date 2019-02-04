#include <iostream>

using namespace std;

void DisplayMessage(int);

void main()
{
	int index;
	cout << "Please input pollution index." << endl;
	cin >> index;
	DisplayMessage(index);
}

void DisplayMessage(int n)
{
	if (n < 0)
		cout << "improper data" << endl;
	else if (n < 35)
		cout << "The air condition is pleasant." << endl;
	else if (n <= 60)
		cout << "The air condition is unpleasant." << endl;
	else 
		cout << "The air condition is a health hazard."
			 << endl;
}