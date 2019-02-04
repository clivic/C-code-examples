//*******************************************************************
//	BTree Class's specification
//	General introduction:
//		It is a Balanced Multiway Search Tree(BTree) which 
//		automatically adjust it self into a more "bushy" state when 
//		Inserting. And it is a Multiway Search Tree.
//	Notes:	
//		The AVLNode class is derived from SearchTree class, and only 
//		available to entries in the form of struct Record.(for it's
//		a search tree)
//	Uses:	
//		SearchTree class.
//*******************************************************************
#ifndef BTREE
#define BTREE
#include "BNode.h"

template <class Record, int order>
class BTree 
{
public: 
	Error_code SearchTree(Record &target);
	Error_code Insert(const Record &newEntry);
	BTree();	
	Error_code Remove(const Record &target);

private: 
	//data members:
	BNode<Record, order> *root;

	//auxiliary functions:
	Error_code RecursiveSearchTree(BNode<Record, order> *current, Record &target);
	Error_code SearchNode(BNode<Record, order> *current, const Record &target, int &position);

	Error_code PushDown(
		BNode<Record, order> *current, const Record &newEntry,
		Record &median, BNode<Record, order> * &rightBranch);
	void PushIn(BNode<Record, order> *current,
		const Record &entry, BNode<Record, order> *rightBranch, int position);
	void SplitNode(BNode<Record, order> *current,			//node to be split
		const Record &extraEntry,BNode<Record, order> *extraBranch,
		int position,										//index in node whereextra entry goes
		BNode<Record, order> * &rightHalf, Record &median); //new node for right half of entries
	
	Error_code RecursiveRemove(BNode<Record, order> *current, const Record &target);
	void RemoveData(BNode<Record, order> *current, int position);
	void CopyInPredecessor(BNode<Record, order> *current, int position);
	void Restore(BNode<Record, order> *current, int position);
	void MoveLeft(BNode<Record, order> *current, int position);
	void MoveRight(BNode<Record, order> *current, int position);
	void Combine(BNode<Record, order> *current, int position);
};

//*******************************************************************

//	BTree Class's implementation
template <class Record, int order>
BTree<Record, order>::BTree()
{
	root = NULL;
};

template <class Record, int order>
Error_code BTree<Record, order>::SearchTree(Record &target)
//	Post:	If there is an entry in the BTree whose key matches that 
//			intarget, the parametertarget is replaced by the 
//			corresponding Record from the BTree and a code of 
//			success is returned. Otherwise a code of not present is 
//			returned.
//	Uses:	function RecursiveSearchTree. 
{
	return RecursiveSearchTree(root, target);
}

template <class Record, int order>
Error_code BTree<Record, order>::RecursiveSearchTree(
	BNode<Record, order> *current, Record &target)
//	Pre:	current is either NULL or points to a subtree of the Btree.
//	Post:	If the Key of target is not in the subtree, a code of not 
//			present is returned. Otherwise, a code ofsuccess is 
//			returned andtarget is set to the correspondingRecord of the
//			subtree.
//	Uses:	function RecursiveSearchTree and SearchNode.
{
	Error_code result = not_present;
	int position;
	if (current != NULL) 
	{
		result = SearchNode(current, target, position);
		if (result == not_present)
			result = RecursiveSearchTree(current->branch[position], target);
		else
			target = current->data[position];
	}
	return result;
}

template <class Record, int order>
Error_code BTree<Record, order>::SearchNode(
	BNode<Record, order> *current, const Record &target, int &position)
//	Pre:	current points to a node of a Btree.
//	Post:	If the Key of target is found in the pointer current, then 
//			a code of success is returned, the parameter position is 
//			set to the index of target, and the corresponding Record 
//			is copied to target. Otherwise, a code of not present is 
//			returned, and position is set to the branch index on which 
//			to continue the search.
//	Uses:	Methods of class Record. 
{
	position = 0;

	//Sequential search through the keys.
	while (position < current->count && target > current->data[position])
		position++; 
	if (position < current->count && target == current->data[position])
		return success;
	else
		return not_present;
}

