//*******************************************************************
//	Traditional Queue's specification
//	It's a physical queue, like the linear queue but doesn't contain
//	the problem of brimming in exchange of efficiency.
//	Besides, it can be derived.
//	Note:	using "Utility"'s utility .h and .cpp
//*******************************************************************
#ifndef PQ
#define PQ
#include "D:\Visual C++ programs\Utility\utility.h"

const int MAXQUEUE = 50;

template <class Queue_entry>
class PQueue
{
public:
	PQueue();
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
	int rear;
	const int front = 0;
	Queue_entry entry[MAXQUEUE];	
};

#endif