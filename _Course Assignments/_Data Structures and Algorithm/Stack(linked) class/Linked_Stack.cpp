//*******************************************************************
//	Stack(linked) implementation (not STL)
//	And please remember to add Linked_Stack.cpp when using it.
//	In this stack, the top node is the top of the stack and
//	the bottom is the last one in the linked stack.
//	Note: don't use it along with other Stack class
//	(eg. stacks that implemented by array)
//*******************************************************************
#include "Linked_Stack.h"
//*******************************************************************

template <class Node_entry>
Node <Node_entry>::Node()
{
	next = NULL;
}

template <class Node_entry>
Node <Node_entry>::Node(/* in */ Node_entry item,
	/* in */ Node* addOn)
{
	entry = item;
	next = addOn;
}

//*******************************************************************

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
	delete p;
	count--;
	return success;
}

template<class Node_entry>
Error_code Stack <Node_entry>::Push(/* in */ const Node_entry& item)
//	Pre:	none
//	Post:	push one item in the stack from the head
{
	Node<Node_entry> *p = new Node<Node_entry>(item, head);
	if (p == NULL)	return overflow;
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
Node<Node_entry>* Stack <Node_entry>::GetTop() const
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
			pTemp->next = new Node<Node_entry>(po->entry);
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
			pTemp->next = new Node<Node_entry>(po->entry);
			pTemp = pTemp->next;
		}
	}
	count = original.Size();
}