template <class Record, int order>
Error_code BTree<Record, order>::Insert(const Record &newEntry)
//	Post:	If the Key of new entry is already in the Btree, a code 
//			of duplicate error is returned. Otherwise, a code of 
//			success is returned and the Record new entry is Inserted 
//			into the BTree in such a way that the properties of a 
//			BTree are preserved.
//	Uses:	Methods of struct BNode and the auxiliary function PushDown.
{
	Record median;
	BNode<Record, order> *rightBranch, *new_root;
	Error_code result = PushDown(root, newEntry, median, rightBranch);
	if (result == overflow) { //The whole tree grows in height.
		//Make a brand new root for the whole BTree.
		new_root = new BNode<Record, order>;
		new_root->count = 1;
		new_root->data[0] = median;
		new_root->branch[0] = root;
		new_root->branch[1] = rightBranch;
		root = new_root;
		result = success;
	}
	return result;
}

template <class Record, int order>
Error_code BTree<Record, order>::PushDown(
	BNode<Record, order> *current, const Record &newEntry,
	Record &median, BNode<Record, order> * &rightBranch)
//	Pre:	current is either NULL or points to a node of a BTree.
//	Post:	If an entry with a Key matching that ofnew entry is in the 
//			subtree to which current points, a code of duplicate error 
//			is returned. 
//			Else, new entry is inserted into the subtree: 
//				If this causes the height of the subtree to grow, a 
//				code of over_flow is returned, and the Record median 
//				is extracted to be reinserted higher in the BTree, 
//				together with the subtree right branch on its right. 
//				Else(the height does not grow), a code of success is 
//				returned.
//	Uses:	Functions PushDown (called recursively), SearchNode, 
//			SplitNode, and PushIn. 
{
	Error_code result;
	int position;
	if (current == NULL)
	{
		//Since we cannot Insert in an empty tree, the recursion terminates.
		median = newEntry;
		rightBranch = NULL;
		result = overflow;
	}
	else //Search the current node.
	{ 
		if (SearchNode(current, newEntry, position) == success)
			result = duplicate_error;
		else 
		{
			Record extraEntry;
			BNode<Record, order> *extraBranch;
			result = PushDown(current->branch[position], newEntry,
				extraEntry, extraBranch);
			if (result == overflow)
			{
				//Record extra entry now must be added tocurrent
				if (current->count < order - 1) 
				{
					result = success;
					PushIn(current, extraEntry, extraBranch, position);
				}
				//Record median and itsright branch will go up to a higher node.
				else SplitNode(current, extraEntry, extraBranch, position, rightBranch, median);
				
			}
		}
	}
	return result;
}


template <class Record, int order>
void BTree<Record, order>::PushIn(
	BNode<Record, order> *current,
	const Record &entry, BNode<Record, order> *rightBranch,
	int position)
//	Pre:	current points to a node of a BTree. The pointer current 
//			is not full and entry current pointing to belongs at 
//			index position.
//	Post:	entry has been Inserted along with its right-hand branch 
//			right branch into pointer current at index position.
{
	//Shift all later data to the right.
	for (int i = current->count; i > position; i--) 
	{
		current->data[i] = current->data[i - 1];
		current->branch[i + 1] = current->branch[i];
	}
	current->data[position] = entry;
	current->branch[position + 1] = rightBranch;
	current->count++;
}

template <class Record, int order>
void BTree<Record, order>::SplitNode(
	BNode<Record, order> *current,		//node to be split
	const Record &extraEntry,			//new entry to Insert
	BNode<Record, order> *extraBranch,	//subtree on right ofextra entry
	int position,						//index in node whereextra entry goes
	BNode<Record, order> * &rightHalf,	//new node for right half of entries
	Record &median)						//median entry (in neither half)
