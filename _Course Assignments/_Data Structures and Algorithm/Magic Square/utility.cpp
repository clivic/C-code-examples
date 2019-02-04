//*******************************************************************
//	Utility cpp
//	this cpp is mating with utility.h and implements the functions 
//	in it like UserSayYes()
//*******************************************************************

#include "utility.h"

bool UserSayYes()
//	Pre:	none.
//	Post:	if enter "y" or "Y", return 1, if enter "n" or "N", 
//			return 0, otherwise, input again
//	Use:	prompt user to answer yes or no.
{
	char answer;
	bool initialResponse = true;
	do				//loop until a proper answer
	{
		if (initialResponse)
			cout << "(y,n)? " << flush;
		else
			cout << "Respond with either y or n: " << flush;
		cin >> answer;
		initialResponse = false;
	} while (!(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N'));
	return (answer == 'y' || answer == 'Y');
}