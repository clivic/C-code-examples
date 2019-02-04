//*******************************************************************
//	BinaryTree class specification
//*******************************************************************
#ifndef BINTREE
#define BINTREE
#include "Binary_Node.h"
#include "Linked_Stack.h"
#include "Linked_Queue.h"

template <class Tree_Entry>
class BinaryTree 
{
public:
	BinaryTree();
	bool Empty() const;
	void Preorder(void(*visit)(Tree_Entry &));
	void Inorder(void(*visit)(Tree_Entry &));
	void Postorder(void(*visit)(Tree_Entry &));
	void Travorder(void(*visit)(Tree_Entry &));
	int Size() const;
	int Height() const;
	int NumOfLeaves() const;
	Error_code Insert(Tree_Entry &);
	Error_code Remove(Tree_Entry &);
	void Interchange();
	void Clear();

	//safty guard
	BinaryTree(const BinaryTree<Tree_Entry> &original);	//copy constructor
	BinaryTree<Tree_Entry> &operator = (const BinaryTree<Tree_Entry> &original);
	~BinaryTree();										//destructor
	
protected:
	//auxillary functions
	void RecursivePreorder(BinaryNode<Tree_Entry> *subRoot, void(*visit)(Tree_Entry &));
	void RecursiveInorder(BinaryNode<Tree_Entry> *subRoot, void(*visit)(Tree_Entry &));
	void RecursivePostorder(BinaryNode<Tree_Entry> *subRoot, void(*visit)(Tree_Entry &));
	void RecursiveTravorder(Queue< BinaryNode<Tree_Entry>* > &q, void(*visit)(Tree_Entry &));
	int RecursiveCountLeaves(BinaryNode<Tree_Entry> *subRoot) const;
	void SubInterchange(BinaryNode<Tree_Entry>* &subRoot);
	void RecursiveCopy(Queue<Tree_Entry> &q, BinaryNode<Tree_Entry> *subRoot, BinaryNode<Tree_Entry> *subRootOrg);
	Error_code SearchAndDestroy(BinaryNode<Tree_Entry>* &subRoot, const Tree_Entry &target);
	Error_code RemoveRoot(BinaryNode<Tree_Entry>* &subRoot);	//for Remove
	void RecursiveDelete(BinaryNode<Tree_Entry>* &subRoot);		//for Clear

	//data members
	BinaryNode<Tree_Entry> *root;
	int count;
};

//*******************************************************************

//	BinaryTree class implementation
template <class Tree_Entry>
BinaryTree<Tree_Entry>::BinaryTree()
//	Post:	An Empty binary tree has been created. 
{
	root = NULL;
	count = 0;
}

