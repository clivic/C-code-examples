//*******************************************************************
//	Linked List Class(two-way)'s specification
//	General introduction:
//		It's a list using template, which could read and write in the
//		list at any position.
//		Besides, it can be derived.
//	Note:	using "Utility"'s utility .h and .cpp
//*******************************************************************
#ifndef LINKED_LIST
#define LINKED_LIST
#include "utility.h"
#include "Node.h"
template <class List_entry>
class List
{
public:
	// fundamental methods of the List ADT
	List();
	int Size() const;
	bool Full() const;
	bool Empty() const;
	void Clear();
	void Traverse(void(*visit)(List_entry &));
	Error_code Retrieve(int position, List_entry &x) const;
	Error_code Replace(int position, const List_entry &x);
	Error_code Remove(int position, List_entry &x);
	Error_code Insert(int position, const List_entry &x);

	//safty guards
	~List();
	List(const List<List_entry> &copy);
	void operator = (const List<List_entry> &copy);

protected:
	// data members for a contiguous list implementation
	int count;
	Node<List_entry> *head;
	mutable int currentPos;
	mutable Node<List_entry> *current;

	//protected tool function
	Node<List_entry> *SetPos(int pos) const;
};

//*******************************************************************

//List Class Implementation
template <class List_entry>
List <List_entry>::List()
//	Post:	The List has been created and is initialized to be empty.
//			And current position is set to 0 -- NULL.
{
	count = 0;
	head = NULL;
	current = head;
	currentPos = 0;
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
//			the List is full or not.
{
	Node<List_entry> *newNode;
	newNode = new Node<List_entry>;
	if (newNode == NULL)	return true;
	else 
	{
		delete newNode;
		return false;
	}
}

template <class List_entry>
bool List <List_entry>::Empty() const
//	Post:	The function returns true or false according to whether
//			the List is empty or not.
{
	return (count == 0);
}

template <class List_entry>
void List <List_entry>::Clear()
//	Post:	The list is cleared with count equal to 0.
{
	List_entry x;
	while (!Empty())	Remove(0, x);
}

template <class List_entry>
void List <List_entry>::Traverse(void(*visit)(List_entry &))
//	Post:	The action specified by function(*visit) has been performed on every entry of
//			the list, beginning at position 0 and doing each in turn. 
{
	Node<List_entry> *p_node = head;
	while (p_node != NULL)
	{
		(*visit)(p_node->entry);
		p_node = p_node->next;
	}
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
	if (position < 0 || position >= count)
		return range_exceed;
	x = SetPos(position)->entry;
	return success;
}

template <class List_entry>
Error_code List <List_entry>::Replace(int position, const List_entry &x)
//	Post:	If	0 <= position < n, where n is the number of entries
//				in the List, the function succeeds: The entry at position
//				is replaced by x; all other entries remain unchanged.
//			Else The function fails with a diagnostic error code.
{
	if (position < 0 || position >= count)
		return range_exceed;
	SetPos(position)->entry = x;
	return success;
}

template <class List_entry>
Error_code List <List_entry>::Remove(int position, List_entry &x)
//	Post:	If	0<= position < n, where n is the number of entries in
//				the List, the function succeeds: The entry at position is
//				removed from the List, and all later entries have their
//				position numbers decreased by 1. The parameter x
//				records a copy of the entry formerly at position.
//				Besides, currentPos is at the head.
//			Else The function fails with a diagnostic error code.
{
	if (position < 0 || position >= count)
		return range_exceed;
	Node<List_entry> *previous, *following;
	if (position != 0)
	{
		previous = SetPos(position - 1);
		following = previous->next;
		previous->next = following->next;
		if (following->next != NULL)
			following->next->precede = previous;
	}
	else
	{
		following = head;
		head = head->next;
		if (head != NULL)
			head->precede = NULL;
		//Should be added
		currentPos = 0;
		current = head;
	}
	delete following;
	count--;
	return success;
}

template <class List_entry>
Error_code List <List_entry>::Insert(int position, const List_entry &x)
//	Post:	If	the List is not full and 0 <= position <= n; where n is the number of
//				entries in the List, the function succeeds: entry x is inserted into
//				the list, at the position, and any entry formerly at position and
//				all later entries have their position numbers increased by 1.
//			Else The function fails with a diagnostic error code.
{
	Node<List_entry> *newNode, *following, *preceding;
	if (position < 0 || position > count)
		return range_exceed;

	if (position == 0) 
	{
		if (count == 0) following = NULL;
		else 
		{
			SetPos(0);
			following = current;
		}
		preceding = NULL;
	}
	else 
	{
		SetPos(position - 1);
		preceding = current;
		following = preceding->next;
	}
	newNode = new Node<List_entry>(x, preceding, following);

	if (newNode == NULL) return overflow;
	if (preceding != NULL) preceding->next = newNode;
	if (following != NULL) following->precede = newNode;
	current = newNode;
	currentPos = position;

	if (position == 0)head = newNode;
	count++;
	return success;
}

//safty guards
template <class List_entry>
List <List_entry>::~List()
{
	Clear();
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy)
{
	count = 0;
	head = NULL;
	currentPos = 0;
	current = NULL;
	Node<List_entry> *newNode = copy.head;
	for (int i = 0; newNode != NULL; i++)
	{
		Insert(i, newNode->entry);
		newNode = newNode->next;	
	}
}

template <class List_entry>
void List<List_entry>:: operator = (const List<List_entry> &copy)
{
	Clear();
	Node<List_entry> *newNode = copy.head;
	for (int i = 0; newNode != NULL; i++)
	{
		Insert(i, newNode->entry);
		newNode = newNode->next;
	}
}

//protected tool function
template <class List_entry>
Node<List_entry> *List<List_entry>::SetPos(int position) const
//	Pre:	position is a valid position in the List: 0 <= position < count.
//	Post:	The current Node pointer references the Node at position.
{
	if (currentPos <= position)
		for (; currentPos != position; currentPos++)
			current = current->next;
	else
		for (; currentPos != position; currentPos--)
			current = current->precede;
	return current;
}

#endif