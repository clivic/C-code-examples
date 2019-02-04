/**************************************************************************************************
List ADT specification (list.h)
This file gives the specification of a list abstract data type.
The list components are unsorted list.
**************************************************************************************************/
#include <iostream>

using namespace std;

typedef float DataType;

const int MAX_LENGTH = 100;

class List
{
public:
	List();
	/*	This constructor initializes the list to be empty.
		Postcondition:	list is empty.															 */

	bool Isempty();
	/*	This function is to verify the state of whether empty.
		Postcondition:	Function value == true, if list is empty
									   == false, otherwise.										 */
	bool Isfull();
	/*	This function is to verify the state of whether full.
		Postcondition:	Function value == true, if list is full,
									   == false, otherwise.										 */
																												 
	int  Length();
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
	
	bool IsPresent	(/* in */	DataType item);
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



/**************************************************************************************************
IMPLEMENTATION FILE (list.cpp)
This file implements the List class member functions.
List representation: a one-dimensional array and a length variable.                     
**************************************************************************************************/

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

bool List::Isempty()
//	Postcondition:	Function value == true, if length == 0,
//								   == false, otherwise.	
{
	return (length == 0);
}

//*************************************************************************************************

bool List::Isfull()
//	Postcondition:	Function value == true, if length == MAX_LENGTH,
//								   == false, otherwise.	
{
	return (length == MAX_LENGTH);
}

//*************************************************************************************************

int  List::Length()
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

bool List::IsPresent	(/* in */	DataType item)
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

/**************************************************************************************************
This program is the client code.
**************************************************************************************************/

int main()
{
	List list;
	DataType a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	list.InsertOnce(a);
	list.InsertOnce(b);
	list.InsertOnce(c);
	list.InsertOnce(d);
	list.InsertOnce(e);
	
	//output
	list.Reset();
	DataType outputTemp;
	int limit = list.Length();
	int i;
	for (int i = 0; i < limit - 1; i++)
	{
		outputTemp = list.Next();
		cout << outputTemp << ' ';
	}
		outputTemp = list.Next();
		cout << outputTemp;		//format
	cout << endl;
	
	DataType old1, new1, old2, new2;
	cin >> old1 >> new1 >> old2 >> new2;
	list.Replace(old1, new1);
	list.Replace(old2, new2);
	
	//output
	list.Reset();
	for (i = 0; i < limit - 1; i++)
	{
		outputTemp = list.Next();
		cout << outputTemp << ' ';
	}
		outputTemp = list.Next();
		cout << outputTemp;		//format
	cout << endl;

	return 0;
}

