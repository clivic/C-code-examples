//*************************************************************************************************
//	Chain list specification 
//	version 2.0
//	this version is two-way chain list, more convenient for finding than the previous version:
//	1. its members' memorys are not adjoined to another one by one
//	2. its length is specified by the user, having not "MAX_LENGTH" and varying length variable
//	   like that in array list.
//	3. when finding, either front to end or end to front is available.
//	4. It's a circullar chain list.
//	but still has disadvantage:
//	-- its more complex to determine a member for it has to find from the begining
//	   everytime locating it.
//*************************************************************************************************
#ifndef CL2
#define CL2
#include"chainList.h"
typedef int type;						//convenient to modify type

struct Node2: public Node				//the containing of every member in a chain list
{
	Node2* precede;
	Node2(type item = 0);				//initialize the containing of key
};
class ChainList2 :public ChainList
{
public:
	ChainList2(type n = 1);				//initialization
	~ChainList2();						//destruction	
	void ReplaceItem(int i, type item);	//replace the item in member specified
	void Replace(int i, Node* &member);	//replace the member in pos specified
	void Insert(int i, Node* &member);	//insert a member between pos i and pos i + 1, 
	//if i = 0, insert it at the head 
	void Delete(int i);					//delete a dynamic member in pos i, 
	//if i = 0, delete the first one 
};

#endif