//*******************************************************************
//	Sortable list (Storing Character Strings) Specification
//	General introduction:	
//		This Sortable list is derived from SortableList as the name 
//		"SortableListChar", which is only for storing c-strings. But 
//		this class can use a new way to sort elements besides those 
//		7 sorting methods -- Radix Sort.
//	Uses:
//		Sortable_List.h, Linked_Queue.h and STL string.h
//*******************************************************************
#ifndef SORTABLELISTCHAR
#define SORTABLELISTCHAR
#include "Sortable_List.h"
#include "Linked_Queue.h"
//#include <string>

const int KEY_SIZE = 50;
const int MAX_CHARS = 28;

class KeyCStr
{
public:
	KeyCStr(char s[]);				//constructor
	char* GetKeyCStr() const;
protected:
	char str[KEY_SIZE];
};

//*******************************************************************

class RecordCStr
{
public:
	operator KeyCStr();				//implicit conversion from RecordCStr to KeyCStr.
	RecordCStr(char s[] = "");		//constructor
	char *GetKeyCStr() const;		
	char KeyCStrLetter(int position) const;
protected:
	char str[KEY_SIZE];
	//You can add other infomations into the record.
};

//output the key
ostream &operator << (ostream &output, KeyCStr &x);

//*******************************************************************

class SortableListChar : public SortableList<RecordCStr>
//for test of radix sort we change it as: 
//(because SortableList is too large.(a tmp array)
//class SortableListChar : public List<RecordCStr>
{
public:
	void RadixSort();
protected:
	void Rethread(Queue<RecordCStr> queues[]);
};

//Auxillary function of RadixSort
int AlphabeticOrder(char c);
#endif