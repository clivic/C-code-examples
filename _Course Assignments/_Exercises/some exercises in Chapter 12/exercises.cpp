#include <iostream>
#include <string>
#include <iomanip>		//for setwidth
#include "ArtWork.h"	//for No.7

using namespace std;

const int EACH_GROUP(5);
const int NUMBER_OF_SETS(3);

//No.2
typedef float DataSet[EACH_GROUP];

bool Equal(/* in */ const DataSet first, 
		   /* in */ const DataSet second);

void main()
{
	//No.2
	DataSet input, output, working;

	//No.3
	DataSet set[NUMBER_OF_SETS];

	//No.4
	for (int outer(0); outer < NUMBER_OF_SETS; outer++)
	{
		for (int inner(0); inner < EACH_GROUP; inner++)
		{
			set[outer][inner] = 0;
		}
	}
	
	//No.7
	Works currentList;
	int numPieces(120);
	
	//No.8
	currentList[36];
	currentList[11].title;
	currentList[84].size.width;
	currentList[119].room;
	currentList[77].artist.substr(0,1);

	//No.9
	int num(0);		//number of artworks in currentList.
	for (num; num < numPieces; num++)
	{
		cout << left << setw(9) << "The item:" << '#' << num + 1 << endl
			 << "Artist:" << currentList[num].artist << endl
			 << setw(9) << "Title:" << currentList[num].title << endl
			 << setw(9) << "Price:" << '$' << currentList[num].price << endl << endl;
	}

	//No.10
	float totalPrice(0);
	for (int count = 0; count < numPieces; count++)
	{
		totalPrice += currentList[count].price;
	}

	//No.11
	cout << "Articles in Blue room:" << endl;
	for (count = 0; count < numPieces; count++)
	{
		cout << "blue" << currentList[count].room << ' ' << BLUE << endl;  
		if (currentList[count].room = BLUE)		//in uninitilized situations, it is realized as "true"...
			cout << currentList[count].title << endl;
	}

	//No.12
	cout << "Total price of oilpaintings larger than 400 inches^2:" << endl;
	float total(0);								//total price
	for (count = 0; count < numPieces; count++)
	{
		if (currentList[count].medium == OIL &&
			currentList[count].size.height *
			currentList[count].size.width > 400)
			total += currentList[count].price;
	}

}

//*************************************************************************************************

//No.5
bool Equal(/* in */ const DataSet first,		//not DataSet first[] please notice ! :)
		   /* in */ const DataSet second)
//No.6
{
	for (int count(0); count < EACH_GROUP; count++)
		if (!(first[count] == second[count]))
			return false;
	return true;
}
