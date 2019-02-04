//*******************************************************************
//	Hash Table Class Implementation
//*******************************************************************
#include "Hash Table.h"

Key empty = "";
Key used = "        ";

HashTable::HashTable()
{
	Clear();
}

void HashTable::Clear()
//	Post:	Clear all the HashTable, reset it to the state that every 
//			entrie is in the default empty, with key = "".
{
	for (int i = 0; i < HASH_SIZE; i++)
	{
		Record tmp(-1,empty);
		table[i] = tmp;
	}
	collideTime = 0;
}

Error_code HashTable::Insert(const Record &newEntry)
//	Post:	If the Hash table is full, a code of overflow is returned. 
//			If the table already contains an item with the key of new 
//			entry a code of duplicate error is returned, else
//			the Record new entry is inserted into the Hash table and 
//			success is returned.
//	Uses:	Methods for classes Key, and Record, The function hash.
{
	Error_code result = success;
	int probeCount,		// Counter to be sure that table is not full.
		increment,		// Increment used for quadratic probing.
		probe;			// Position currently probed in the hash table.
	probe = Hash(newEntry);
	probeCount = 0;
	increment = 1;
	//convert from const record to record, then to key
	if (Retrieve((Record)newEntry, (Record)newEntry) == success)	
		return duplicate_error;
	while (table[probe] != empty			// Is the location empty?
		&& table[probe] != used				// empty because delete
		&& table[probe] != newEntry.GetKey()// Duplicate key?
		&& probeCount < (HASH_SIZE + 1) / 2)// Has overflow occurred?
	{ 
		probeCount++;
		probe = (probe + increment) % HASH_SIZE;
		increment += 2; // Prepare increment for next iteration.
		collideTime++;
	}
	if (table[probe] == empty) table[probe] = newEntry;
	if (table[probe] == used) table[probe] = newEntry;
	// Insert new entry.
	else if (table[probe] == newEntry.GetKey())	result = duplicate_error;
	else result = overflow; // The table is full.
	return result;
}

Error_code HashTable::Retrieve(const Key &target, Record &found) const
//	Post:	Use Hash function to retrieve the target, if not found,
//			return not_present, else Record found = the Record of Key
//			target, and return success.
//	Uses:	Methods for classes Key, and Record, The function hash.
{
	int probeCount,		// Counter to be sure that table is not full.
		increment,		// Increment used for quadratic probing.
		probe;			// Position currently probed in the hash table.
	probe = Hash(target);
	probeCount = 0;
	increment = 1;
	while (table[probe].GetKey() != empty // Is the location empty?
		&& table[probe].GetKey() != target.GetKey() // not found
		&& probeCount < (HASH_SIZE + 1) / 2) // Has overflow occurred?
	{ 
		probeCount++;
		probe = (probe + increment) % HASH_SIZE;
		increment += 2; // Prepare increment for next iteration.
	}
	if (table[probe].GetKey() == target.GetKey())
	{
		found = table[probe];
		return success;
	}
	else return not_present;
}

Error_code HashTable::Remove(const Key &target, Record &found)
//	Uses:	Methods for classes Key, and Record, The function hash.
{
	int probeCount, // Counter to be sure that table is not full.
		increment,	// Increment used for quadratic probing.
		probe;		// Position currently probed in the hash table.
	probe = Hash(target);
	probeCount = 0;
	increment = 1;
	while (table[probe] != empty // Is the location empty?
		&& table[probe].GetKey() != target.GetKey() // not found
		&& probeCount < (HASH_SIZE + 1) / 2) { // Has overflow occurred?
		probeCount++;
		probe = (probe + increment) % HASH_SIZE;
		increment += 2; // Prepare increment for next iteration.
	}
	if (table[probe].GetKey() == target.GetKey())
	{
		found = table[probe];
		table[probe].WriteWord(used);  //attention
		return success;
	}
	else return not_present;
}

Error_code HashTable::Replace(const Key &replaced, const Record &toReplace, Record &found)
//	Post:	if the Record corresponding to the Key replaced is not in the hash table,
//			return not_present, else replace that Record with Record toReplace, and 
//			store the original one in Record found.
{
	if (Remove(replaced, found) == success)	return Insert(toReplace);
	return not_present;
}

int HashTable::GetCollideTime() const
{
	return collideTime;
}

int Hash(const Record &newEntry)
//	Post:	Arrange the Key newEntry to a position in the array.
//	Uses:	Hash function in Key class parameter.
{
	Key key = newEntry.GetKey();
	return Hash(key);
}

int Hash(const Key &newEntry)
//	Post:	Arrange the Key newEntry to a position in the array.
//	Note:	This Hash Function'simplementation is ELFHash 
//			(Executable and Linking Format), with collide time
//			435, in length 30001 array.
{
	String keyWord = newEntry.GetKey();
	unsigned long pos = 0, temp;
	for (int i = 0; keyWord[i] != 0; i++)
	{
		pos = (pos << 4) + keyWord[i];
		temp = pos & 0xF0000000L;
		if (temp)	pos ^= temp >> 24;
		pos &= ~temp;
	}
	return pos = pos % HASH_SIZE;
}