//	Pre:	current points to a node of a BTree. The node current points 
//			to is full, but if there were room, the Record extraEntry 
//			with its right-hand pointer extra branch would belong in 
//			*current at "position" position, 0 <= position < order.
//	Post:	The node *current with extraEntry and pointer extraBranch at 
//			"position" position are divided into nodes *current and 
//			*rightHalf separated by a Record median.
//	Uses:	Methods of struct BNode, function PushIn. 
{
	rightHalf = new BNode<Record, order>;
	int mid = order / 2; //The entries frommid on will go toright half.

	//First case: extra entry belongs in left half.
	if (position <= mid)
	{ 
		for (int i = mid; i < order - 1; i++) //Move entries toright half.
		{ 
			rightHalf->data[i - mid] = current->data[i];
			rightHalf->branch[i + 1 - mid] = current->branch[i + 1];
		}
		current->count = mid;
		rightHalf->count = order - 1 - mid;
		PushIn(current, extraEntry, extraBranch, position);
	}

	//Second case: extra entry belongs in right half.
	else 
	{
		mid++; //Temporarily leave the median in left half.
		for (int i = mid; i < order - 1; i++)
		{ 
			//Move entries toright half.
			rightHalf->data[i - mid] = current->data[i];
			rightHalf->branch[i + 1 - mid] = current->branch[i + 1];
		}
		current->count = mid;
		rightHalf->count = order - 1 - mid;
		PushIn(rightHalf, extraEntry, extraBranch, position - mid);
	}
	median = current->data[current->count - 1];

	//Remove median from left half.
	rightHalf->branch[0] = current->branch[current->count];
	current->count--;
}

template <class Record, int order>
Error_code BTree<Record, order>::Remove(const Record &target)
//	Post:	If a Record with Key matching that of target belongs to 
//			the BTree, a code of success is returned and the 
//			corresponding node is Removed from the BTree.
//			Otherwise, a code of not_present is returned.
//	Uses:	Function RecursiveRemove. 
{
	Error_code result;
	result = RecursiveRemove(root, target);
	if (root != NULL && root->count == 0) //Clear the root.
	{ 
		BNode<Record, order> *old_root = root;
		root = root->branch[0];
		delete old_root;
	}
	return result;
}

template <class Record, int order>
Error_code BTree<Record, order>::RecursiveRemove(
	BNode<Record, order> *current, const Record &target)
//	Pre:	current is either NULL or points to the root node of a 
//			subtree of a BTree.
//	Post:	If a Record with Key matching that of target belongs to 
//			the subtree, a code of success is returned and the 
//			corresponding node is Removed from the subtree so that 
//			the properties of a BTree are maintained. 
//			Otherwise, a code of not_present is returned.
//	Uses:	Functions SearchNode, CopyInPredecessor, RecursiveRemove, RemoveData, and Restore. 
{
	Error_code result;
	int position;
	if (current == NULL) result = not_present;
	else 
	{
		if (SearchNode(current, target, position) == success) 
		{
			//The target is in the current node.
			result = success;
			if (current->branch[position] != NULL) //not leaf
			{ 
				CopyInPredecessor(current, position);
				RecursiveRemove(current->branch[position],
					current->data[position]);
			}
			//Remove from a leaf node.
			else RemoveData(current, position); 
		}
		else result = RecursiveRemove(current->branch[position], target);
		if (current->branch[position] != NULL)
			if (current->branch[position]->count < (order - 1) / 2)
				Restore(current, position);
	}
	return result;
}


template <class Record, int order>
void BTree<Record, order>::
RemoveData(BNode<Record, order> *current, int position)
//	Pre:	current points to a leaf node in a BTree with an entry at position.
//	Post:	This entry is Removed from *current. 
{
	for (int i = position; i < current->count - 1; i++)
		current->data[i] = current->data[i + 1];
	current->count--;
}

template <class Record, int order>
void BTree < Record, order >::CopyInPredecessor(
	BNode<Record, order> *current, int position)
//	Pre:	current points to a non-leaf node in a BTree with an 
//			entry at position.
//	Post:	This entry is replaced by its immediate predecessor 
//			under order of keys.
{
	BNode<Record, order> *leaf = current->branch[position];

	//First go left from the current entry.
	while (leaf->branch[leaf->count] != NULL)
		leaf = leaf->branch[leaf->count];

	//Move as far rightward as possible.
	current->data[position] = leaf->data[leaf->count - 1];
}


