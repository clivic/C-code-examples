#include <string>

using namespace std;

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
