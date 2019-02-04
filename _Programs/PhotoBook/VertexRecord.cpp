#include "VertexRecord.h"

VertexRecord::VertexRecord()
{
	no = x = y = 0;
	location = detail = "";
}

VertexRecord::VertexRecord(int n, int x1, int y1, string location1, string detail1)
{

	no = n;
	x = x1;
	y = y1;
	location = location1; detail = detail1;
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

string VertexRecord::GetDetail()
{
	return detail;
}

void VertexRecord::SetLocation(string loc)
{
	location = loc;
}

void VertexRecord::SetDetail(string del)
{
	detail = del;
}