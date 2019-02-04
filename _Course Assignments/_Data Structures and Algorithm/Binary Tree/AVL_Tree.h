//*******************************************************************
//	AVLTree Class's specification
//	General introduction:
//		It is a Binary Tree which can automatically adjust it self 
//		into a more "bushy" state -- the heights of left and right 
//		subtrees differ by at most 1.
//	Notes:	
//		The AVLNode class is derived from SearchTree class, and only 
//		available to entries in the form of struct Record.(for it's
//		a search tree)
//	Uses:	
//		SearchTree class.
//*******************************************************************
#ifndef AVLTREE
#define AVLTREE
#include "Search_Tree.h"

template <class Record>
class AVLTree: public SearchTree<Record> 
{
public:
	Error_code Insert(const Record &newData);
	Error_code Remove(Record &oldData);

protected: 
	Error_code AVL_Insert(BinaryNode<Record>* &subRoot,const Record &newData, bool &taller);
	void RotateLeft(BinaryNode<Record>* &subRoot);
	void RotateRight(BinaryNode<Record>* &subRoot);
	void RightBalance(BinaryNode<Record>* &subRoot);
	void LeftBalance(BinaryNode<Record>* &subRoot);
	//add for Remove
	Error_code AVL_Remove(BinaryNode<Record>* &subRoot, Record &newData, bool &shorter);
	bool RightBalance2(BinaryNode<Record>* &subRoot);
	bool LeftBalance2(BinaryNode<Record>* &subRoot);
};

//*******************************************************************

//AVLTree Class's implementation
template <class Record>
Error_code AVLTree<Record>::Insert(const Record &newData)
//	Post:	If the key of new data is already in the AVL tree, a code 
//			of duplicate error is returned. 
//			Else, a code of success is returned and the Record new 
//			data is Inserted into the tree in such a way that the 
//			properties of an AVL tree are preserved.
//	Uses:	AVL_Insert.
{
	bool taller; //Has the tree grown in height?	
	return AVL_Insert(root, newData, taller);
}

template <class Record>
Error_code AVLTree<Record>::AVL_Insert(BinaryNode<Record>* &subRoot,
	const Record &newData, bool &taller)
//	Pre:	The sub root is either NULL or points to a subtree of 
//			the AVL tree.
//	Post:	If the key of new data is already in the subtree, a code 
//			of duplicate error is returned. 
//			Else, a code of success is returned and the Record 
//			new data is Inserted into the subtree in such a way that 
//			the properties of an AVL tree have been preserved. 
//			If the subtree is increased in height, the parameter 
//			taller is set to true. 
//			Else it is set to false.
//	Uses:	Methods of struct AVL node; 
//			functions AVL_Insert recursively, LeftBalance, 
//			and RightBalance. 
{
	Error_code result = success;
	if (subRoot == NULL) 
	{
		subRoot = new AVLNode<Record>(newData);
		taller = true;
	}
	else if (newData == subRoot->data) 
	{
		result = duplicate_error;
		taller = false;
	}

	//Insert in left subtree.
	else if (newData < subRoot->data) 
	{ 
		result = AVL_Insert(subRoot->left, newData, taller);
		if (taller == true)
			//Change balance factors.
			switch (subRoot->GetBalance()) 
		{ 
			case LEFT_HIGHER:
				LeftBalance(subRoot);
				taller = false; //Rebalancing always shortens the tree.
				break;
			case EQUAL_HEIGHT:
				subRoot->SetBalance(LEFT_HIGHER);
				break;
			case RIGHT_HIGHER:
				subRoot->SetBalance(EQUAL_HEIGHT);
				taller = false;
				break;
		}
	}

	//Insert in right subtree.
	else
	{ 
		result = AVL_Insert(subRoot->right, newData, taller);
		if (taller == true)
			switch (subRoot->GetBalance()) 
		{
			case LEFT_HIGHER:
				subRoot->SetBalance(EQUAL_HEIGHT);
				taller = false;
				break;
			case EQUAL_HEIGHT:
				subRoot->SetBalance(RIGHT_HIGHER);
				break;
			case RIGHT_HIGHER:
				RightBalance(subRoot);
				taller = false; //Rebalancing always shortens the tree.
				break;
		}
	}
	return result;
}

