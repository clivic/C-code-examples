//*******************************************************************
//	AVL_Node Class's specification
//	General introduction:
//		It is the fundamental node of an AVL tree, containing balance
//		factor for autobanlance operation. 
//	Notes:	
//		The AVLNode class is derived from BinaryNode class, and only 
//		available to entries in the form of struct Record.(for it's
//		a search tree)
//	Uses:	
//		BinaryNode class.
//*******************************************************************
#ifndef AVLNODE
#define AVLNODE
#include "Binary_Node.h"

template <class Record>
struct AVLNode: public BinaryNode<Record> 
{
	BalanceFactor balance;
// constructors:
	AVLNode();
	AVLNode(const Record &x);
// overridden virtual functions:
	void SetBalance(BalanceFactor b);
	BalanceFactor GetBalance() const;
};

//*******************************************************************

//AVL_Node Class's implementation
template <class Record>
AVLNode<Record> ::AVLNode()
{
	left = NULL;
	right = NULL;
	balance = EQUAL_HEIGHT;
}

template <class Record>
AVLNode<Record> ::AVLNode(const Record &x)
{
	data = x;
	left = NULL;
	right = NULL;
	balance = EQUAL_HEIGHT;
}

template <class Record>
void AVLNode<Record> ::SetBalance(BalanceFactor b)
{
	balance = b;
}

template <class Record>
BalanceFactor AVLNode<Record> ::GetBalance() const
{
	return balance;
}

#endif