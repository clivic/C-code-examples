#include <iostream>
#include <string>

using namespace std;

void main()
{
	//No.4
	//This program is for inexperienced users.
	
	double num1, num2, num3;
	cout << "No.4" << endl << endl;
	cout << "This program is to calculate the "
		 << "average of three real numbers."
		 << endl << "Please enter three number,"
		 << " and after inputting each one, you"
		 << " should start a new line by using "
		 << "\"enter\" key." << endl;
	cin >> num1 >> num2 >> num3;
	cout << "Now for the input values: " << endl
		 << num1 << ' ' << num2 << ' ' << num3 
		 << endl << "The average of them is: "
		 << endl << (num1 + num2 + num3) / 3
		 << endl << endl << endl;

	//No.5
	//This program is for experienced users.

	cout << "No.4" << endl << endl;
	cout << "To calculate the "
		 << "average of three real numbers, "
		 << "please enter them in one line."
		 << endl;
	cin >> num1, num2, num3;
	cout << "Now for the input values: " << endl
		 << num1 << ' ' << num2 << ' ' << num3 
		 << endl << "The average of them is: "
		 << endl << (num1 + num2 + num3) / 3
		 << endl << endl << endl;
}