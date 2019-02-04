#include "Map.h"
#ifndef PLIST
#define PLIST

class PictureList: public List<PictureRecord > 
{
public:
	PictureList();
	Error_code Initialization();
	Error_code Insert(const PictureRecord  &data);
	Error_code Remove(PictureRecord &data);
	Error_code Replace(const PictureRecord  &data);    // the meaning is changed only
	Error_code SearchByTitle(string title, int &n /*���ҵ�������*/, const Node<PictureRecord >*  items[]/*��Ӧ�ռ��ָ���ַ*/);
	Error_code SearchByLocation(string location,  int &n /*���ҵ�������*/, const Node<PictureRecord >  *  items[]/*��Ӧ��¼��ָ���ַ*/);
	Error_code SearchByFootmark(Map<200> &map);
	void Sort();
	void Print();
private:
	//���Ҹ�������
	Error_code SearchByKey(string filename,PictureRecord &item, int &pos);
};

#endif