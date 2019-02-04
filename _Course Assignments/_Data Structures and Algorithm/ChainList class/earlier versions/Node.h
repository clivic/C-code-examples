//*******************************************************************
//	This is the Node specification for LINKED STRUCTURES
//	linked data structures should include this .h and .cpp to run 
//	properly, like Linked_Stack class etc.
//	its implementation is included in client for the use of tmeplate.
//*******************************************************************
#ifndef NODE
#define NODE
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

//*******************************************************************

//Node implementation
template <class Node_entry>
Node <Node_entry>::Node()
{
	next = NULL;
}

template <class Node_entry>
Node <Node_entry>::Node(/* in */ Node_entry item, /* in */ Node* addOn)
{
	entry = item;
	next = addOn;
}

#endif