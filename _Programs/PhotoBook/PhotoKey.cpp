#include "PhotoKey.h"

PhotoKey::PhotoKey(string x)
{
	key = x;
}

PhotoKey::PhotoKey(const PhotoRecord & r)
{
	key = r.GetKey();
}

string PhotoKey::Getstring() const
{
	return key;
}

bool operator == (const PhotoKey & x, const PhotoKey &y)
{
	return x.Getstring()==y.Getstring();
}

bool operator > (const PhotoKey & x, const PhotoKey &y)
{
	return x.Getstring()>y.Getstring();
}

bool operator < (const PhotoKey & x, const PhotoKey &y)
{
	return x.Getstring()<y.Getstring();
}

bool operator >= (const PhotoKey & x, const PhotoKey &y)
{
	return x.Getstring()>=y.Getstring();
}

bool operator <= (const PhotoKey & x, const PhotoKey &y)
{
	return x.Getstring()<=y.Getstring();
}