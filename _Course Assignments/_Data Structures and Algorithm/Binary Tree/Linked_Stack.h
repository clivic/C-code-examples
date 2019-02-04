//*******************************************************************
//	Stack(linked) specification (not STL)
//	version 2.1
//	General introduction:	
//		In this stack, the top node is the top of the stack and
//		the bottom is the last one in the linked stack.
//		And this data structure uses templates.
//	Updates(from version 2.0):
//		The linked structure now is two-way.
//	Note: 
//		using utility.h and utility.cpp
//		using Node.h 	
//		(this means when using this data structure, client should 
//		include the specified files into the project)
//*******************************************************************
#ifndef STACKL
#define STACKL

#include "utility.h"
#include "Node.h"

template <class Node_entry>
class Stack
{
public:
	Stack();
	Error_code Push(/* in  */ const Node_entry& item);
	Error_code Top(/* out */ Node_entry& item) const;
	Error_code Pop();
	bool Empty() const;
	bool Full() const;
	void Clear();
	int Size();
	Node<Node_entry>* GetTop() const;

	//safty guards
	~Stack();
	Stack& operator = (const Stack& original);
	Stack(const Stack& original);

private:
	int count;
	Node<Node_entry> *head;			//the top node(head)
};

//*******************************************************************

//	Stack(linked) implementation (not STL)
template <class Node_entry>
Stack <Node_entry>::Stack()
//	Pre:	none
//	Post:	initialized an empty stack
{
	count = 0;
	head = NULL;
}

template<class Node_entry>
Error_code Stack <Node_entry>::Pop()
//	Pre:	none
//	Post:	remove the one on the top (the head element)
{
	if (Empty())
		return underflow;
	Node<Node_entry> *p = head;
	head = head->next;
	if (head != NULL)
		head->precede = NULL;
	delete p;
	p = NULL;
	count--;
	return success;
}

template<class Node_entry>
Error_code Stack <Node_entry>::Push(/* in */ const Node_entry& item)
//	Pre:	none
//	Post:	push one item in the stack from the head
{
	Node<Node_entry> *p = new Node<Node_entry>(item, NULL, head);
	if (p == NULL)	return overflow;
	if (head != NULL)
		head->precede = p;
	head = p;
	count++;
	return success;
}

template<class Node_entry>
Error_code Stack <Node_entry>::Top(/* out */ Node_entry& item) const
//	Pre:	none
//	Post:	copy the value of top one into item
{
	if (Empty())
		return underflow;
	item = head->entry;
	return success;
}

template<class Node_entry>
Node <Node_entry>* Stack <Node_entry>::GetTop() const
//	Pre:	none.
//	Post:	the head pointer is returned.
{
	return head;
}

template<class Node_entry>
bool Stack <Node_entry>::Empty() const
//	Pre:	none.
//	Post:	if stack is empty return true, else false.
{
	return(head == NULL && count == 0);		//double insurance
}

template<class Node_entry>
bool Stack <Node_entry>::Full() const
//	Pre:	none
//	Post:	IF can't creat dynamic spaces return true, ELSE false
{
	Node *pNew = new Node;
	if (pNew == NULL) return true;
	delete pNew;
	pNew = NULL;
	return false;
}

template<class Node_entry>
void Stack <Node_entry>::Clear()
//	Pre:	none.
//	Post:	stack is reset to be empty.
{
	while (!Empty())	Pop();
	count = 0;
}

template<class Node_entry>
int Stack <Node_entry>::Size()
//	Pre:	none
//	Post:	return the size of the stack
{
	return count;
}

//safty guards
template<class Node_entry>
Stack <Node_entry>::~Stack()
//	Pre:	none.
//	Post:	stack is cleared.
{
	Clear();
}

template<class Node_entry>
Stack <Node_entry>& Stack <Node_entry>::operator = (const Stack <Node_entry>& original)
//	Pre:	There is no assurence for a newly allocated dynamic location
//			to fail in this function.
//	Post:	the stack is reset as a copy of Stack original.
{
	//judge for identity
	if (this == &original)	return *this;

	//clear then copy
	Clear();
	Node<Node_entry> * pTemp, *pNew, *po = original.GetTop();
	if (po == NULL)	head = NULL;
	else
	{
		pNew = pTemp = new Node<Node_entry>(po->entry);
		while (po->next != NULL)
		{
			po = po->next;
			pTemp->next = new Node<Node_entry>(po->entry,pTemp);
			pTemp = pTemp->next;
		}
		head = pNew;
	}
	count = original.Size();
	return *this;
}

template<class Node_entry>
Stack<Node_entry>::Stack(const Stack <Node_entry>& original)
//	Pre:	There is no assurence for a newly allocated dynamic location
//			to fail in this function.
//	Post:	copy constructor
{
	Node<Node_entry> * pTemp, *po = original.GetTop();
	if (po == NULL)	head = NULL;
	else
	{
		head = pTemp = new Node<Node_entry>(po->entry);
		while (po->next != NULL)
		{
			po = po->next;
			pTemp->next = new Node<Node_entry>(po->entry,pTemp);
			pTemp = pTemp->next;
		}
	}
	count = original.Size();
}
#endif