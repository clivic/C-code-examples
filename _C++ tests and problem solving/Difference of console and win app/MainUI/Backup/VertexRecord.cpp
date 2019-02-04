#include  "VertexRecord.h"

VertexRecord::VertexRecord()
{
	no = x = y = 0;
	location = information = "";
}

VertexRecord::VertexRecord(int n, int x1, int y1, string location1, string information1)
{

	no = n;
	x = x1;
	y = y1;
	location = location1; information = information1;
}

int VertexRecord::GetNo()
{
	return no;
}

int VertexRecord::GetX()
{
	return x;
}

int VertexRecord::GetY()
{
	return y;
}

string VertexRecord::GetLocation()
{
	return location;
}

string VertexRecord::GetInfo()
{
	return information;
}

void VertexRecord::SetLocation(string loc)
{
	location = loc;
}

void VertexRecord::SetInfo(string info)
{
	information = info;
}