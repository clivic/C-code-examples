#include <iostream>
#include <string>
#include "struct and enum.h"

using namespace std;

const int ARRAYSIZE = 50;

int main()
{
	Time* pointTime;
	pointTime = new Time;
	(*pointTime).minutes = 6;	//. 's precedence is higher than pointer(*)
	pointTime->seconds = 54;

	Song* pointSong;
	pointSong = new Song;
	pointSong->title = "Resolution";
	pointSong->album = "Mild Wind";
	pointSong->artist = "Clivic";
	pointSong->time = *pointTime;
	pointSong->type = PURE_MUSIC;

	cout << "Time is: " << pointTime->minutes
		<< "'" << pointTime->seconds << endl << endl;

	cout << "My song: " << pointSong->title << endl
		<< "Album:   " << pointSong->album << endl
		<< "Artist:  " << pointSong->artist << endl
		<< "Time:    " << pointSong->time.minutes
		<< "\' " << pointSong->time.seconds<< endl;
	delete pointSong, pointTime;

	//*********************************************************************************************

	//driver of creating an array
	int* array1;
	array1 = new int[ARRAYSIZE];
	
	//initialization
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		array1[i] = i;
	}

	//modify the array
	cout << "Input abtray 5 numbers" << endl;
	cin >> array1[0] >> array1[5] >> array1[10] >> array1[15] >> array1[20];
	
	//find max
	cout << "max : ";
	int max = array1[0];
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		if (max < array1[i])
			max = array1[i];
	}
	cout << max << endl;

	//// find min
	//cout << "min : ";
	//int min = array1[0];
	//for (int i = 0; i < ARRAYSIZE; i++)
	//{
	//	if (min > array1[i])
	//		min = array1[i];
	//}
	//cout << min << endl;

	// asscending sequence sort
	int temp;											//for swap
	int start;											//the start pos in loop of outer iteration 
	int count;											//the start pos in loop of inner iteration
	int pos;											//min value's pos
	int min = array1[0];
	for (start = 0; start < ARRAYSIZE - 1; start++)
	{
		pos = start;
		min = array1[start];
		for (count = start + 1; count < ARRAYSIZE; count++)
		{
			if (min > array1[count])
			{
				min = array1[count];
				pos = count;
			}
		}

		if (start == 0)									//output min replacing the upper one (itegrate)
			cout << "min : " << min << endl;

		//swap
		temp = array1[pos];
		array1[pos] = array1[start];
		array1[start] = temp;
	}

	//outprint the final array
	cout << endl << "Final array:" << endl;
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		cout << array1[i] << endl;
	}

	delete array1;

	return 0;
}