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
	Error_code Initialize();//读取graphVertex.txt，读取introuction.txt
	Error_code InsertPicPtr(string location, const Node<PhotoRecord > *cptr);//增加地点与pic的对应关系
	void Print();			//输出节点信息，及其节点与地点的对应关系信息；
	
	string GetName() const;
	void SetName(string name);

protected:
	//functions
	Error_code  ReadVertexXY(); //读取节点的x，y轴信息。called by Initialize
	Error_code  readVertexInfo();//读取节点的详细信息。called by Initialize
	Error_code SearchByNo(int no, int&pos, VertexRecord& vr) ;//查找指定编号no在list中的详细信息

	Error_code SearchByLocation(string location, int&pos, VertexRecord& vr) ;

	//data
	int count; //包含的节点数目；
	string name;//地图名称，如华师大，中国等
	//记录每个节点对应的图片的内存地址；
	List <const Node<PhotoRecord >  *>  picInfoPtrs[graphSize];
	//记录结点信息
	List<VertexRecord> vertexList; 
};

//*******************************************************************

template <int graphSize>
Map::Map()
{
	count = 0;
	name = "";
}