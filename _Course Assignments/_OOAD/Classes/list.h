/**************************************************************************************************
List ADT specification (list.h)
This file gives the specification of a list abstract data type.
The list components are unsorted list.
**************************************************************************************************/
#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

typedef string DataType;

const int MAX_LENGTH = 100;

class List
{
public:
	List();
	/*	This constructor initializes the list to be empty.
		Postcondition:	list is empty.															 */

	bool Isempty() const;
	/*	This function is to verify the state of whether empty.
		Postcondition:	Function value == true, if list is empty
									   == false, otherwise.										 */
	bool Isfull() const;
	/*	This function is to verify the state of whether full.
		Postcondition:	Function value == true, if list is full,
									   == false, otherwise.										 */
																												 
	int  Length() const;
	/*	This function is to take the length of the list.
		Postcondition:	Function value Function value == length of list.						 */
													
	void Insert		(/* in */	DataType item);
	/*	This function is to insert an item into a list.
		Precondition:	!Isfull() && item is assigned.
		Postcondition:	IF NOT Isfull()
							item is in the list && Length() == Length()@entry + 1.				
						ELSE
							do nothing.															 */

	void Delete		(/* in */	DataType item);
	/*	This function is to delete an item from a list.
		Precondition:	!Isempty() && item is assigned.
		Postcondition:	IF NOT Isempty()
							item is no longer in the list && Length() == Length()@entry - 1.	
						ELSE
							do nothing.															 */
	
	bool IsPresent	(/* in */	DataType item) const;
	/*	This function is to verify if an item is in a list.
		Precondition:	item is assigned.
		Postcondition:	Function value == true, if the item is found,
									   == false, otherwise.										 */
	
	void Selsort();
	/*	This function is to sort the list.
		Postcondition:	List components are in ascending order of value.						 */
	
	void Reset();
	/*	This function is to initialize the iteration.
		Postcondition:	Iteration is initialized.												 */

	DataType Next();
	/*	This function is to get next item in the list to the operation.
		Precondition:	Before excuting this function, the iteration is at least initialized once
						&&	no transformers excuted since the last call.
		Postcondition:	Function value == the value on the current position.
						And if the last one is at the end, then return from the beginning.		 */

	void InsertOnce (/* in */	DataType item);
	/*	This function is to insert a non-duplicated item into a list.
		Precondition:	!Isfull() && item is assigned.
		Postcondition:	IF NOT duplicated,
							item is in the list && Length() == Length()@entry + 1.
						ELSE
							do nothing.															 */
	
	void Replace	(/* in */	DataType oldItem,
					 /* in */	DataType newItem);
	/*	This function is to replace an item in a list by another item.
		Precondition:	!Isfull() && item is assigned.
		Postcondition:	the oldItem is replaced by newItem without moving position in the list.  */

	void Print() const;
	/*	This function is to provide an easy way for client to output the aggregate list.
		Postcondition:	the list is entirely output, each item occupies one line.				 */

private:
	int length;
	int currentPos;
	DataType data[MAX_LENGTH];
};

#endif