//*******************************************************************
//	BNode Class's specification
//	General introduction:
//		It is the fundamental node of a Balanced Multiway Search 
//		Tree(BTree), containing key and pointer storage. 
//	Notes:	
//		The BNode is strongly recommended to be used in the form of 
//		struct Record.(for it is also a search tree.
//*******************************************************************
#ifndef BNODE
#define BNODE
#include "utility.h"

template <class Record, int order>
struct BNode 
{
	// constructor:
	BNode( );

	// data members:
	int count;
	Record data[order - 1];
	BNode<Record, order> *branch[order];
};

//*******************************************************************

//	BNode Class's implementation
template <class Record, int order>
BNode<Record, order>::BNode()
{
	// data members:
	count = 0;
}

#endif