//*******************************************************************
//	Client (b)
//	This client generate a magic square whose size is defined by user 
//*******************************************************************
#include "utility.h"
#include "MagicSquare.h"

int main()
{
	MagicSquare square;
	do
	{
		square.Generate();
		cout << "The magic square is: " << endl;
		square.Print();
		cout << endl << endl;
		cout << "\nContinue?" << flush;
	} while (UserSayYes());
}