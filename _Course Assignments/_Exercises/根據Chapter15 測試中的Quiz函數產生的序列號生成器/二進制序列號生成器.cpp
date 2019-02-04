//*****************************************************************************
//According to the Quiz() in Chapter 15 test, I catch up with the idea of 
//generating a series number, it cold be a pretty good idea perhaps :)
//*****************************************************************************

#include <iostream>

using namespace std;

//series number generator function
void Quiz( /* in */ int n)
{
	if (n > 0)
	{
		cout << 0;
		Quiz(n - 1);
		cout << 1;
		Quiz(n - 1);
	}
}

void main()
{
	int n;
	do
	{
		cout << "Please input a number which > 0(alphabet or punctuation to terminate):" << endl;
		cin >> n;
		if (n <= 0)
		{
			cout << "invalid input" << ", please input again." << endl;
		}
		else if (n > 0)
		{
			cout << "Series number for " << n << " is ";
			Quiz(n);
			cout << endl << endl;
		}
		else if (!cin)
			break;
	} while (cin);
	cout << "Thank you for using!" << endl;
}