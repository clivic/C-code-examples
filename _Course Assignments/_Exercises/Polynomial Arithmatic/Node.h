//*******************************************************************
//	Node specification for LINKED STRUCTURES
//	version 2.0
//	General introduction:	
//		This Node headerfile defines the fundamental Node used by 
//		linked structures.
//	Updates:
//		It integrate the specification and implementation of the 
//		Node class into this head file, for convenient use
//		of clients. (only need to include this header file)
//	Notes:
//		linked data structures should include this header file into 
//		the project to run properly, like Linked_Stack class etc.
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