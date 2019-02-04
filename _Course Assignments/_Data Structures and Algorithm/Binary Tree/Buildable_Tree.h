//*******************************************************************
//	BuildableTree class specification
//*******************************************************************
#ifndef BUILDTREE
#define BUILDTREE
#include "Key and Record.h"
#include "Search_Tree.h"


template <class Record>
class BuildableTree : public SearchTree<Record>
{
public:
	Error_code BuildTree(const List<Record> &supply);

protected: 
	void BuildInsert(int count, const Record &newData, List < BinaryNode<Record>* > &lastNode);
	BinaryNode<Record> * FindRoot(const List < BinaryNode<Record>* > &lastNode);
	void ConnectTrees(const List < BinaryNode<Record>* > &lastNode)
};

//*******************************************************************

//	BuildableTree class implementation
template <class Record>
Error_code BuildableTree<Record>::BuildTree(const List<Record> &supply)
//	Post:	If the entries of supply are in increasing order, a code 
//			of success is returned and the Search tree is built out 
//			of these entries as a balanced tree. Otherwise, a code 
//			of fail is returned and a balanced tree is constructed 
//			from the longest increasing sequence of entries at the 
//			start of supply.
//	Uses:	The methods of class List; the functions BuildInsert, 
//			connect_subtrees, and FindRoot.
{
	Error_code orderedData = success;
	//set this tofail if keys do not increase.
	//rem it for our BinaryTree int count.
	Record x, last_x;
	List < BinaryNode<Record> * > lastNode;
	//pointers to last nodes on each level
	BinaryNode<Record> *none = NULL;
	lastNode.Insert(0, none); //permanently NULL (for children of leaves)
	while (supply.Retrieve(count, x) == success) 
	{
		if (count > 0 && x <= last_x) 
		{
			orderedData = fail;
			break;
		}
		BuildInsert(++count, x, lastNode);
		last_x = x;
	}
	root = FindRoot(lastNode);
	ConnectTrees(lastNode);
	return orderedData; //Report any data-ordering problems back to client.
}

template <class Record>
void BuildableTree<Record> ::
BuildInsert(int count, const Record &newData,
List < BinaryNode<Record>* > &lastNode)
//	Post:	A new node, containing the Record new data, has been 
//			Inserted as the right most node of a partially completed 
//			binary search tree. The level of this new node is one 
//			more than the highest power of 2 that divides count.
//	Uses:	Methods of class List. 
{
	int level; //level of new node above the leaves, counting inclusively
	for (level = 1; count % 2 == 0; level++)
		count /= 2; //Use count to calculate level of next node .
	BinaryNode<Record>
		*nextNode = new BinaryNode<Record>(newData),
		*parent; //one level higher in last node
	lastNode.Retrieve(level - 1, nextNode->left);
	if (lastNode.Size() <= level)
		lastNode.Insert(level, nextNode);
	else
		lastNode.replace(level, nextNode);

	if (lastNode.Retrieve(level + 1, parent) == success &&	parent->right == NULL)
		parent->right = nextNode;
}

template <class Record>
BinaryNode<Record> *BuildableTree<Record> ::FindRoot(
	const List < BinaryNode<Record>* > &lastNode)
//	Pre:	The list last node contains pointers to the last node on 
//			each occupied level of the binary search tree.
//	Post:	A pointer to the root of the newly created binary search 
//			tree is returned.
//	Uses:	Methods of classList.
{
	BinaryNode<Record> *highNode;
	lastNode.Retrieve(lastNode.Size() - 1, highNode);
	//Find root in the highest occupied level in last node .
	return highNode;
}

template <class Record>
void BuildableTree<Record> ::ConnectTrees(
	const List < BinaryNode<Record>* > &lastNode)
//	Pre:	The nearly-completed binary search tree has been 
//			initialized. List last node has been initialized and 
//			contains links to the last node on each level of the tree.
//	Post:	The final links have been added to complete the binary 
//			search tree.
//	Uses:	Methods of class List. 
{
	BinaryNode<Record>
		*highNode, //from last node with NULL right child
		*lowNode; //candidate for right child of high node
	int highLevel = lastNode.Size() - 1, lowLevel;
	while (highLevel > 2) //Nodes on levels 1 and 2 are already OK.
	{ 
		lastNode.Retrieve(highLevel, highNode);
		if (highNode->right != NULL)
			highLevel--;	//Search down for highest dangling node.
		else				//Case: undefined right tree
		{ 
			lowLevel = highLevel;
			do 
			{ //Find the highest entry not in the left subtree.
				lastNode.Retrieve(--lowLevel, lowNode);
			} while (lowNode != NULL && lowNode->data < highNode->data);
			highNode->right = lowNode;
			highLevel = lowLevel;
		}
	}
}

#endif