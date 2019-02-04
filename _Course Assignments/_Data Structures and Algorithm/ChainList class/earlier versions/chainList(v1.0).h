//*************************************************************************************************
//	Chain list specification 
//	version 1.0
//	this is a list like array list, but it's implemented by pointer struct and has advantages:
//	1. its members' memorys are not adjoined to another one by one
//	2. its length is specified by the user, having not "MAX_LENGTH" and varying length variable
//	   like that in array list.
//	but also has disadvantage:
//	-- its more complex to determine a member for it has to find from the begining
//	   everytime locating it.
//*************************************************************************************************
#ifndef CL
#define CL

typedef int type;						//convenient to modify type

struct Node								//the containing of every member in a chain list
{
	type key;
	Node* next;
	Node(type item = 0);				//initialize the containing of key
};
class ChainList 
{
protected: 
	int len;							//the length 
	Node* h;							//the first member address
	Node* ps;							//pointer for start pos
	Node* pt;							//pointer for terminal pos
public:	
	ChainList(type n = 1);				//initialization
	~ChainList();						//destruction	
	Node* GetAdr() const;				//return address of the first member(or of the whole list)
	type GetItem(int i);				//return the item in member specified
	Node GetMember(int i);				//return the member specified
	int GetLen() const;					//return the chain list's length
	void Print();						//print the items in the whole list
	void ReplaceItem(int i, type item);	//replace the item in member specified
	void Replace(int i, Node* &member);	//replace the member in pos specified
	void Insert(int i, Node* &member);	//insert a member between pos i and pos i + 1, 
										//if i = 0, insert it at the head 
	void Delete(int i);					//delete a dynamic member in pos i, 
										//if i = 0, delete the first one 
};

#endif