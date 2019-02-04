//*******************************************************************
//	Hash Table Class Specification
//	Version 1.0
//	General introduction:
//		This is the Hash Table based on Key and Record Classes, which 
//		can be quite different in every implementation but always in
//		the similar structure.
//	Notes:	
//		The Key class should contain KeyLetter method which accepts
//		an integer indicates the position and return the character
//		in the key in this position; And MakeBlank function which sets
//		up an empty key.
//	Uses:
//		Key and Record Classes
//*******************************************************************
#ifndef HASH
#define HASH
#include "Key and Record.h"
#include "utility.h"
const int HASH_SIZE = 30001;

class HashTable 
{
public:
	HashTable();
	void Clear();
	Error_code Insert(const Record &newEntry);
	Error_code Retrieve(const Key &target, Record &found) const;
	Error_code Remove(const Key &target, Record &found);
	Error_code Replace(const Key &replaced, const Record &toReplace, Record &found);
	int GetCollideTime() const;
protected:
	int collideTime;
	Record table[HASH_SIZE];
};

int Hash(const Record &newEntry);

int Hash(const Key &newEntry);


#endif