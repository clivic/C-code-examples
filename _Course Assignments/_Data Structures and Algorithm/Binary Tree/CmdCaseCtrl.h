//*******************************************************************
//	Case control for client function DoCommand in Tree Derival.
//*******************************************************************
#ifndef CASECTRL
#define CASECTRL
#include "AVL_Tree.h"

enum PrintState{ PRE_ORDER, IN_ORDER, POST_ORDER, TRAV_ORDER };

class CmdCaseCtrl
{
public:
	CmdCaseCtrl();
	void Append(BinaryTree<int> &bT);
	void Delete(BinaryTree<int> &bT);
	void Print(BinaryTree<int> &bT) const;
	void GetLeaves(const BinaryTree<int> &bT) const;
	void GetSize(const BinaryTree<int> &bT) const;
	void InterchangeLR(BinaryTree<int> &bT);
	void ClearTree(BinaryTree<int> &bT);

protected:
	//Tools and Storage space for DoCommand function to use:
	int tmpEntry;

	//Tool functions:
};

void PrintEntry(int &entry);	//for Print

#endif