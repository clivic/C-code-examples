#ifndef STACK
#define STACK

#include "D:\Visual C++ programs\Utility\utility.h"

const int MAXSTACK = 50;

template <class Stack_entry>

class Stack
{
	public:
		Stack();
		Error_code push(/* in */ const Stack_entry& item);
		Error_code top(/* out */ Stack_entry& item) const;
		Error_code pop();
		bool empty() const;
		void clear();
		bool full() const;
		int size();

	private:
		int count;
		Stack_entry entry[MAXSTACK];
};

#endif