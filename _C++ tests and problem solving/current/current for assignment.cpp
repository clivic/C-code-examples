#include <iostream>
#include <string>

using namespace std;

//enumeration of catgory
enum Catgory {PURE_MUSIC, SONG, PURE_VOICE_SONG};

//Type declaration
//No.1
struct Time
{
	int minutes;
	int seconds;
};

//No.3
struct Song
{	
	string title;
	string album;
	string artist;
	Time time;
	Catgory type;
};

//***********************************************

int main()
{
	//No.2
	Time someTime;
	someTime.minutes = 6;
	someTime.seconds = 54;
	
	//No.4
	Song mySong;
	mySong.title = "Resolution";
	mySong.album = "Mild Wind";
	mySong.artist = "Clivic";
	mySong.time = someTime;
	mySong.type = PURE_MUSIC;

	
	//cout << "Time is: " << someTime.minutes
	//	   << "\' " << someTime.seconds << endl << endl;
	//
	//cout << "My song: "<< mySong.title  << endl
	//	   << "Album:   " << mySong.album  << endl
	//	   << "Artist:  " << mySong.artist << endl
	//	   << "Time:    " << someTime.minutes
	//	   << "\' " << someTime.seconds   << endl;
	cout << 1 << endl;
	return 0;
}
