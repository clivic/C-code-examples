#include  "utility.h"
#ifndef VERTEXRECORD
#define VERTEXRECORD

class VertexRecord
{
public:
	//constructors
	VertexRecord(); 
	VertexRecord(int n, int x1, int y1, string location1, string information1);

	int GetNo();
	int GetX();
	int GetY();
	string GetLocation();
	string GetInfo();

	void SetLocation(string loc);
	void SetInfo(string del);

protected:
	int no;		//number of vertex

	int x;
	int y;
	string location;
	string information;
};

//ostream &operator << (ostream &output, VertexRecord  &x);
#endif