/**************************************************************************************************
This program is to test the switch sentence and
solve these questions:
1. Can there be a null switch statement?					Yes.
2. Can the case condtion to be a value not char?			Yes.	
3. Can it be preceded by more than 1 case label?			Yes.
4. Can two cases in one line correspond to one sentence?	No.
5. Can case condition be a variable?						No.
6. Can the expression in parentheses a float-point type?	No.
**************************************************************************************************/

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	//Q1
	cout << "Q1" << endl;
	cout << "Please enter the controlling letter:"
		 << endl;
	int control;
	cin >> control;
	switch (control);	//Null switch
	cout << endl << endl;

	//Others
	cout << "Others" << endl;
	switch (control)
	{
		case 1 : cout << "It's 1." << endl;
				 break;	//Q2
		case 2 :		//Q3
		case 3 : cout << "It's 2 or 3." << endl;
				 break;
		case islower('a') : cout << "Lower. " << endl;
		default: cout << "No matched." << endl;
		/*
		case 4, 5: cout << "It's 4 or 5." << endl;
				 break;	//Q4
		int a(6);		//a variable
		case a : cout << "It's a variable contains 6." << endl;
				 break;	//Q5
		*/
	}
	cout << endl << endl;

	//Q6
	/*
	cout << "Q6" << endl;
	switch (5.5);		//float-point type
	cout << endl;
	*/
	
	return 0;
}