////*******************************************************************
////	Client (a)
////	This client reads an array of int and determmine whether to be 
////	a magic square.
////*******************************************************************
//#include "utility.h"
//#include "MagicSquare.h"
//
//int main()
//{
//	MagicSquare square;
//	Grid grid;
//	int size;
//	do
//	{
//		//Reads a square
//		cout << "Please enter a square, first the size of it: " << flush;
//		cin >> size;
//		while (size <= 0 || !cin)
//		{
//			cout << "Size should > 0, please input again: " << flush;
//			cin >> size;
//		}
//		cout << "Then input the grid: " << endl;
//		for (int i = 0; i < size; i++)
//		for (int j = 0; j < size; j++)
//			cin >> grid[i][j];
//
//		cout << "The grid you input is: " << endl;
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//				cout << grid[i][j] << ' ';
//			cout << '\n';
//		}
//
//		cout << endl << endl;
//
//		//Judge
//		if (square.Judge(grid, size))
//			cout << "It is a magic square.\n" << flush;
//		else
//			cout << "It is not a magic square.\n" << flush;
//		cout << "\nContinue?" << flush;
//	} while (UserSayYes());
//}