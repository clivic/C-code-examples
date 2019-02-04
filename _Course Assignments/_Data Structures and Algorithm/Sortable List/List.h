//*******************************************************************
//	Contiguous List Class's specification
//	It's a list using template, which could read and write in the
//	list at any position.
//	Besides, it can be derived.
//	Note:	using "Utility"'s utility .h and .cpp
//*******************************************************************
#ifndef LIST
#define LIST
#include "utility.h"
const int MAX_LIST = 20000;
template <class List_entry>
class List 
{
public:
	// methods of the List ADT
	List();
	int Size() const;
	bool Full() const;
	bool Empty() const;
	void Clear();
	void Traverse(void (*visit)(List_entry &));
	Error_code Retrieve(int position, List_entry &x) const;
	Error_code Replace(int position, const List_entry &x);
	Error_code Remove(int position, List_entry &x);
	Error_code Insert(int position, const List_entry &x);
protected:
	// data members for a contiguous list implementation
	int count;
	List_entry entry[MAX_LIST];
};

//*******************************************************************

//List Class Implementation
template <class List_entry>
List <List_entry>::List()
//	Post:	The List has been created and is initialized to be empty.
{
	count = 0;
}

template <class List_entry>
int List <List_entry>::Size() const
//	Post:	The function returns the number of entries in the List.
{
	return count;
}

template <class List_entry>
bool List <List_entry>::Full() const
//	Post:	The function returns true or false according to whether
//	the List is full or not.
{
	return (count == MAX_LIST);
}

template <class List_entry>
bool List <List_entry>::Empty() const
//	Post:	The function returns true or false according to whether
//	the List is empty or not.
{
	return (count == 0);
}

template <class List_entry>
void List <List_entry>::Clear()
//	Post:	The list is cleared with count equal to 0.
{
	count = 0;
}

template <class List_entry>
void List <List_entry>::Traverse(void (*visit)(List_entry &))
//	Post:	The action specified by function(*visit) has been performed on every entry of
//			the list, beginning at position 0 and doing each in turn. 
{
	for (int i = 0; i < count; i++)
		(*visit)(this->entry[i]);
}

template <class List_entry>
Error_code List <List_entry>::Retrieve(int position, List_entry &x) const
//	Post:	If	0 <= position < n, where n is the number of entries
//				in the List, the function succeeds: The entry at position
//				is copied to x; all List entries remain unchanged.
//			Else The function fails with a diagnostic error code(note, it's always
//				 range_exceed, so please notice (you can manually remove the "//"
//				 below to make the error code range_exceed be able to use)).
{
	//if (count == 0)	return underflow;	//to standardize the output, can be removed
	if (position >= count || position < 0)	return range_exceed;
	x = entry[position];
	return success;
}

template <class List_entry>
Error_code List <List_entry>::Replace(int position, const List_entry &x)
//	Post:	If	0 <= position < n, where n is the number of entries
//				in the List, the function succeeds: The entry at position
//				is replaced by x; all other entries remain unchanged.
//			Else The function fails with a diagnostic error code.
{
	if (position >= count || position < 0)	return range_exceed;
	entry[position] = x;
	return success;
}

template <class List_entry>
Error_code List <List_entry>::Remove(int position, List_entry &x)
//	Post:	If	0<= position < n, where n is the number of entries in
//				the List, the function succeeds: The entry at position is
//				removed from the List, and all later entries have their
//				position numbers decreased by 1. The parameter x
//				records a copy of the entry formerly at position.
//			Else The function fails with a diagnostic error code.
{
	if (Empty())	return underflow;
	if (position >= count || position < 0)	return range_exceed;
	int i = position;
	x = entry[i];
	for (; i < count - 1; i++)
		entry[i] = entry[i + 1];
	count--;
	return success;
}

template <class List_entry>
Error_code List <List_entry>::Insert(int position, const List_entry &x)
//	Post:	If	the List is not full and 0 <= position <= n; where n is the number of
//				entries in the List, the function succeeds: Any entry formerly at position and
//				all later entries have their position numbers increased by 1 and x is inserted
//				at position of the List.
//			Else The function fails with a diagnostic error code.
{
	if (Full())	return overflow;
	if (position > count || position < 0)	return range_exceed;
	for (int i = count - 1; i >= position; i--)
		entry[i + 1] = entry[i];
	entry[position] = x;
	count++;
	return success;
}
#endif