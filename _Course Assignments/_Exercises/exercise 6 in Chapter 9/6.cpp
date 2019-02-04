#include <iostream>

using namespace std;

int main()
{
	char answer;	
	do
	{
		cout << "Please input yes or no, "
			 << "represented by \"Y\" or \"N\"."
		     << endl;
	
		cin >> answer;
		if (answer != 'Y' && answer != 'N')
		{
			cout << "Input is invalid perhaps."
				 << endl;
		}
	} while (answer != 'Y' && answer != 'N');
	cout << "You've input: " << answer << endl;
	return 0;
}

//	!Skill perhaps: using if (after cin) 
//	to issue "error message" in do-while loop. :)

	

