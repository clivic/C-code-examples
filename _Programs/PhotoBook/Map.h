/*
*	By LiPing Wang
*/
#include "Linked_List.h"
#include "VertexRecord.h"
#include "PhotoRecord.h"


template <int graphSize>
class Map 
{
public:
	Map();
	Error_code Initialize();//��ȡgraphVertex.txt����ȡintrouction.txt
	Error_code InsertPicPtr(string location, const Node<PhotoRecord > *cptr);//���ӵص���pic�Ķ�Ӧ��ϵ
	void Print();			//����ڵ���Ϣ������ڵ���ص�Ķ�Ӧ��ϵ��Ϣ��
	
	string GetName() const;
	void SetName(string name);

protected:
	//functions
	Error_code  ReadVertexXY(); //��ȡ�ڵ��x��y����Ϣ��called by Initialize
	Error_code  readVertexInfo();//��ȡ�ڵ����ϸ��Ϣ��called by Initialize
	Error_code SearchByNo(int no, int&pos, VertexRecord& vr) ;//����ָ�����no��list�е���ϸ��Ϣ

	Error_code SearchByLocation(string location, int&pos, VertexRecord& vr) ;

	//data
	int count; //�����Ľڵ���Ŀ��
	string name;//��ͼ���ƣ��绪ʦ���й���
	//��¼ÿ���ڵ��Ӧ��ͼƬ���ڴ��ַ��
	List <const Node<PhotoRecord >  *>  picInfoPtrs[graphSize];
	//��¼�����Ϣ
	List<VertexRecord> vertexList; 
};

//*******************************************************************

template <int graphSize>
Map::Map()
{
	count = 0;
	name = "";
}