//*******************************************************************
//	CmdCaseCrtl Class Implementation in Tree Derival.
//*******************************************************************
#include "CmdCaseCtrl.h"

CmdCaseCtrl::CmdCaseCtrl(){}
//	Post:	Do nothing.

void CmdCaseCtrl::Append(BinaryTree<int> &bT)
//	Post:	DoCommand case "Append" is done.
{
	printf("Please enter the integer number you wanna input: ");
	Cin(tmpEntry);
	if (bT.Insert(tmpEntry) == success)
		printf("The number %d has been appended successfully!\n", tmpEntry);
	else cerr << "WARNING: Can't append entry into Binary Tree.\n";
	cout << endl;
}

void CmdCaseCtrl::Delete(BinaryTree<int> &bT)
//	Post:	DoCommand case "Delete" is done.
{
	printf("Please enter the integer number you wanna delete: ");
	Cin(tmpEntry);
	if (bT.Remove(tmpEntry) == not_present)
		printf("The number %d not found.\n", tmpEntry);
	else
		printf("The number %d has been deleted successfully!\n", tmpEntry);
	cout << endl;
}

void CmdCaseCtrl::Print(BinaryTree<int> &bT) const
//	Post:	DoCommand case "Print" is done.
{
	int pState;
	printf("Please input the way you wanna output,\n");
	printf("0 means preorder,\n");
	printf("1 means inorder,\n");
	printf("2 means postorder,\n");
	printf("3 means travorder: ");
	Cin(pState);
	switch (pState)
	{
	case PRE_ORDER:
		bT.Preorder(PrintEntry);	break;

	case IN_ORDER:
		bT.Inorder(PrintEntry);		break;

	case POST_ORDER:
		bT.Postorder(PrintEntry);	break;

	case TRAV_ORDER:
		bT.Travorder(PrintEntry);	break;

	default:
		printf("Invalid input.");	break;
	}
	cout << endl << endl;
}

void PrintEntry(int& entry)
{
	printf("%d ", entry);
}

void CmdCaseCtrl::GetLeaves(const BinaryTree<int> &bT) const
//	Post:	DoCommand case "Leaves get number" is done.
{
	printf("The number of leaves is: %d", bT.NumOfLeaves());
	cout << endl << endl;
}

void CmdCaseCtrl::GetSize(const BinaryTree<int> &bT) const
//	Post:	DoCommand case "Size of tree" is done.
{
	printf("Size of the tree is: %d", bT.Size());
	cout << endl << endl;
}

void CmdCaseCtrl::InterchangeLR(BinaryTree<int> &bT)
//	Post:	DoCommand case "Interchange" is done.
{
	bT.Interchange();
	printf("The tree has been interchanged.\n");
	cout << endl;
}

void CmdCaseCtrl::ClearTree(BinaryTree<int> &bT)
//	Post:	DoCommand case "Clear" is done.
{
	bT.Clear();
	printf("The Tree has been all cleared successfully!\n");
	cout << endl;
}