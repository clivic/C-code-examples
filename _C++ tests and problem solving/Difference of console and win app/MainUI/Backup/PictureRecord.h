//*******************************************************************
//	PictureRecord class Specification
//	General introduction:	
//		It's a modification based on codes offered by Ms.Wang, whose
//		is also cooperated with a mate called XiaoYi Shu.
//		It stores the info of one picture.
//*******************************************************************
#include "utility.h"
#ifndef PRECORD
#define PRECORD

struct OthersType
{
    int height;
	int width;
	int Size;
	long time;			//��������2038��1��18��19ʱ14��07��
	string information;	//������Ϣ
	string titleEn;		//Ӣ��title
    string map;			//������ͼ
	string location;	//��ͼ�е�λ��
	string hmap;		//�����ϼ���ͼ
	string hlocation;	//hmap�е�λ��
	string owner;		//����
};

class PictureRecord 
{
public:
	PictureRecord();
	PictureRecord(string a, OthersType others);
	string GetKey() const;
	int GetHeight() const;
	int GetWidth() const;
	int GetSize() const;
	long GetTime() const;
	string GetInfo() const;
	string GetTitleEn() const;
	string GetMap() const;
	string GetLocation() const;
	string GetHMap() const;
	string GetHLocation() const;
	string GetOwner() const;
    OthersType GetOthers() const;
private:
	string key; //filename
	OthersType info;//see defintion of OthersType
};

bool operator > (const PictureRecord  &x, const PictureRecord  &y);
bool operator < (const PictureRecord  &x, const PictureRecord  &y);
bool operator <= (const PictureRecord  &x, const PictureRecord  &y);
bool operator >= (const PictureRecord  &x, const PictureRecord  &y);
bool operator == (const PictureRecord  &x, const PictureRecord  &y);
ostream &operator << (ostream &output, PictureRecord  &x);

#endif