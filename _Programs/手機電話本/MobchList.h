//*************************************************************************************************
//	Mobile Chain list specification 
//	version 1.0
//	This is the independent module of Chain list class, specificly designed to adapt to
//	Mobile phone book.
//	Use:	utility.h (vital).
//*************************************************************************************************
#include "utility.h"
#ifndef CHAINLIST
#define CHAINLIST

struct Entry
{
	string name;						
	string phNum;						//phone number
};
struct Node								//the containing of every member in a chain list
{
	Entry entry;
	Node* next;
	Node(string nameIn, 
		 string phNumIn);				
	Node();								//initialize the containing of num
	void NodePrint();					//cout the entry it contains
};
class ChainList
{
private: 
	int len;								//the length 
	Node* h;								//the first member address
	Node* ps;								//pointer for start pos
	Node* pt;								//pointer for terminal pos
	void FindPos(int i);					//find the ith member use ps to point to it
public:	
	ChainList();							//initialization
	ChainList(string nameIn,
			  string phNumIn);				//initialization with an initial member
	~ChainList();							//destruction	
	Node* GetAdr() const;					//return address of the first member(or of the whole list)
	int GetLen() const;						//return the chain list's length
	string GetName(/* in */ int i);			//return the ith member's name
	string GetPhNum(/* in */ int i);		//return the ith member's phone number
	void Print();							//print the items in the whole list
	void Print(int i);						//print the ith item
	void ModifyName(int i);					//modify the name of the item in member specified
	void ModifyNum(int i);					//modify the phone number of the item in member specified
	void Add();								//prompt and add a member in mobile phone book 
	void Delete(int i);						//delete a dynamic member in pos i, 
											//if i = 0, delete the first one 
	int FindByName(const string& name);
	int FindByPhNum(const string& phNum);
	void FindByName_Print(const string& name);
	void FindByPhNum_Print(const string& phNum);
};

#endif