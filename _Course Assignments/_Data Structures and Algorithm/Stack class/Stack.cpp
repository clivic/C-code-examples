//*******************************************************************
//	Stack implementation (not STL)
//	And please remember to add Stack.cpp when using it
//*******************************************************************
#include "Stack.h"

template<class Stack_entry>
Stack <Stack_entry>::Stack()
//	Pre:	none
//	Post:	initialized an empty stack
{
	count = 0;
}

template<class Stack_entry>
Error_code Stack <Stack_entry>::pop()
//	Pre:	none
//	Post:	remove the one on the top
{
	Error_code outcome = success;
	if (empty())
		outcome = underflow; 
	else
		count--;
	return outcome;
}

template<class Stack_entry>
Error_code Stack <Stack_entry>::push(/* in */ const Stack_entry& item)
//	Pre:	none
//	Post:	push one item in the stack
{
	Error_code outcome = success;
	if (full())
		outcome = overflow;
	else
	{
		entry[count] = item;
		count++;
	}
	return outcome;
}

template<class Stack_entry>
Error_code Stack <Stack_entry>::top(/* out */ Stack_entry& item) const
//	Pre:	none
//	Post:	copy the value of top one into item
{
	Error_code outcome = success;
	if (empty())
		outcome = underflow;
	else
		item = entry[count - 1];
	return outcome;
}

template<class Stack_entry>
bool Stack <Stack_entry>::empty() const
//	Pre:	none
//	Post:	if stack is empty return true, else false
{
	return (count == 0);
}

template<class Stack_entry>
bool Stack <Stack_entry>::full() const
//	Pre:	none
//	Post:	if stack is full return true, else false
{
	return (count == MAXSTACK);
}

template<class Stack_entry>
void Stack <Stack_entry>::clear()
//	Pre:	none
//	Post:	stack is reset to be empty
{
	count = 0;
}

template<class Stack_entry>
int Stack <Stack_entry>::size()
//	Pre:	none
//	Post:	return the size of the stack
{
	return count;
}