//*******************************************************************
//	Map records specification
//	General introduction:	
//		Link the vertices and pictures to the photoes.
//	Notes:
//		By reference -- Pei Long Fu and Ms.Wang.
//*******************************************************************
#include "Linked_List.h"
#include "VertexRecord.h"
#include "PictureRecord.h"

template <int graphSize>
class Map 
{
public:
	Map();

	Error_code Initialize(string mapname,string mapPath);//load graphVertex.txt and introuction.txt
	Error_code InserPicPtr(string location, const Node<PictureRecord >  *cptr);//link picture and location
	void Print();//Print vertex info. and info. about vertex and location
	
	string GetName() const;
	void SetName(string name);
private:
	//functions
	Error_code ReadVertexXY(string mapPath);					//load x,y
	Error_code readVertexInfo(string mapPath);					//load info
	Error_code SearchByNo(int no, int &pos, VertexRecord &vRec);//search info by number
	Error_code SearchByLocation(string location, int &pos, VertexRecord &vRec) ;
	
	//data members
	int count;													//how many vertex
	string name;												//name of map
	List <const Node<PictureRecord > *> picInfoPtrs[graphSize];	//address of pictures
	List<VertexRecord> vertexList;								

};
