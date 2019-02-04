#include"PhotoRecord.h"

PhotoRecord::PhotoRecord
(int a, string b, int c, int d, int e, long f,
	string g, string h, string i, string j, string k,
	string l, string m, int n)
{
	num = a;
	identifier = b;		//photoIndex
	length = c;
	breath = d;
	size = e;
	photoedtime = f;
	chName = g;
	key = h;			//photoName
	map = i;			//photo place's map	
	place = j;			//photo place
	smap = k;			//superior map
	splace = l;			//place in superior map
	owner = m;
	double frequency = n;
}

int PhotoRecord::GetNum() const
{
	return num;
}

string PhotoRecord::GetIdentifier() const
{
	return identifier;
}

int PhotoRecord::GetLength() const
{
	return length;
}

int PhotoRecord::GetBreath() const
{
	return breath;
}

int PhotoRecord::GetSize() const
{
	return size;
}

long PhotoRecord::GetTime() const
{
	return photoedtime;
}

string PhotoRecord::GetChName() const
{
	return chName;
}

string PhotoRecord::GetKey() const
{
	return key;
}

string PhotoRecord::GetMap() const
{
	return map;
}

string PhotoRecord::GetPlace() const
{
	return place;
}

string PhotoRecord::GetSMap() const
{
	return smap;
}

string PhotoRecord::GetSPlace() const
{
	return splace;
}

string PhotoRecord::GetOwner() const
{
	return owner;
}

int PhotoRecord::GetFrequency() const
{
	return frequency;
}

void PhotoRecord::PlusFrequency()
{
	frequency++;
}

void PhotoRecord::ModifyKey(const string &newKey)
{
	key = newKey;
}

void PhotoRecord::ModifyChName(const string &newChName)
{
	chName = newChName;
}

void PhotoRecord::ModifyOwnerName(const string &newOwner)
{
	owner = newOwner;
}

bool operator > (const PhotoRecord &x, const PhotoRecord &y)
{
	return x.GetKey() > y.GetKey();
}

bool operator < (const PhotoRecord &x, const PhotoRecord &y)
{
	return x.GetKey() < y.GetKey();
}

bool operator <= (const PhotoRecord &x, const PhotoRecord &y)
{
	return x.GetKey() <= y.GetKey();
}

bool operator >= (const PhotoRecord &x, const PhotoRecord &y)
{
	return x.GetKey() >= y.GetKey();
}

bool operator == (const PhotoRecord &x, const PhotoRecord &y)
{
	return x.GetKey() == y.GetKey();
}

ostream & operator << (ostream &output, PhotoRecord &x)
{
	output << x.GetKey() << ", " << x.GetLength() << ", " << x.GetBreath()
		<< ", " << x.GetSize() << ", " << x.GetTime() << ", " << x.GetChName()
		<< ", " << x.GetKey() << ", " << x.GetMap() << ", " << x.GetPlace()
		<< ", " << x.GetSMap() << ", " << x.GetSPlace() << ", " << x.GetOwner()
		<< ", " << x.GetFrequency();
	output << endl << endl;
	return output;
}


