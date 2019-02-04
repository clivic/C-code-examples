#include <iostream>
#include <string>

using namespace std;

//enumeration of catgory
enum Catgory { PURE_MUSIC, SONG, PURE_VOICE_SONG };

//Type declaration
struct Time
{
	int minutes;
	int seconds;
};

struct Song
{
	string title;
	string album;
	string artist;
	Time time;
	Catgory type;
};