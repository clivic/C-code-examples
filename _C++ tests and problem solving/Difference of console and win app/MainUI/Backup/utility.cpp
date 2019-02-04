#include  "utility.h"

bool UserSayYes()
//	Pre:	none.
//	Post:	return true if user input 'y' or 'Y', either 'n' or 'N' false.
{
	char answer;
	cout << "(y/n)? " << flush;
	cin >> answer;
	answer = tolower(answer);
	while (answer != 'y' &&answer != 'n')
	{
		cout << "Respond with either y or n: " << flush;
		cin >> answer;
	}

	return (answer == 'y');
}
