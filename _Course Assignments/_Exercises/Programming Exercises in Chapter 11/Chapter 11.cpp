#include <iostream>
#include <string>
#include "struct and enum.h"

using namespace std;

int main()
{
	Time someTime;
	someTime.minutes = 6;
	someTime.seconds = 54;
	
	Song mySong;
	mySong.title = "Resolution";
	mySong.album = "Mild Wind";
	mySong.artist = "Clivic";
	mySong.time = someTime;
	mySong.type = PURE_MUSIC;

	cout << "Time is: " << someTime.minutes
		 << "\' " << someTime.seconds << endl << endl;
	
	cout << "My song: " << mySong.title  << endl
		 << "Album:   " << mySong.album  << endl
		 << "Artist:  " << mySong.artist << endl
		 << "Time:    " << someTime.minutes
		 << "\' " << someTime.seconds   << endl;

	return 0;
}