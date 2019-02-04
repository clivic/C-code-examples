/* author ShuXiaoYi
** modify WangLiping
**
*/
#include "utility.h"
#include "string.h"
#ifndef PHOTORECORD
#define PHOTORECORD

class PhotoRecord 
{
public:
	PhotoRecord(int a = 0, string b = " ", int c = 0, int d = 0, int e = 0, long f = 0,
		string g = " ", string h = " ", string i = " ", string j = " ", string k = " ", 
		string l = " ", string m = " ", int n = 0);
	int GetNum() const;
	string GetIdentifier() const;
	int GetLength() const;
	int GetBreath() const;
	int GetSize() const;
	long GetTime() const;
	string GetChName() const;
	string GetKey() const;
	string GetMap() const;
	string GetPlace() const;
	string GetSMap() const;
	string GetSPlace() const;
	string GetOwner() const;
	int GetFrequency() const;
	void ModifyKey(const string &newKey);
	void ModifyChName(const string &newChName);
	void ModifyOwnerName(const string &newOwner);
	
	void PlusFrequency();


protected:
	int num;
	string identifier;		//photoIndex
	int	length;
	int breath;
	int size;
	long photoedtime;
	string chName;
	string key;				//photoName
	string map;				//photo place's map	
	string place;			//photo place
	string smap;			//superior map
	string splace;			//place in superior map
	string owner;
	int frequency;	
};

bool operator > (const PhotoRecord &x, const PhotoRecord &y);
bool operator < (const PhotoRecord &x, const PhotoRecord &y);
bool operator <= (const PhotoRecord &x, const PhotoRecord &y);
bool operator >= (const PhotoRecord &x, const PhotoRecord &y);
bool operator == (const PhotoRecord &x, const PhotoRecord &y);
ostream & operator << (ostream &output, PhotoRecord &x);


#endif