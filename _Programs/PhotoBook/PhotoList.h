#include "Linked_List.h"
#include "PhotoKey.h"
#ifndef PHOTOLIST
#define PHOTOLIST
class PhotoList: public List<PhotoRecord> 
{
public:
	PhotoList();
	Error_code Initialization();
	Error_code Insert(const PhotoRecord &data);
	Error_code Remove(PhotoRecord& data);
	Error_code Replace(const PhotoRecord &data);    // the meaning is changed only
	Error_code SearchByName(string name, int& n, List<Node<PhotoRecord> * > items);
	Error_code SearchByPlace(string place, int& n, List<Node<PhotoRecord> * > items);
	Error_code SearchByKey(PhotoKey word, PhotoRecord & item, int& pos);
	void Sort();
	void Print();
};
#endif