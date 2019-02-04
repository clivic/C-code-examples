/**************************************************************************************************
IMPLEMENTATION FILE (list.cpp)
This file implements the List class member functions.
List representation: a one-dimensional array and a length variable.                     
**************************************************************************************************/

#include <string>
#include "stdafx.h"					//to adapt the visual studio 2013
#include "D:\Visual C++ programs\To do list _ program problems 1 in chapter13\list.h"
#include <iostream>

using namespace std;

/*	Private members of class:
	int length;						//Length of the list
	DataType data[MAX_LENGTH];		//Array holding the list items								 */

//*************************************************************************************************

List::List()
//	constructor
//	Postcondition:	length == 0.															 
{
	length = 0;
}

//*************************************************************************************************

bool List::Isempty() const
//	Postcondition:	Function value == true, if length == 0,
//								   == false, otherwise.	
{
	return (length == 0);
}

//*************************************************************************************************

bool List::Isfull() const
//	Postcondition:	Function value == true, if length == MAX_LENGTH,
//								   == false, otherwise.	
{
	return (length == MAX_LENGTH);
}

//*************************************************************************************************

int  List::Length() const
//	Postcondition:     Function value == true, if length == MAX_LENGTH,
//									  == false, otherwise.
{
	return length;
}

//*************************************************************************************************

void List::Insert		(/* in */	DataType item)
/*	Precondition:	!Isfull() && item is assigned.
	Postcondition:	IF NOT Isfull()
						item is in the list && Length() == Length()@entry + 1.				
					ELSE
						do nothing.																 */
{
	if (!Isfull())
	{
		data[length] = item;
		length++;
	}
}

//*************************************************************************************************

void List::Delete		(/* in */	DataType item)
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
		data[i] = data[length - 1];
		length--;
	}
}

//*************************************************************************************************

bool List::IsPresent	(/* in */	DataType item) const
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

void List::Selsort()
//	Postcondition:	List components are in ascending order of value.
{
	DataType temp;			// temporary variable for swap
	int	passCount;			// loop control variable
	int searchIndx;			// index of iterration time
	int minIndx;			// index of minimum searching

	for (passCount = 0; passCount < length - 1; passCount++)
	{
		minIndx = passCount;

		// Find the index of the smallest component
		// in data[passCount..length-1]

		for (searchIndx = passCount + 1; searchIndx < length; searchIndx++)
			if (data[searchIndx] < data[minIndx])
				minIndx = searchIndx;

      // Swap data[minIndx] and data[passCount]
      temp = data[minIndx];
      data[minIndx] = data[passCount];
      data[passCount] = temp;
   }
}

//*************************************************************************************************

void List::Reset()
//	Postcondition:	currentPos is initialized.
{
	currentPos = 0;
}

//*************************************************************************************************

DataType List::Next()
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

void List::InsertOnce (/* in */	DataType item)
/*	Precondition:	!Isfull() && item is assigned.
	Postcondition:	IF NOT duplicated,
						item is in the list && Length() == Length()@entry + 1.
					ELSE
						do nothing.																 */
{
	if (!Isfull() && !IsPresent(item))
	{
		data[length] = item;
		length++;
	}
}

//*************************************************************************************************

void List::Replace	(/* in */	DataType oldItem,
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

void List::Print() const
//	Postcondition:Contents of data[0..length-1] are output, each item occupies one line.		 
{
	int i;
	for (i = 0; i < length; i++)
        cout << data[i] << endl;
}