template <class Record, int order>
void BTree<Record, order>::
Restore(BNode<Record, order> *current, int position)
//	Pre:	current points to a non-leaf node in a BTree; the node 
//			to which current->branch[position] points has one too 
//			few entries.
//	Post:	An entry is taken from elsewhere to Restore the minimum 
//			number of entries in the node to which 
//			current->branch[position] points.
//	Uses:	MoveLeft, MoveRight, Combine. 
{
	if (position == current->count) //case: rightmost branch
		if (current->branch[position - 1]->count > (order - 1) / 2)
			MoveRight(current, position - 1);
		else
			Combine(current, position);
	else if (position == 0)			//case: leftmost branch
		if (current->branch[1]->count > (order - 1) / 2)
			MoveLeft(current, 1);
		else
			Combine(current, 1);
	else							//remaining cases: intermediate branches
		if (current->branch[position - 1]->count > (order - 1) / 2)
			MoveRight(current, position - 1);
		else if (current->branch[position + 1]->count > (order - 1) / 2)
			MoveLeft(current, position + 1);
		else Combine(current, position);
}

template <class Record, int order>
void BTree<Record, order>::
MoveLeft(BNode<Record, order> *current, int position)
//	Pre:	current points to a node in a BTree with more than the 
//			minimum number of entries in branch position and one 
//			too few entries in branch position - 1.
//	Post:	The leftmost entry from branch position has moved into 
//			current, which has sent an entry into the branch 
//			position - 1. 
{
	BNode<Record, order>
		*leftBranch = current->branch[position - 1],
		*rightBranch = current->branch[position];
	leftBranch->data[leftBranch->count] = current->data[position - 1]; 
	leftBranch->branch[++leftBranch->count] = rightBranch->branch[0];
	current->data[position - 1] = rightBranch->data[0];
	
	//Add the right-hand entry to the parent.
	rightBranch->count--;
	for (int i = 0; i < rightBranch->count; i++) 
	{
		//Move right-hand entries to fill the hole.
		rightBranch->data[i] = rightBranch->data[i + 1];
		rightBranch->branch[i] = rightBranch->branch[i + 1];
	}
	rightBranch->branch[rightBranch->count] =
		rightBranch->branch[rightBranch->count + 1];
}

template <class Record, int order>
void BTree<Record, order>::
MoveRight(BNode<Record, order> *current, int position)
//	Pre:	current points to a node in a BTree with more than the 
//			minimum number of entries in branch position and one too 
//			few entries in branch position + 1.
//	Post:	The rightmost entry from branch position has moved 
//			intocurrent, which has sent an entry into the branch 
//			position + 1. 
{
	BNode<Record, order>
		*rightBranch = current->branch[position + 1],
		*leftBranch = current->branch[position];
	rightBranch->branch[rightBranch->count + 1] =
		rightBranch->branch[rightBranch->count];
	for (int i = rightBranch->count; i > 0; i--) 
	{
		//Make room for new entry.
		rightBranch->data[i] = rightBranch->data[i - 1];
		rightBranch->branch[i] = rightBranch->branch[i - 1];
	}
	rightBranch->count++;
	rightBranch->data[0] = current->data[position];

	//Take entry from parent.
	rightBranch->branch[0] = leftBranch->branch[leftBranch->count--];
	current->data[position] = leftBranch->data[leftBranch->count];
}


template <class Record, int order>
void BTree<Record, order>::
Combine(BNode<Record, order> *current, int position)
//	Pre:	current points to a node in a BTree with entries in the 
//			branches position and position - 1, with too few to move 
//			entries.
//	Post:	The nodes at branches position - 1 and position have 
//			been combined into one node, which also includes the 
//			entry formerly in current at index position - 1. 
{
	int i;
	BNode<Record, order>
		*leftBranch = current->branch[position - 1],
		*rightBranch = current->branch[position];
	leftBranch->data[leftBranch->count] = current->data[position - 1];
	leftBranch->branch[++leftBranch->count] = rightBranch->branch[0];
	for (i = 0; i < rightBranch->count; i++) 
	{
		leftBranch->data[leftBranch->count] =
			rightBranch->data[i];
		leftBranch->branch[++leftBranch->count] =
			rightBranch->branch[i + 1];
	}
	current->count--;
	for (i = position - 1; i < current->count; i++) 
	{
		current->data[i] = current->data[i + 1];
		current->branch[i + 1] = current->branch[i + 2];
	}
	delete rightBranch;
}

#endif