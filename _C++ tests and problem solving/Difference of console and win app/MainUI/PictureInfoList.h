#include"LocationGraph.cpp"
#ifndef PLIST
#define PLIST
class PictureInfoList: public List<PictureRecord > {
public:
	PictureInfoList();
	Error_code initialization();
	Error_code insert(const PictureRecord  &data);
	Error_code remove(PictureRecord & data);
	Error_code replace(const PictureRecord  &data);    // the meaning is changed only
	Error_code searchByTitle(string title, int& n /*���ҵ�������*/, const Node<PictureRecord >*   items[]/*��Ӧ�ռ��ָ���ַ*/);
	Error_code searchByLocation(string location,  int& n /*���ҵ�������*/, const Node<PictureRecord >  *   items[]/*��Ӧ��¼��ָ���ַ*/);
	Error_code searchByFootmark(LocationGraph<200> &map);
	void sort();
	void print();
private:
	//���Ҹ�������
	Error_code searchByKey(string filename,PictureRecord  & item/*out*/, int& pos/*out*/);
};

#endif