template <class Record>
void AVLTree<Record>::RotateLeft(BinaryNode<Record>* &subRoot)
//	Pre:	subRoot points to a subtree of the AVL tree. This subtree 
//			has a nonempty right subtree.
//	Post:	subRoot is reset to point to its former right child, and 
//			the former subRoot node is the left child of the new 
//			subRoot node. 
{
	if (subRoot == NULL || subRoot->right == NULL) //impossible cases
		cout << "WARNING: program error detected in rotate left" << endl;
	else 
	{
		BinaryNode<Record> *rightTree = subRoot->right;
		subRoot->right = rightTree->left;
		rightTree->left = subRoot;
		subRoot = rightTree;
	}
}

template <class Record>
void AVLTree<Record>::RotateRight(BinaryNode<Record>* &subRoot)
//	Pre:	subRoot points to a subtree of the AVL tree. This subtree 
//			has a nonempty left subtree.
//	Post:	subRoot is reset to point to its former left child, and 
//			the former subRoot node is the right child of the new 
//			subRoot node. 
{
	if (subRoot == NULL || subRoot->left == NULL) //impossible cases
		cout << "WARNING: program error detected in rotate right" << endl;
	else {
		BinaryNode<Record> *leftTree = subRoot->left;
		subRoot->left = leftTree->right;
		leftTree->right = subRoot;
		subRoot = leftTree;
	}
}

template <class Record>
void AVLTree<Record>::RightBalance(BinaryNode<Record>* &subRoot)
//	Pre:	sub root points to a subtree of an AVL tree, doubly 
//			unbalanced on the right.
//	Post:	The AVL properties have been restored to the subtree.
//	Uses:	Methods of struct AVL node; functions RotateRight, 
//			RotateLeft.
{
	BinaryNode<Record>* &rightTree = subRoot->right;
	switch (rightTree->GetBalance()) 
	{
	case RIGHT_HIGHER: //single rotation left
		subRoot->SetBalance(EQUAL_HEIGHT);
		rightTree->SetBalance(EQUAL_HEIGHT);
		RotateLeft(subRoot);
		break;
	case EQUAL_HEIGHT: //impossible case
		cout << "WARNING: program error in right balance" << endl;
	case LEFT_HIGHER: //double rotation left
		BinaryNode<Record> *subTree = rightTree->left;
		switch (subTree->GetBalance()) 
		{
		case EQUAL_HEIGHT:
			subRoot->SetBalance(EQUAL_HEIGHT);
			rightTree->SetBalance(EQUAL_HEIGHT);
			break;
		case LEFT_HIGHER:
			subRoot->SetBalance(EQUAL_HEIGHT);
			rightTree->SetBalance(RIGHT_HIGHER);
			break;
		case RIGHT_HIGHER:
			subRoot->SetBalance(LEFT_HIGHER);
			rightTree->SetBalance(EQUAL_HEIGHT);
			break;
		}
		subTree->SetBalance(EQUAL_HEIGHT);
		RotateRight(rightTree);
		RotateLeft(subRoot);
		break;
	}
}

