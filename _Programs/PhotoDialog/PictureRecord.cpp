#include  "PictureRecord.h"

PictureRecord ::PictureRecord()
{
   key = "none";
}

PictureRecord ::PictureRecord(string k, OthersType others)
{
   key = k;
   info = others;
}
	
string PictureRecord ::GetKey() const
{
   return key;
}

int PictureRecord ::GetHeight() const
{
   return info.height;
}

int PictureRecord ::GetWidth() const
{
   return info.width;
}
int PictureRecord ::GetSize() const
{
   return info.size;
}
long PictureRecord ::GetTime() const
{
   return info.time;
}
string PictureRecord ::GetInfo() const
{
   return info.information;
}

string PictureRecord ::GetTitleEn() const
{
   return info.titleEn;
}

string PictureRecord ::GetMap() const
{
   return info.map;
}

string PictureRecord ::GetLocation() const
{
   return info.location;
}

string PictureRecord ::GetHMap() const
{
   return info.hmap;
}

string PictureRecord ::GetHLocation() const
{
   return info.hlocation;
}

string PictureRecord ::GetOwner() const
{
   return info.owner;
}

OthersType PictureRecord ::GetOthers() const
{
   return info;
}

bool operator > (const PictureRecord  &x, const PictureRecord  &y)
{
	return x.GetTitleEn() > y.GetTitleEn();
}

bool operator < (const PictureRecord  &x, const PictureRecord  &y)
{
	return x.GetTitleEn() < y.GetTitleEn();
}

bool operator <= (const PictureRecord  &x, const PictureRecord  &y)
{
	return x.GetTitleEn() <= y.GetTitleEn();
}

bool operator >= (const PictureRecord  &x, const PictureRecord  &y)
{
	return x.GetTitleEn() >= y.GetTitleEn();
}

bool operator == (const PictureRecord  &x, const PictureRecord  &y)
{
	return x.GetTitleEn() == y.GetTitleEn();
}

ostream &operator << (ostream &output, PictureRecord  &x)
{
	output << x.GetKey() << ", " << x.GetHeight() << ", " << x.GetWidth()
		<< ", " << x.GetSize() << ", " << x.GetTime() << ", " << x.GetInfo()
		<< ", " << x.GetTitleEn() << ", " << x.GetMap() << ", " << x.GetLocation()
		<< ", " << x.GetHMap() << ", " << x.GetHLocation() << ", " << x.GetOwner();
	output << endl << endl;
	return output;
}


