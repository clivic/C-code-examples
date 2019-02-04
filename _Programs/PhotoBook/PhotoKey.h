#include "PhotoRecord.h"
#ifndef PHOTOKEY
#define PHOTOKEY
class PhotoKey
{
public:
	PhotoKey(string x = " ");
	PhotoKey(const PhotoRecord &r);
	string Getstring() const;
protected:
	string key;
};

bool operator == (const PhotoKey & x, const PhotoKey &y);
bool operator > (const PhotoKey & x, const PhotoKey &y);
bool operator < (const PhotoKey & x, const PhotoKey &y);
bool operator >= (const PhotoKey & x, const PhotoKey &y);
bool operator <= (const PhotoKey & x, const PhotoKey &y);
#endif