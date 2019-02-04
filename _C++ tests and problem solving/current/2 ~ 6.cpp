#include <iostream>
#include <string>
#include <iomanip>		//for setwidth

using namespace std;

//*************************************************************************************************
//Specification
//*************************************************************************************************

enum Medium {OIL, WATERCOLOR, PASTEL, ACRYLIC, PRINT, COLOR_PHOTO, B_AND_W_PHOTO};
enum Room	{MAIN, GREEN, BLUE, NORTH, SOUTH, ENTRY, BALCONY};		//Where it's hanged

struct Size
{
public:
	int height;	//measures in inches
	int width;
};

//*************************************************************************************************

struct Artwork
{
public:
	string artist;
	string title;
	Medium medium;
	Size size;
	Room room;
	float price;
};

//*************************************************************************************************

typedef Artwork Works[120];		//all are 120 pieces

const int EACH_GROUP(5);
const int NUMBER_OF_SETS(3);

//No.2
typedef float DataSet[EACH_GROUP];

bool Equal(/* in */ const DataSet first, 
		   /* in */ const DataSet second);

int main()
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
	
	cout << 1 << endl;
	return 0;
}

//*************************************************************************************************
//Inplementation
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
