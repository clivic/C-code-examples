//*******************************************************************
//	Queue(linked) specification (not STL)
//	version 2.0
//	General introduction:	
//		In this queue, the top node is the top of the queue 
//		and the bottom is the last one in the linked queue.
//		And this data structure uses templates.
//	Updates:
//		It integrate the specification and implementation of the 
//		Linked Queue class into this head file, for convenient use
//		of clients. (only need to include this header file)
//	Note: 
//		using utility.h and utility.cpp
//		using Node.h 	
//		(this means when using this data structure, client should 
//		include the specified files into the project)
//*******************************************************************
#ifndef QUEUEL
#define QUEUEL
#include "utility.h"
#include "Node.h"

template <class Node_entry>
class Queue
{
public:
	Queue();
	Error_code Serve();
	Error_code Append(/* in */ const Node_entry& item);
	Error_code Retrieve(/* out */ Node_entry& item) const;
	bool Empty() const;
	bool Full() const;
	void Clear();
	int Size() const;
	Error_code ServeAndRetrieve(/* out */ Node_entry& item);
	void Print();
	Node<Node_entry>* GetFront() const;
	Node<Node_entry>* GetRear() const;

	//safty guards
	~Queue();
	Queue& operator = (const Queue& original);
	Queue(const Queue& original);

protected:
	int count;
	Node<Node_entry> *front, *rear;	
};

//*******************************************************************

//	Queue(linked) implementation (not STL)
template <class Node_entry>
Queue<Node_entry>::Queue()
//	Post:	Linked Queue is initialized, with no contains.
{
	front = rear = NULL;
	count = 0;
}

template <class Node_entry>
bool Queue <Node_entry>::Empty() const
//	Post:	IF empty return true, ELSE false
{
	//return count == 0;	//method 1
	return rear == NULL;	//method 2
	//return front == NULL;	//method 3
}

template <class Node_entry>
bool Queue <Node_entry>::Full() const
//	Post:	IF can't creat dynamic spaces return true, ELSE false
{
	Node *pNew = new Node;
	if (pNew == NULL) return true;
	delete pNew;
	pNew = NULL;
	return false;
}

template <class Node_entry>
Error_code Queue <Node_entry>::Append(/* in */ const Node_entry& item)
//	Post:	new item added
{
	Node<Node_entry> *pNew = new Node<Node_entry>(item);
	if (pNew == NULL)	return overflow;
	if (Empty())	front = rear = pNew;
	else
	{
		rear->next = pNew;
		rear = pNew;
	}
	count++;
	return success;
}

template <class Node_entry>
Error_code Queue <Node_entry>::Serve()
//	Post:	remove the first item
{
	if (Empty())	return underflow;
	Node<Node_entry> *pOld = front;
	front = pOld->next;
	if (front == NULL)	rear = NULL;
	delete pOld;
	pOld = NULL;
	count--;
	return success;
}

template <class Node_entry>
Error_code Queue <Node_entry>::Retrieve(/* out */ Node_entry& item) const
//	Post:	the front entry is copied to the item
{
	if (Empty())	return underflow;
	item = front->entry;
	return success;
}

template <class Node_entry>
Error_code Queue <Node_entry>::ServeAndRetrieve(/* out */ Node_entry& item)
//	Post:	the front entry is copied to the item and served
{
	if (Retrieve(item) == underflow) return underflow;
	Serve();
	return success;
}


template <class Node_entry>
void Queue <Node_entry>::Clear()
//	Post:	Queue is reset to be empty
{
	while (!Empty())	Serve();
	count = 0;
}

template <class Node_entry>
int Queue <Node_entry>::Size() const
//	Post:	return the size of the queue
{
	return count;
}

template <class Node_entry>
void Queue <Node_entry>::Print()
//	Pre:	Type Node_entry should be printable
//	Post:	print all the numbers in Queue
//	Note:	this function is bounded with std::cout
//			and clients can make thier own print functions
{
	if (Empty())
	{
		cout << "Empty Queue.\n" << flush;
		return;
	}
	Node_entry item;
	if (count == 1)
	{
		cout << "The element is:\n" << flush;
		Retrieve(item);
		cout << item << endl;
	}
	else
	{
		cout << "The elements are:\n" << flush;
		for (int i = 0; i < count; i++)
		{
			Retrieve(item);
			Serve();
			Append(item);
			cout << item << endl;
		}
	}
}

template <class Node_entry>
Node<Node_entry>* Queue <Node_entry>::GetFront() const
//	Post:	return the address of the first Node in Queue
{
	return front;
}

template <class Node_entry>
Node<Node_entry>* Queue <Node_entry>::GetRear() const
//	Post:	return the address of the last Node in Queue
{
	return rear;
}

//safty guards
template<class Node_entry>
Queue <Node_entry>::~Queue()
//	Post:	Queue is cleared
{
	Clear();
}

template<class Node_entry>
Queue <Node_entry>& Queue <Node_entry>::operator = (const Queue <Node_entry>& original)
//	Pre:	There is no assurence for a newly allocated dynamic location
//			to fail in this function
//	Post:	the queue is reset as a copy of Stack original
{
	//judge for identity
	if (this == &original)	return *this;

	//clear then copy
	Clear();
	Node<Node_entry> * pTemp, *pNew, *po = original.GetFront();
	if (po == NULL)
		front = rear = NULL;
	else
	{
		pNew = pTemp = new Node<Node_entry>(po->entry);
		while (po->next != NULL)
		{
			po = po->next;
			pTemp->next = new Node<Node_entry>(po->entry);
			pTemp = pTemp->next;
		}
		front = pNew;
		rear = po;
	}
	count = original.Size();
	return *this;
}

template<class Node_entry>
Queue <Node_entry>::Queue(const Queue& original)
//	Pre:	There is no assurence for a newly allocated dynamic location
//			to fail in this function
//	Post:	copy constructor
{
	Node<Node_entry> * pTemp, *pNew, *po = original.GetFront();
	if (po == NULL)
		front = rear = NULL;
	else
	{
		pNew = pTemp = new Node<Node_entry>(po->entry);
		while (po->next != NULL)
		{
			po = po->next;
			pTemp->next = new Node<Node_entry>(po->entry);
			pTemp = pTemp->next;
		}
		front = pNew;
		rear = po;
	}
	count = original.Size();
}

#endif