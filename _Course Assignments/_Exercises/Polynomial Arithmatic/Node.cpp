//*******************************************************************
//	This is the Node implementation for LINKED STRUCTURES
//*******************************************************************
#include "Node.h"

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