template <class Record>
void AVLTree<Record>::LeftBalance(BinaryNode<Record>* &subRoot) 
//	Pre:	sub root points to a subtree of an AVL tree, doubly 
//			unbalanced on the left.
//	Post:	The AVL properties have been restored to the subtree.
//	Uses:	Methods of struct AVL node; functions RotateRight, 
//			RotateLeft.
{
	BinaryNode<Record>* &leftTree = subRoot->left;
	switch (leftTree->GetBalance()) 
	{
	case LEFT_HIGHER: //single rotation left
		subRoot->SetBalance(EQUAL_HEIGHT);
		leftTree->SetBalance(EQUAL_HEIGHT);
		RotateRight(subRoot);
		break;
	case EQUAL_HEIGHT: //impossible case
		cout << "WARNING: program error in right balance" << endl;
	case RIGHT_HIGHER: //double rotation left
		BinaryNode<Record> *subTree = leftTree->right;
		switch (subTree->GetBalance())
		{
		case EQUAL_HEIGHT:
			subRoot->SetBalance(EQUAL_HEIGHT);
			leftTree->SetBalance(EQUAL_HEIGHT);
			break;
		case RIGHT_HIGHER:
			subRoot->SetBalance(EQUAL_HEIGHT);
			leftTree->SetBalance(LEFT_HIGHER);
			break;
		case LEFT_HIGHER:
			subRoot->SetBalance(RIGHT_HIGHER);
			leftTree->SetBalance(EQUAL_HEIGHT);
			break;
		}
		subTree->SetBalance(EQUAL_HEIGHT);
		RotateLeft(leftTree);
		RotateRight(subRoot);
		break;
	}
}

template <class Record>
Error_code AVLTree<Record>::Remove(Record &newData)
//	Post:	If the key of new data is not in the AVL tree, a code of 
//			not_present is returned. Otherwise, a code of success is 
//			returned and the Record new data is removed from the 
//			tree in such a way that the properties of an AVL tree 
//			are preserved.
//	Uses:	AVL_Remove. 
{
	bool shorter = true; //Has the tree shorter in height?	
	return AVL_Remove(root, newData, shorter);
}

template <class Record>
Error_code AVLTree<Record>::AVL_Remove(BinaryNode<Record>* &subRoot,
	Record &newData, bool &shorter)
{
	Error_code result = success;
	Record subRecord;
	if (subRoot == NULL)
	{
		shorter = false;
		return not_present;
	}
	else if (newData == subRoot->data) 
	{
		//Remember node to delete at end.
		BinaryNode<Record> *toDelete = subRoot;

		if (subRoot->right == NULL)
		{
			subRoot = subRoot->left;
			shorter = true;
			delete toDelete; //Remove toDelete from tree.
			return success;
		}

		else if (subRoot->left == NULL)
		{
			subRoot = subRoot->right;
			shorter = true;
			delete toDelete; //Remove toDelete from tree.
			return success;
		}

		else	//Neither subtree is empty. 
		{ 
			toDelete = subRoot->left;				//Move left to find predecessor.	
			BinaryNode<Record> *parent = subRoot;	//parent of toDelete
			while (toDelete->right != NULL)			//toDelete is not the predecessor.
			{ 
				parent = toDelete;
				toDelete = toDelete->right;
			}
			//subRoot->data = toDelete->data;		//Move data from toDelete to root. 
			newData = toDelete->data;
			subRecord = newData;
		}
	}

	if (newData < subRoot->data)					//Remove in left subtree.
	{ 
		result = AVL_Remove(subRoot->left, newData, shorter);
		if (shorter == true)
			switch (subRoot->GetBalance())			//Change balance factors.
		{
			case LEFT_HIGHER:
				subRoot->SetBalance(EQUAL_HEIGHT);
				break;
			case EQUAL_HEIGHT:
				subRoot->SetBalance(RIGHT_HIGHER);
				shorter = false;
				break;
			case RIGHT_HIGHER:
				if (subRecord.GetKey() != 0)
					subRoot->data = subRecord;		//Move data from toDelete to root. 
				shorter = RightBalance2(subRoot);
				break;
		}
	}

	if (newData > subRoot->data)					//Remove in right subtree.
	{
		result = AVL_Remove(subRoot->right, newData, shorter);
		if (shorter == true)
			switch (subRoot->GetBalance())			//Change balance factors.
		{
			case LEFT_HIGHER:
				if (subRecord.GetKey() != 0)
					subRoot->data = subRecord;		//Move data from toDelete to root. 
				shorter = LeftBalance2(subRoot);
				break;
			case EQUAL_HEIGHT:
				subRoot->SetBalance(LEFT_HIGHER);
				shorter = false;
				break;
			case RIGHT_HIGHER:
				subRoot->SetBalance(EQUAL_HEIGHT);
				break;
		}
	}
	return result;
}

