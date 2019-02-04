//*******************************************************************
//	The implementation of class MagicSquare
//*******************************************************************
#include "MagicSquare.h"
#include "utility.h"
MagicSquare::MagicSquare()
//	Pre:	none
//	Post:	initialize the magic square with every cell being 0
{
	for (int i = 0; i < LENTH; i++)
	for (int j = 0; j < LENTH; j++)
		grid[i][j] = 0;
}

//*******************************************************************

void MagicSquare::SetDefalut()
//	Pre:	none
//	Post:	set the magic square's every cell to be 0 manually
{
	for (int i = 0; i < LENTH; i++)
	for (int j = 0; j < LENTH; j++)
		grid[i][j] = 0;
}

//*******************************************************************

void MagicSquare::Generate()
//	Pre:	none  
//	Post:	set the magic square to be really "magic", that's to say,
//			sum of every row, column, and diagonals are all equal
//	Note:	the input and output operations are binded to the method
//			&& the input size should > 0 && it's an odd number.
{
	SetDefalut();
	cout << "Please input a size: " << flush;
	cin >> sideLen;

	//satisfy the input:
	while (sideLen <= 0)
	{
		cout << "Should be a postive number please enter again: " << flush;
		cin >> sideLen;
	}

	while (sideLen % 2 == 0)
	{
		cout << "Should be an odd number please enter again: " << flush;
		cin >> sideLen;
	}

	//	generating:
	int num = 1;
	int row = 0;
	int col = (sideLen - 1) / 2;	
	for (; num <= sideLen * sideLen; num++)
	{
		grid[row][col] = num;
		row--;
		col++;
		
		//deal with out of bound 
		if (row < 0)
			row += sideLen;
		if (col >= sideLen)
			col -= sideLen;

		//deal with overtaking the cell
		if (grid[row][col])
		{
			row += 2;
			col--;
		}
		if (row >= sideLen)
			row -= sideLen;
		if (col < 0)
			col += sideLen;
	}
}

//*******************************************************************

bool MagicSquare::Judge(
	/* in */ const Grid gridIn,
	/* in */ int size)
//	Pre:	size should be the same of the side length of the gird "gridIn"
//			&& size should be positive
//	Post:	if is , return 1; else return 0
{
	if (size < 0)
	{
		cerr << "MagicSquare::Judge() error: size can't be < 0.\n" << flush;
		return 0;
	}

	bool result = true;		//preinstalled

	//	Judge rows
	int i = 0;
	int j = 0;
	int SumR = 0;			//sum of rows
	int SumRD = 0;			//sum of the first row, for compare
	for (j = 0; j < size; j++)
	{
		SumRD += gridIn[i][j];
	}
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			SumR += gridIn[i][j];
		}	
		if (SumR != SumRD)
			{
				result = false;
				return result;
			}
		SumR = 0;
	}

	//	Judge cols
	int SumC = 0;			//sum of cols
	int SumCD = 0;			//sum of the first col, for compare
	j = 0;
	for (i = 0; i < size; i++)
	{
		SumCD += gridIn[i][j];
	}
	for (j = 1; j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			SumC += gridIn[i][j];	
		}
		if (SumC != SumCD)
			{
				result = false;
				return result;
			}
		SumC = 0;
	}

	//	Judge diagnols
	int SumLeft = 0;			//sum of the left diagnol
	int SumRight = 0;			//sum of the right diagnol
	for (i = 0, j = 0; i < size && j < size; i++, j++)
		SumLeft += gridIn[i][j];
	for (i = 0, j = size - 1; i < size && j >= 0; i++, j--)
		SumRight += gridIn[i][j];
	if (SumLeft != SumRight)
	{
		result = false;
		return result;
	}

	return result;
}

//*******************************************************************

void MagicSquare::Read(
	/* in */ const Grid gridIn,
	/* in */ int size)
//	Pre:	size could be the same of the side length of the gird "gridIn"		
//			&& grid should be assigned value
//	Post:	grid is loaded into the MagicSquare class
//	Note:	size should be positive
{
	if (size < 0)
	{
		cerr << "MagicSquare::Read() error:	size can't be < 0.\n" << flush;
		return;
	}

	sideLen = size;
	for (int i = 0; i < sideLen; i++)
	for (int j = 0; j < sideLen; j++)
	{
		grid[i][j] = gridIn[i][j];
	}
}

//*******************************************************************

void MagicSquare::Print()
//	Pre:	gird contains components
//			&& sideLen >= the actual size of the grid
//	Post:	The grid is printed out
//	Note:	sideLen should be positive 
{
	if (sideLen < 0)
	{
		cerr << "MagicSquare::Judge() error: size can't be < 0.\n" << flush;
		return;
	}

	for (int i = 0; i < sideLen; i++)
	{
		for (int j = 0; j < sideLen; j++)
		cout << grid[i][j] << ' ';
		cout << '\n';
	}
}