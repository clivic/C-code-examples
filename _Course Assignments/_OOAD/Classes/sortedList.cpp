/**************************************************************************************************
IMPLEMENTATION FILE (sortedList.cpp)
This file implements the SortedList class member functions.
In the list, the member data are sorted in ascending sequence.
List representation: a one-dimensional array and a length variable.
This version still use sequencial search.
**************************************************************************************************/

#include <string>
#include "D:\Visual C++ programs\Sorted List ADT\sortedList.h"
#include <iostream>

using namespace std;

/*	Private members of class:
int length;						//Length of the list
DataType data[MAX_LENGTH];		//Array holding the list items								 */

//*************************************************************************************************

SortedList::SortedList()
//	constructor
//	Postcondition:	length == 0.															 
{
	length = 0;
}

//*************************************************************************************************

bool SortedList::Isempty() const
//	Postcondition:	Function value == true, if length == 0,
//								   == false, otherwise.	
{
	return (length == 0);
}

//*************************************************************************************************

bool SortedList::Isfull() const
//	Postcondition:	Function value == true, if length == MAX_LENGTH,
//								   == false, otherwise.	
{
	return (length == MAX_LENGTH);
}

//*************************************************************************************************

int  SortedList::Length() const
//	Postcondition:     Function value == true, if length == MAX_LENGTH,
//									  == false, otherwise.
{
	return length;
}

//*************************************************************************************************

void SortedList::Insert(/* in */	DataType item)
/*	Precondition:	!Isfull() && item is assigned.
Postcondition:	IF NOT Isfull()
item is in the list && Length() == Length()@entry + 1.
ELSE
do nothing.																 */
{
	if (!Isfull())
	{
		int i;			//index
		for (i = length - 1; i >= 0; i--)
		{
			if (item < data[i])
				data[i + 1] = data[i];
			else
				break;
		}
		data[i + 1] = item;
		length++;
	}
}

//*************************************************************************************************

void SortedList::Delete(/* in */	DataType item)
/*	This function is to delete an item from a list.
Precondition:	!Isempty() && item is assigned.
Postcondition:	IF NOT Isempty()
item is no longer in the list && Length() == Length()@entry - 1.
ELSE
do nothing.																 */
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (data[i] == item)
			break;
	}

	if (i < length)
	{
		for (; i < length - 1; i++)
		{
			data[i] = data[i + 1];
		}
		length--;
	}
}

//*************************************************************************************************

bool SortedList::IsPresent(/* in */	DataType item) const
//	Precondition:	item is assigned.
//	Postcondition:	function value == true, if item is in data[0..length-1]
//								   == false, otherwise.
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (data[i] == item)
			break;
	}

	return (i < length);
}

//*************************************************************************************************

void SortedList::Reset()
//	Postcondition:	currentPos is initialized.
{
	currentPos = 0;
}

//*************************************************************************************************

DataType SortedList::Next()
//	Precondition:	Before excuting this function, the iteration is at least initialized once
//					&&	no transformers excuted since the last call.
//	Postcondition:	Function value == the value on the current position.
//					And if the last one is at the end, then return from the beginning.
{
	DataType item;
	item = data[currentPos];

	//set the next current position
	if (currentPos == length - 1)
		currentPos = 0;
	else
		currentPos++;
	return item;
}

//*************************************************************************************************

void SortedList::InsertOnce(/* in */	DataType item)
/*	Precondition:	!Isfull() && item is assigned.
Postcondition:	IF NOT duplicated,
item is in the list && Length() == Length()@entry + 1.
ELSE
do nothing.																 */
{
	if (!IsPresent(item))
	{
		Insert(item);
	}
}

//*************************************************************************************************

void SortedList::Replace(/* in */	DataType oldItem,
	/* in */	DataType newItem)
	/*	Precondition:	!Isfull() && item is assigned.
	Postcondition:	the oldItem is replaced by newItem without moving position in the list.		 */
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (data[i] == oldItem)
			break;
	}

	if (i < length)
		data[i] = newItem;
}

//*************************************************************************************************

void SortedList::Print() const
//	Postcondition:Contents of data[0..length-1] are output, each item occupies one line.		 
{
	int i;
	for (i = 0; i < length; i++)
		cout << data[i] << endl;
}
