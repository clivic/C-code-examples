/* author ShuXiaoYi
** modify WangLiping
**
*/
#include<iostream>
#include<string>
using namespace std;
#ifndef PRECORD
#define PRECORD

struct OthersType{
    int height;
	int width;
	int size;
	long time;//��������2038��1��18��19ʱ14��07��
	string detail;//��ϸ����
	string titleEn;//Ӣ��title
    string map;//������ͼ
	string location;//��ͼ�е�λ��
	string hmap;//�����ϼ���ͼ
	string hlocation;//hmap�е�λ��
	string owner;//����

};

class PictureRecord {
public:
	PictureRecord();
	PictureRecord(string a, OthersType others);
	string the_key() const;
	int the_height() const;
	int the_width() const;
	int the_size() const;
	long the_time() const;
	string the_detail() const;
	string the_titleEn() const;
	string the_map() const;
	string the_location() const;
	string the_hmap() const;
	string the_hlocation() const;
	string the_owner() const;
    OthersType the_others() const;
private:
	string key; //filename
	OthersType info;//see defintion of OthersType
	
};

bool operator > (const PictureRecord  &x, const PictureRecord  &y);
bool operator < (const PictureRecord  &x, const PictureRecord  &y);
bool operator <= (const PictureRecord  &x, const PictureRecord  &y);
bool operator >= (const PictureRecord  &x, const PictureRecord  &y);
bool operator == (const PictureRecord  &x, const PictureRecord  &y);
ostream & operator << (ostream &output, PictureRecord  &x);

#endif