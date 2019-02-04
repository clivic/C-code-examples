/************************************************************************************************************************************
Acoustic Program
This program inputs 12 sound-level readings, taken in a room at different frequencies. The first reading is used as a base value.
For each reading, a value related to the base is calculated and printed. This program ends by printing the highest and lowest reading.
************************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void main()
{
	//Declare variables
	float baseValue,       //first Reading
		  current,		   //each input
		  relative,		   //current - baseValue
		  high,			   //highest value input
		  highRelative,	   //high - baseValue
		  low,			   //lowest value input
		  lowRelative;	   //low - baseValue
	int   highNumber,	   //Sequence number of high
		  lowNumber,	   //Sequence number of low
		  readingNumber;   //Sequence number of current

	//Declare file input
	ifstream fin;
	fin.open("acoustic.txt");
	if (!fin)
	{
		cout << "Can't open data. Please check your file and determine if it exists or could be opened." << endl;
		return 1;
	}

	//Initialize variables and output(The format)
	readingNumber(1), relative(0);
	cout << setw(14) << "Reading Number" << setw(15)
		 << "Actual Reading" << setw(18) << "Relative Reading"
		 << endl;

	