template <class Tree_Entry>
bool BinaryTree<Tree_Entry>::Empty() const
//	Post:	A result oftrue is returned if the binary tree is Empty. 
//			Otherwise,false is returned. 
{
	return root == NULL;
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::Preorder(void(*visit)(Tree_Entry &))
{
	RecursivePreorder(root, visit);
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::RecursivePreorder(
	BinaryNode<Tree_Entry> *subRoot, void(*visit)(Tree_Entry &))
{
	if (subRoot != NULL)
	{
		(*visit)(subRoot->data);
		RecursivePreorder(subRoot->left, visit);
		RecursivePreorder(subRoot->right, visit);
	}
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::Inorder(void(*visit)(Tree_Entry &))
//	Post:	The tree has been been traversed in infix order sequence.
//	Uses:	The function RecursiveInorder
{
	RecursiveInorder(root, visit);
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::RecursiveInorder(BinaryNode<Tree_Entry> *subRoot, void(*visit)(Tree_Entry &))
//	Pre:	subRoot is either NULL or points to a subtree of the Binary tree.
//	Post:	The subtree has been traversed in Inorder sequence.
//	Uses:	The function recursive Inorder_recursively 
{
	if (subRoot != NULL) 
	{
		RecursiveInorder(subRoot->left, visit);
		(*visit)(subRoot->data);
		RecursiveInorder(subRoot->right, visit);
	}
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::Postorder(void(*visit)(Tree_Entry &))
{
	RecursivePostorder(root, visit);
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::RecursivePostorder(BinaryNode<Tree_Entry> *subRoot, void(*visit)(Tree_Entry &))
{
	if (subRoot != NULL)
	{
		RecursivePostorder(subRoot->left, visit);
		RecursivePostorder(subRoot->right, visit);
		(*visit)(subRoot->data);
	}
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::Travorder(void(*visit)(Tree_Entry &))
{
	Queue< BinaryNode<Tree_Entry>* > q;
	q.Append(root);
	RecursiveTravorder(q, visit);
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::RecursiveTravorder(Queue< BinaryNode<Tree_Entry>* > &q, void(*visit)(Tree_Entry &))
//	Pre:	q shouldn't be empty.
//	Post:	Traverse the tree level by level.
//	Uses:	Linked_Queue.h's Queue Class.
{
	BinaryNode<Tree_Entry> *subRoot;
	if (q.ServeAndRetrieve(subRoot) == success && subRoot != NULL)
	{
		(*visit)(subRoot->data);
		q.Append(subRoot->left);
		q.Append(subRoot->right);
		RecursiveTravorder(q, visit);
	}
}

template <class Tree_Entry>
int BinaryTree<Tree_Entry>::Size() const
{
	return count;
}

template <class Tree_Entry>
int BinaryTree<Tree_Entry>::Height() const
{
	int count = Size();
	if (count == 0)	return 0;
	int tmp = 1;
	for (int i = 0; tmp <= count; i++)
		tmp *= 2;
	return i;
}

template <class Tree_Entry>
int BinaryTree<Tree_Entry>::NumOfLeaves() const
{
	return RecursiveCountLeaves(root);
}

template <class Tree_Entry>
int BinaryTree<Tree_Entry>::RecursiveCountLeaves(BinaryNode<Tree_Entry> *subRoot) const
{
	int sum = 0;
	if (!subRoot)	return sum;	//empty
	if (!(subRoot->left) && !(subRoot->right)) return ++sum;//only the leaf
	sum = RecursiveCountLeaves(subRoot->left) +
		RecursiveCountLeaves(subRoot->right);
	return sum;
}

template <class Tree_Entry>
Error_code BinaryTree<Tree_Entry>::Insert(Tree_Entry &x)
//	Post:	append the Tree_Entry x on the tail order of the tree.
//			Always return success.
//	Uses:	Linked_Stack class and Node class.
{
	if (Empty())
	{
		root = new BinaryNode<Tree_Entry>(x);
		count++;
		return success;
	}
	Stack<int> numbers;
	int item = 0;
	int tmpcount = Size();
	while (tmpcount > 0)
	{
		if (tmpcount % 2 == 0)//the node is right child
		{
			numbers.Push(2);//2 stand for right child (2n+2)
		}
		else				//the node is left child 
		{
			numbers.Push(1);//1 stand for left child (2n+1)
		}
		tmpcount = (tmpcount - 1) / 2;//get to the parent
	}
	BinaryNode<Tree_Entry> *current = root;
	while (numbers.Size() > 1)
	{
		numbers.Top(item);
		if (item == 1)current = current->left;
		if (item == 2)current = current->right;
		numbers.Pop();
	}
	numbers.Top(item);
	if (item == 1)current->left = new BinaryNode<Tree_Entry>(x);
	if (item == 2)current->right = new BinaryNode<Tree_Entry>(x);
	count++;
	return success;
}

template <class Tree_Entry>
Error_code BinaryTree<Tree_Entry>::Remove(Tree_Entry &x)
//	Post:	If a Tree_entry with a key matching that of target belongs 
//			to the binary tree a code of success is returned and the 
//			corresponding node is removed from the tree. 
//			Otherwise, a code of not present is returned.
//	Uses:	Function search_and_destroy.
{
	Error_code result = SearchAndDestroy(root, x);
	if (result == success)	count--;
	return result;
}

template <class Tree_Entry>
Error_code BinaryTree<Tree_Entry>::SearchAndDestroy(
	BinaryNode<Tree_Entry>* &subRoot, const Tree_Entry &target)
{
	if (subRoot == NULL || subRoot->data == target)
		return RemoveRoot(subRoot);
	Error_code result = SearchAndDestroy(subRoot->left, target);
	if (result == not_present)
		return SearchAndDestroy(subRoot->right, target);
	return result;
}

template <class Tree_Entry>
Error_code BinaryTree<Tree_Entry>::RemoveRoot(BinaryNode<Tree_Entry>* &subRoot)
{
	if (subRoot == NULL) return not_present;
	BinaryNode<Tree_Entry> *toDelete = subRoot;
	// Remember node to delete at end.
	if (subRoot->right == NULL) subRoot = subRoot->left;
	else if (subRoot->left == NULL) subRoot = subRoot->right;
	else 
	{ // Neither subtree is empty.
		toDelete = subRoot->left; // Move left to find predecessor.	
		BinaryNode<Tree_Entry> *parent = subRoot; // parent of toDelete
		while (toDelete->right != NULL)  // toDelete is not the predecessor.
		{
			parent = toDelete;
			toDelete = toDelete->right;
		}
		subRoot->data = toDelete->data; // Move from toDelete to root.
		if (parent == subRoot) subRoot->left = toDelete->left;
		else parent->right = toDelete->left;
	}
	delete toDelete; // Remove toDelete from tree.
	return success;
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::Interchange()
//	Post:	All of the left and right subtrees are interchanged.
{
	SubInterchange(root);
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::SubInterchange(BinaryNode<Tree_Entry> * &subRoot)
{
	if (subRoot != NULL)
	{
		Swap(subRoot->left, subRoot->right);
		SubInterchange(subRoot->left);
		SubInterchange(subRoot->right);
	}
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::Clear()
//	Post:	The whole tree is cleared.
//	Uses:	function RecursiveDelete.
{
	RecursiveDelete(root);
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::RecursiveDelete(BinaryNode<Tree_Entry>* &subRoot)
//	Post:	subRoot's subtree is deleted.
{
	if (subRoot == NULL)	return;
	RecursiveDelete(subRoot->left);
	RecursiveDelete(subRoot->right);
	delete subRoot;
	subRoot = NULL;
}

//safty guards
template <class Tree_Entry>
BinaryTree<Tree_Entry>::BinaryTree(const BinaryTree<Tree_Entry> &original)
{
	root = NULL;
	Queue<Tree_Entry*> q;
	q.Append(original->root);
	RecursiveCopy(q, root, original->root);
	count = original.count;
}

template <class Tree_Entry>
void BinaryTree<Tree_Entry>::RecursiveCopy(Queue<Tree_Entry> &q,
										   BinaryNode<Tree_Entry> *subRoot, 
										   BinaryNode<Tree_Entry> *subRootOrg)
//	Pre:	subRoot and subRootOrg should be on the same corresponding position.
//	Post:	copy the subtree of the subRootOrg to the subtree of subRoot.
//	Uses:	Queue Class.
{
	q.ServeAndRetrieve(subRootOrg);
	if (!subRoot)	subRoot = new BinaryNode<Tree_Entry>;
	subRoot->data = subRootOrg->data;
	q.Append(subRootOrg->left);
	q.Append(subRootOrg->right);
	RecursiveCopy(q, subRoot->left, subRootOrg);
}

template<class Tree_Entry>
BinaryTree<Tree_Entry> &BinaryTree<Tree_Entry>::operator = (const BinaryTree<Tree_Entry> &original)
{
	Clear();
	Queue<Tree_Entry*> q;
	q.Append(original->root);
	RecursiveCopy(q, root, original->root);
	count = original.count;
}

template <class Tree_Entry>
BinaryTree<Tree_Entry>::~BinaryTree()
{
	Clear();
}

#endif