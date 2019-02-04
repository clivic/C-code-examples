//*************************************************************************************************
//	Chain list specification 
//	version 1.1
//	General:
//	this is a list like array list, but it's implemented by pointer struct and has advantages:
//	1. its members' memorys are not adjoined to another one by one
//	2. its length is specified by the user, having not "MAX_LENGTH" and varying length variable
//	   like that in array list.
//	but also has disadvantages:
//	1. its more complex to determine a member for it has to find from the begining
//	   everytime locating it.
//	2. its containing could only be simple types like double, int... And need to be modified 
//	   manually by client in this specification.
//	Updates from v1.0:
//	1. it's circulate.
//	2. included in standard utility package 
//*************************************************************************************************
#ifndef CL
#define CL
#include "D:\Visual C++ programs\Utility\utility.h"

typedef int type;											//convenient to modify type

struct Node													//the containing of every member in a chain list
{
	type key;
	Node* next;
	Node(type item = 0, Node* addOn = NULL);				//initialize the containing of key
};

class ChainList 
{
protected: 
	int len;												//the length 
	Node* h;												//the first member address
	Node* ps;												//pointer for start pos
	Node* pt;												//pointer for terminal pos
public:	
	ChainList(type n = 1);									//initialization	
	Node* GetAdr() const;									//return address of the first member(or of the whole list)
	type GetItem(int i);									//return the item in member specified
	type GetItem_Change(int i);								//return the item in member specified AND make the head pointer
															//to the current entry
	Node GetMember(int i);									//return the member specified
	int GetLen() const;										//return the chain list's length
	void Print();											//print the items in the whole list
	void ReplaceItem(int i, type item);						//replace the item in member specified
	void Replace(int i, Node* &member);						//replace the member in pos specified
	void Insert(int i, type item);							//insert a member between pos i and pos i + 1, 
															//if i = 0, insert it at the head 
	void Delete(int i);										//delete a dynamic member in pos i, 
															//if i = 0, delete the first one 
	void Clear();											//clear the list

	//Safety Guards
	~ChainList();											//destruction
	ChainList(const ChainList& original);					//copy constructor
	ChainList& operator = (const ChainList& original);		//overload =
};

#endif