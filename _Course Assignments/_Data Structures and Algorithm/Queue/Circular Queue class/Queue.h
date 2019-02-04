//*******************************************************************
//	(Ultimate) Circular Queue's specification
//	It's a circular queue, a comparatively mature version of Queue
//	class.
//	Besides, it can be derived.
//	Note:	using "Utility"'s utility .h and .cpp
//*******************************************************************
#ifndef CQ
#define CQ
#include "D:\Visual C++ programs\Utility\utility.h"

const int MAXQUEUE = 50;

template <class Queue_entry>
class Queue
{
public:
	Queue();
	Error_code Serve();
	Error_code Append(/* in */ const Queue_entry& item);
	Error_code Retrieve(/* out */ Queue_entry& item) const;
	bool Empty() const;
	bool Full() const;
	void Clear();
	int Size() const;
	Error_code ServeAndRetrieve(/* out */ Queue_entry& item);
	void Print();
protected:
	int count;
	int front, rear;
	Queue_entry entry[MAXQUEUE];	
};

#endif