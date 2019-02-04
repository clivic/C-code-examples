#include "life.h"
#include "utility.h"

void Life::Initialize()
//	Pre:	none
//	Post:	configuration is defined by user.	
{
	int i;		//for count only
	int n;		//the cell user specify
	for (i=0; i < MAXCOL + 4; i++)
		grid[i] = 0;

	cout << "Please list living cells.\n";
	cout << "Terminate the list with the special number -1.\n" << flush;
	cin >> n;
	
	while (n != -1)
	{
		if (n >= 1 && n <= MAXCOL)
			grid[n + 1] = 1;
		else
			cout << "Column is out of range.\n" << flush;
		cin >> n;
	}
}

//*****************************************************************************

void Life::Print()
//	Pre:	the Life object contains a configuration defined by user.
//	Post:	it is printed according to the rule.						
{
	int i;		//for count only
	cout << "\nThe current Life configuration is:" << endl;
	for (i = 2; i <= MAXCOL + 1; i++)
	{
		if (grid[i] == 1)
			cout << '*';
		else
			cout << '_';
	}
	cout << endl;
}

//*****************************************************************************

void Life::Update()
//	Pre:	the Life object contains a configuration defined by user.
//	Post:	configuration is the next generation.
{
	int i;		//for count only
	int newGrid[MAXCOL + 4];
	for (i = 2; i <= MAXCOL + 1; i++)
	{
		switch (NeighborCount(i))
		{
		case 2:
			newGrid[i] = 1;	break;			//alive
		case 3:					
			switch (grid[i])				//reverse
			{
			case 0:
				newGrid[i] = 1;	break;
			case 1:
				newGrid[i] = 0; break;
			}
			break;
		case 4:
			newGrid[i] = grid[i]; break;	//stay
		default:
			newGrid[i] = 0;	 break;
		}
	}
	for (i = 2; i <= MAXCOL + 1; i++)
		grid[i] = newGrid[i];				//overwrite
}

//*******************************************************************

int Life::NeighborCount(/* in */ int n)
//	Pre:	the Life object contains a configuration defined by user
//			&& the given cell is in the range of [2, MAXCOL + 1].
//	Post:	return the number of live neibors around the cell given.
{
	int i;		//for count the four neibors
	int num = 0;
	for (i = n - 2; i <= n + 2; i++)
	{
		num += grid[i];
	}
	num -= grid[n];
	return num;
}
