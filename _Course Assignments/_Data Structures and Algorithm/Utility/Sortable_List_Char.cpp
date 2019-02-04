//*******************************************************************
//	Sortable list (Storing Character Strings) Implementation
//*******************************************************************
#include "Sortable_List_Char.h"

//Key Class Implementation
Key::Key(char s[])
{
	for (unsigned int i = 0; i <= strlen(s); i++)
		str[i] = s[i];	//include '\0'
}

char * Key::GetKey() const
//	Post:	return the cstring str(key).
{
	return (char *)str;
}

//*******************************************************************
//Record Class Implementation
Record::Record(char s[])
{
	for (unsigned int i = 0; i <= strlen(s); i++)
		str[i] = s[i];
	//You can add some other initializations
}

Record::operator Key()
//	Post:	Convert object of Class Record to that of Class Key.
{
	Key tmp(str);
	return tmp;
}

char Record::KeyLetter(int position) const
//	Post:	Return the character in the specified position if position
//			is in [0, strlen), else return '\0'.
{
	if ((unsigned int)position < strlen(str) && position >= 0)	return str[position];
	else return '\0';
}

char * Record::GetKey() const
//	Post:	return the cstring str(key).
{
	return (char *)str;
}

ostream &operator << (ostream &output, Key &x)
//	Post:	Output the Key in format of cstring.
{
	output << x.GetKey();
	output << "  ";
	return output;
}

//*******************************************************************
//SortableListChar Class Implementation
void SortableListChar::RadixSort()
//	Post:	The entries of the Sortable list have been sorted so all 
//			their keys are in alphabetical order.
//	Uses:	Methods from classesList, Queue, and Record functions 
//			position and rethread. 
{
	Record data;
	Queue<Record> queues[MAX_CHARS];
	for (int position = KEY_SIZE - 1; position >= 0; position--)
	{
		//Loop from the least to the most significant position
		while (Remove(0, data) == success)
		{
			int queue_number = AlphabeticOrder(data.KeyLetter(position));
			queues[queue_number].Append(data);	//Queue operation
		}
		Rethread(queues);						//Reassemble the list
	}
}

void SortableListChar::Rethread(Queue<Record> queues[])
//	Post:	All the queues are combined back to the Sortable list, 
//			leaving all the queues empty.
//	Uses:	Methods of classes List, and Queue.
{
	Record data;
	for (int i = 0; i < MAX_CHARS; i++)
	while (!queues[i].Empty())
	{
		queues[i].Retrieve(data);
		Insert(Size(), data);
		queues[i].Serve();
	}
}

int AlphabeticOrder(char c)
//	Post:	The function returns the alphabetic position of character c, 
//			or it returns 0 if the character is blank.
{
	if (c == ' ' || c == '\0')	return 0;
	if ('a' <= c && c <= 'z')	return c - 'a' + 1;
	if ('A' <= c && c <= 'Z')	return c - 'A' + 1;
	return 27;
}

