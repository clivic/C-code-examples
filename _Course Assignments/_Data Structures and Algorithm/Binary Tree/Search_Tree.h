//*******************************************************************
//	SearchTree class specification
//*******************************************************************
#ifndef SEARCHTREE
#define SEARCHTREE
#include "Binary_Tree.h"

template <class Record>
class SearchTree: public BinaryTree<Record> 
{
public:
	Error_code Insert(const Record &newData);
	Error_code Remove(const Record &target);
	Error_code TreeSearch(Record &target) const;

protected:
	BinaryNode<Record> *SearchForNode(BinaryNode<Record>* subRoot, const Record &target) const;
	Error_code SearchAndInsert(BinaryNode<Record>* &subRoot, const Record &newData);
	Error_code SearchAndDestroy(BinaryNode<Record>* &subRoot, const Record &target);
	Error_code RemoveRoot(BinaryNode<Record>* &subRoot);
};

//*******************************************************************

//	SearchTree class implementation
template <class Record>
BinaryNode<Record> *SearchTree<Record> ::SearchForNode(
	BinaryNode<Record>* subRoot, const Record &target) const
{
	if (subRoot == NULL || subRoot->data == target)
		return subRoot;
	else if (subRoot->data < target)
		return SearchForNode(subRoot->right, target);
	else return SearchForNode(subRoot->left, target);
}

//Nonrecursive version:
/*template <class Record>
BinaryNode<Record> *SearchTree<Record> :: SearchForNode(
BinaryNode<Record>* subRoot, const Record &target) const
{
while (subRoot != NULL && subRoot->data != target)
if (subRoot->data < target) subRoot = subRoot->right;
else subRoot = subRoot->left;
return subRoot;
}
*/

template <class Record>
Error_code SearchTree<Record> ::TreeSearch(Record &target) const
{
	Error_code result = success;
	BinaryNode<Record> *found = SearchForNode(root, target);
	if (found == NULL)
		result = not_present;
	else
		target = found->data;
	return result;
}

template <class Record>
Error_code SearchTree<Record> ::Insert(const Record &newData)
{
	Error_code result = SearchAndInsert(root, newData);
	if (result == success)count++;
	return result;
}

template <class Record>
Error_code SearchTree<Record> ::SearchAndInsert(
	BinaryNode<Record> * &subRoot, const Record &newData)
{
	if (subRoot == NULL) 
	{
		subRoot = new BinaryNode<Record>(newData);
		return success;
	}
	else if (newData < subRoot->data)
		return SearchAndInsert(subRoot->left, newData);
	else if (newData > subRoot->data)
		return SearchAndInsert(subRoot->right, newData);
	else return duplicate_error;
}

template <class Record>
Error_code SearchTree<Record> ::Remove(const Record &target)
//	Post:	If a Record with a key matching that of target belongs to 
//			the Search tree a code of success is returned and the 
//			corresponding node is Removed from the tree. Otherwise, 
//			a code of not present is returned.
//	Uses:	Function SearchAndDestroy. 
{
	Error_code result = SearchAndDestroy(root, target);
	if (result == success)	count--;
	return result;
}

template <class Record>
Error_code SearchTree<Record> ::SearchAndDestroy(
	BinaryNode<Record>* &subRoot, const Record &target)
//	Pre:	sub root is either NULL or points to a subtree of the 
//			Search tree.
//	Post:	If the key of target is not in the subtree, a code of 
//			not_present is returned.
//			Otherwise, a code of success is returned and the subtree 
//			node containing target has been Removed in such a way 
//			that the properties of a binary search tree have been 
//			preserved.
//	Uses:	Functions search and destroy recursively and Remove root.
{
	if (subRoot == NULL || subRoot->data == target)
		return RemoveRoot(subRoot);
	else if (target < subRoot->data)
		return SearchAndDestroy(subRoot->left, target);
	else
		return SearchAndDestroy(subRoot->right, target);
}

template <class Record>
Error_code SearchTree<Record> ::RemoveRoot(BinaryNode<Record> * &subRoot)
//	Pre:	sub root is either NULL or points to a subtree of the 
//			Search tree.
//	Post:	If sub root is NULL , a code of not_present is returned. 
//			Otherwise, the root of the subtree is Removed in such a 
//			way that the properties of a binary search tree are 
//			preserved. The parameter sub root is reset as the root 
//			of the modified subtree, and success is returned. 
{
	if (subRoot == NULL) return not_present;
	BinaryNode<Record> *to_delete = subRoot;

	// Remember node to delete at end.
	if (subRoot->right == NULL) subRoot = subRoot->left;
	else if (subRoot->left == NULL) subRoot = subRoot->right;
	else							// Neither subtree is empty.
	{ 
		to_delete = subRoot->left; // Move left to find predecessor.	
		BinaryNode<Record> *parent = subRoot; // parent of to_delete
		while (to_delete->right != NULL) { // to_delete is not the predecessor.
			parent = to_delete;
			to_delete = to_delete->right;
		}
		subRoot->data = to_delete->data; // Move from to_delete to root.
		if (parent == subRoot) subRoot->left = to_delete->left;
		else parent->right = to_delete->left;
	}
	delete to_delete; // Remove to_delete from tree.
	return success;
}

#endif