template <class Record>
bool AVLTree<Record>::RightBalance2(BinaryNode<Record> * &subRoot)
//	Pre:	sub root points to a subtree of an AVL tree, doubly 
//			unbalanced on the right.
//	Post:	The AVL properties have been restored to the subtree.
//	Uses:	Methods of struct AVL node; functions RotateRight, 
//			RotateLeft. 
//	Notes:	Difference between this function and RightBalance is
//			RightBalance2 is for deletion and RightBalance is for 
//			insertion perhaps.
{
	bool shorter;
	BinaryNode<Record> * &rightTree = subRoot->right;
	switch (rightTree->GetBalance()) 
	{
	case RIGHT_HIGHER: //single rotation left
		subRoot->SetBalance(EQUAL_HEIGHT);
		rightTree->SetBalance(EQUAL_HEIGHT);
		RotateLeft(subRoot);
		shorter = true;
		break;
	case EQUAL_HEIGHT: //single rotation left
		rightTree->SetBalance(LEFT_HIGHER);
		RotateLeft(subRoot);
		shorter = false;
		break;
	case LEFT_HIGHER: //double rotation left
		BinaryNode<Record> *subTree = rightTree->left;
		switch (subTree->GetBalance())
		{
		case EQUAL_HEIGHT:
			subRoot->SetBalance(EQUAL_HEIGHT);
			rightTree->SetBalance(EQUAL_HEIGHT);
			break;
		case LEFT_HIGHER:
			subRoot->SetBalance(EQUAL_HEIGHT);
			rightTree->SetBalance(RIGHT_HIGHER);
			break;
		case RIGHT_HIGHER:
			subRoot->SetBalance(LEFT_HIGHER);
			rightTree->SetBalance(EQUAL_HEIGHT);
			break;
		}
		subTree->SetBalance(EQUAL_HEIGHT);
		RotateRight(rightTree);
		RotateLeft(subRoot);
		shorter = true;
		break;
	}
	return shorter;
}

template <class Record>
bool AVLTree<Record>::LeftBalance2(BinaryNode<Record> * &subRoot)
//	Pre:	sub root points to a subtree of an AVL tree, doubly 
//			unbalanced on the left.
//	Post:	The AVL properties have been restored to the subtree.
//	Uses:	Methods of struct AVL node; functions RotateRight, 
//			RotateLeft.
//	Notes:	Difference between this function and LeftBalance is
//			LeftBalance2 is for deletion and LeftBalance is for 
//			insertion perhaps.
{
	bool shorter;
	BinaryNode<Record> * &leftTree = subRoot->left;
	switch (leftTree->GetBalance()) 
	{
	case LEFT_HIGHER: //single rotation right
		subRoot->SetBalance(EQUAL_HEIGHT);
		leftTree->SetBalance(EQUAL_HEIGHT);
		RotateRight(subRoot);
		shorter = true;
		break;
	case EQUAL_HEIGHT: //single rotation right
		leftTree->SetBalance(RIGHT_HIGHER);
		RotateRight(subRoot);
		shorter = false;
		break;
	case RIGHT_HIGHER: //double rotation right
		BinaryNode<Record> *subTree = leftTree->right;
		switch (subTree->GetBalance())
		{
		case EQUAL_HEIGHT:
			subRoot->SetBalance(EQUAL_HEIGHT);
			leftTree->SetBalance(EQUAL_HEIGHT);
			break;
		case RIGHT_HIGHER:
			subRoot->SetBalance(EQUAL_HEIGHT);
			leftTree->SetBalance(LEFT_HIGHER);
			break;
		case LEFT_HIGHER:
			subRoot->SetBalance(RIGHT_HIGHER);
			leftTree->SetBalance(EQUAL_HEIGHT);
			break;
		}
		subTree->SetBalance(EQUAL_HEIGHT);
		RotateLeft(leftTree);
		RotateRight(subRoot);
		shorter = true;
		break;
	}
	return shorter;
}

#endif