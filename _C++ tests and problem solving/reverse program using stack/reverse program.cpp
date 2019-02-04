//*******************************************************************
//	This program gets an int n and n decimal numbers and print it in 
//	reverse order.
//*******************************************************************

#include "utility.h"

void main()
{	
	stack <double> s;
	int n;
	double num;
	
	do
	{	
		cout << "Please input the quantity of numbers: " << flush;
		cin >> n;
		cout << "Then enter the numbers: " << flush;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			s.push(num);
		}
		cout << endl << "The reverse order is:\n" << flush;

		while (!s.empty())
		{
			cout << s.top() << ' ';
			s.pop();
		}
		cout << endl << "Do you wanna continue?" << flush;
	} while (UserSayYes());
}