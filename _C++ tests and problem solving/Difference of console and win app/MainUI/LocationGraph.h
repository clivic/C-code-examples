#include"LinkList.cpp"
#include"VertexRecord.h"
#include"PictureRecord.h"
#ifndef LGRAPH
#define LGRAPH

template <int graph_size>
class LocationGraph {
public:
	LocationGraph();

	Error_code Initialize(string mapname,string mappath);//��ȡgraphVertex.txt����ȡintrouction.txt
	Error_code InserPicPtr(string location, const Node<PictureRecord >  * cptr);//���ӵص���pic�Ķ�Ӧ��ϵ
	void Print();//����ڵ���Ϣ������ڵ���ص�Ķ�Ӧ��ϵ��Ϣ��
	Error_code SearchByNo(int no, int&pos, VertexRecord& vr);//����ָ�����no��list�е���ϸ��Ϣ
	Error_code SearchByLocation(string location, int&pos, VertexRecord& vr);
	
	string the_name() const;
	void set_name(string name);

	//�x���E���o��method
	//indexΪ�ڵ��ţ�vrΪ�ڵ�Ļ�����Ϣ��trackListPtrΪ�ýڵ��Ӧ����Ƭ�б�
	void get_trackByIndex(int index, VertexRecord& vr, const List <const Node<PictureRecord >  *>*& trackListPtr);
	int get_verterxCount() const; //��count
	void positionToNum(int x, int y, int& index, int& no) const;

private:
	Error_code readVertexXY(string mappath); //��ȡ�ڵ��x��y����Ϣ��called by Initialize
	Error_code readVertexInfo(string mappath);//��ȡ�ڵ����ϸ��Ϣ��called by Initialize
	
	int count; //�����Ľڵ���Ŀ��
	string name;//��ͼ���ƣ��绪ʦ���й���
	//��¼ÿ���ڵ��Ӧ��ͼƬ���ڴ��ַ��
	List <const Node<PictureRecord >  *>  picInfoPtrs[graph_size];
	//��¼�����Ϣ
	List<VertexRecord> vertexList; 

};

#endif