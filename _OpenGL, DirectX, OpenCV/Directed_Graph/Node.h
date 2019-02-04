//*******************************************************************
//	Node specification for LINKED STRUCTURES
//	version 2.1
//	General introduction:	
//		This Node headerfile defines the fundamental Node used by 
//		linked structures.
//	Updates:
//		1.	It integrate the specification and implementation of the 
//			Node class into this head file, for convenient use
//			of clients. (only need to include this header file)
//		2.	It has been modified to be two-way node, to adapt
//			Linked Stack and Queue in the same version.
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
	Node(/* in */ Node_entry item,
		/* in */ Node* previous = NULL,
		/* in */ Node* addOn = NULL);

	//data members
	Node_entry entry;
	Node* next;
	Node* precede;
};

//*******************************************************************

//Node implementation
template <class Node_entry>
Node <Node_entry>::Node()
{
	precede = NULL;
	next = NULL;
}

template <class Node_entry>
Node <Node_entry>::Node(/* in */ Node_entry item,
						/* in */ Node* previous,
						/* in */ Node* addOn)
{
	entry = item;
	precede = previous;
	next = addOn;
}

#endif