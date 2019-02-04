//*******************************************************************
//	BinaryNode struct specification
//	General introduction:
//		It is the fundamental node of a tree.
//*******************************************************************
#ifndef BNODE
#define BNODE
#include "utility.h"

//balance factors for derived class AVLNode:
enum BalanceFactor{ LEFT_HIGHER, EQUAL_HEIGHT, RIGHT_HIGHER };

template <class Tree_Entry>
struct BinaryNode 
{
	//data members:
	Tree_Entry data;
	BinaryNode<Tree_Entry> *left;
	BinaryNode<Tree_Entry> *right;

	//constructors:
	BinaryNode();
	BinaryNode(const Tree_Entry &x);

	// virtual methods for derived class AVLNode:
	virtual void SetBalance(BalanceFactor b);
	virtual BalanceFactor GetBalance() const;
};

//*******************************************************************

//	Binary Node struct implementation
template <class Tree_Entry>
BinaryNode<Tree_Entry> ::BinaryNode()
{
	left = NULL;
	right = NULL;
}

template <class Tree_Entry>
BinaryNode<Tree_Entry> ::BinaryNode(const Tree_Entry &x)
{
	data = x;
	left = NULL;
	right = NULL;
}

//	dummy implementation
template <class Tree_Entry>
void BinaryNode<Tree_Entry>::SetBalance(BalanceFactor b){}

template <class Tree_Entry>
BalanceFactor BinaryNode<Tree_Entry>::GetBalance() const
{
	return EQUAL_HEIGHT;
}

#endif