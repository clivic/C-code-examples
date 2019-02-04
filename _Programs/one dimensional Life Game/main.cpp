#include "utility.h"
#include "life.h"

void instructions();

int main()	//one dimensional Life Game
/*	Pre:	user initial
	Post:	prints and inquire if continue
	Use:	class life and its methods initialize(), print(), update()
			functions instructions(), user_say_yes().					*/

{
	Life configuration;
	instructions();
	configuration.Initialize();
	configuration.Print();
	cout << "Continue viewing new generations?" << endl;
	while (UserSayYes())
	{
		configuration.Update();
		configuration.Print();
		cout << "Continue viewing new generations?" << endl;
	}
	return 0;
}

void instructions()
//	Pre:	none.
//	Post:	instructions of one-dimension life game has been output.
{
	cout << "Welcome to the One-Dimensional Life Game adapted from Conway's game of life.\n"
		<< "This game's size is " << MAXCOL << " cells in a row.\n"
		<< "Concrete rules please refer to the reference book on Page 43.\n" << flush;
}