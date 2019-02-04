//*******************************************************************
//	(Ultimate) Circular Queue's implementation
//*******************************************************************
#include "Queue.h"

template <class Queue_entry>
Queue <Queue_entry>::Queue()
//	Pre:	none
//	Post:	Queue is initialized
{
	count = 0;
	front = 0;
	rear = MAXQUEUE - 1;
}

template <class Queue_entry>
bool Queue <Queue_entry>::Empty() const
//	Pre:	none
//	Post:	IF empty return true, ELSE false
{
	return count == 0;
}

template <class Queue_entry>
bool Queue <Queue_entry>::Full() const
//	Pre:	none
//	Post:	IF empty return true, ELSE false
{
	return count == MAXQUEUE;
}

template <class Queue_entry>
Error_code Queue <Queue_entry>::Append(/* in */ const Queue_entry& item)
//	Pre:	none
//	Post:	new item added
{
	if (Full())	return overflow;
	rear = (rear + 1) % MAXQUEUE;
	entry[rear] = item;
	count++;
	return success;
}

template <class Queue_entry>
Error_code Queue <Queue_entry>::Serve()
//	Pre:	none
//	Post:	remove the first item
{
	if (Empty()) return underflow;
	front = (front + 1) % MAXQUEUE;
	count--;
	return success;
}

template <class Queue_entry>
Error_code Queue <Queue_entry>::Retrieve(/* out */ Queue_entry& item) const
//	Pre:	none
//	Post:	the front entry is copied to the item
{
	if (Empty())	return underflow;
	item = entry[front];
	return success;
}

template <class Queue_entry>
Error_code Queue <Queue_entry>::ServeAndRetrieve(/* out */ Queue_entry& item)
//	Pre:	none
//	Post:	the front entry is copied to the item and served
{
	if (Retrieve(item) == underflow) return underflow;
	Serve();
	return success;
}

template <class Queue_entry>
void Queue <Queue_entry>::Clear()
//	Pre:	none
//	Post:	front and rear and count are reset default
{
	count = 0;
	front = 0;
	rear = MAXQUEUE - 1;
}

template <class Queue_entry>
int Queue <Queue_entry>::Size() const
//	Pre:	none
//	Post:	return how many elements the queue contains
{
	return count;
}

template <class Queue_entry>
void Queue <Queue_entry>::Print()
//	Pre:	Type Queue_entry should be printable
//	Post:	print all the numbers in Queue
//	Note:	this function is bounded with std::cout
//			and clients can make thier own print functions
{
	if (Empty())
	{
		cout << "Empty Queue.\n" << flush;
		return;
	}
	Queue_entry item;
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