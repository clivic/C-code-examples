//*******************************************************************
//	Stack(linked) specification (not STL)
//	In this stack, the top node is the top of the stack and
//	the bottom is the last one in the linked stack.
//	Note: don't use it along with other Stack class
//	(eg. stacks that implemented by array)
//	And please notice that the first letter of every function has
//	been capitalized for the unite of data structures.
//*******************************************************************
#ifndef STACKL
#define STACKL

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
class Stack
{
public:
	Stack();
	Error_code Push(/* in */ const Node_entry& item);
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

#endif