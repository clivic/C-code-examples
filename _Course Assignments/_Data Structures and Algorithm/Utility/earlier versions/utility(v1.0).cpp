#include "utility.h"

bool UserSayYes()
//	Pre:	none.
//	Post:	return true if user input 'y' or 'Y', either 'n' or 'N' false.
{
	char answer;
	cout << "(y/n)? " << flush;
	cin >> answer;
	answer = tolower(answer);
	while (answer != 'y' && answer != 'n')
	{
		cout << "Respond with either y or n: " << flush;
		cin >> answer;
	}

	return (answer == 'y');
}

template <class Type>
void Cin(/* inout */ Type& input)
//	Pre:	the object for cin should support "cin operation".
//	Post:	cin a number && IF cin breaks down,
//			prompt user to re-enter the object && clear the cin.	
//	Note:	for template, should include utility.cpp.
{
	cin >> input;
	//prevent the case of not number
	while (!cin)
	{
		cout << "Invalid input, please input again: " << flush;
		cin.clear();
		cin.sync();
		cin >> input;
	}
}