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
	Error_code SearchByTitle(string title, int &n /*查找到的数量*/, const Node<PictureRecord >*  items[]/*对应空间的指针地址*/);
	Error_code SearchByLocation(string location,  int &n /*查找到的数量*/, const Node<PictureRecord >  *  items[]/*对应记录的指针地址*/);
	Error_code SearchByFootmark(Map<200> &map);
	void Sort();
	void Print();
private:
	//查找辅助函数
	Error_code SearchByKey(string filename,PictureRecord &item, int &pos);
};

#endif