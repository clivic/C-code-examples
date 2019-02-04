//*******************************************************************
//	Queue(linked) specification (not STL)
//	In this queue, the top node is the top of the queue and
//	the bottom is the last one in the linked queue.
//	Note: don't use it along with other queue class
//		  (eg. queues that implemented by array)
//		  && using "Utility"'s utility .h and .cpp
//*******************************************************************
#ifndef QUEUEL
#define QUEUEL
#include "D:\Visual C++ programs\Utility\utility.h"


template <class Node_entry>
struct Node
{
	//encapsulation
	//friend Stack<Node_entry>;

	//constructors
	Node();
	Node(/* in */ Node_entry item, /* in */ Node* addOn = NULL);

	//data members
	Node_entry entry;
	Node* next;
};

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

#endif