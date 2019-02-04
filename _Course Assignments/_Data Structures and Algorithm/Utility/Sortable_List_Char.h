//*******************************************************************
//	Sortable list (Storing Character Strings) Specification
//	General introduction:	
//		This Sortable list is derived from SortableList as the name 
//		"SortableListChar", which is only for storing c-strings. But 
//		this class can use a new way to sort elements besides those 
//		7 sorting methods -- Radix Sort.
//	Notes:	
//		using the classes Key and Record, so other files containing 
//		classes Key and Record should not be included in the client.
//		Please notice this.
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

class Key
{
public:
	Key(char s[]);				//constructor
	char* GetKey() const;
protected:
	char str[KEY_SIZE];
};

//*******************************************************************

class Record
{
public:
	operator Key();				//implicit conversion from Record to Key.
	Record(char s[] = "");		//constructor
	char *GetKey() const;		
	char KeyLetter(int position) const;
protected:
	char str[KEY_SIZE];
	//You can add other infomations into the record.
};

//output the key
ostream &operator << (ostream &output, Key &x);

//*******************************************************************

class SortableListChar : public SortableList<Record>
//for test of radix sort we change it as: 
//(because SortableList is too large.(a tmp array)
//class SortableListChar : public List<Record>
{
public:
	void RadixSort();
protected:
	void Rethread(Queue<Record> queues[]);
};

//Auxillary function of RadixSort
int AlphabeticOrder(char c);
#endif