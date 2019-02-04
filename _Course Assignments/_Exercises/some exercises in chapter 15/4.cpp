//No.4
#include <iostream>

using namespace std;

void ReverseOutPut()
//	Prompt user input values and output values each in one line in reverse order
//	Precondition:	numbers not alphabets or punctuations are input && the input number is positive
//	Postcondition:	prompt user to enter an int until enter 0 || negative numbers
//					then cout them in reverse order
{
	int n;			//the input value
	cout << "Enter positive number, 0 to end:  ";
	cin >> n;
	if (n > 0)
	{
		ReverseOutPut();
		cout << n << endl;
	}
		
}