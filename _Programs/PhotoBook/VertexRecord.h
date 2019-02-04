#include "utility.h"
#include "string.h"
#ifndef VERTEXRECORD
#define VERTEXRECORD

class VertexRecord
{
public:
	//constructors
	VertexRecord(); 
	VertexRecord(int n, int x1, int y1, string location1, string detail1);

	int GetNo();
	int GetX();
	int GetY();
	string GetLocation();
	string GetDetail();

	void SetLocation(string loc);
	void SetDetail(string del);

protected:
	int no;		//number of vertex

	int x;
	int y;
	string location;
	string detail;
};

//ostream & operator << (ostream &output, VertexRecord  &x);
#endif