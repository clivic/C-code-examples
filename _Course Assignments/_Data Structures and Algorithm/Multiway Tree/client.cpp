//*******************************************************************
//	Client Mr.Bao
//*******************************************************************
#include"BTree.h"

void InsertTree(BTree<char, 5> &bT);

void main()
{
	BTree<char, 5> myBTree;
	InsertTree(myBTree);
	char target;
	do
	{	
		printf("Please input the target you wanna find: ");
		Cin(target);
		Error_code result= myBTree.SearchTree(target);
		printf("Result: ");
		switch (result)
		{
		case success:
			cout << "success." << endl;		break;
		case not_present:
			cout << "not_present" << endl;	break;
		default:							break;
		}

		result = myBTree.Remove(target);
		printf("Remove the target: ");
		switch (result)
		{
		case success:
			cout << "success." << endl;		break;
		case not_present:
			cout << "not_present" << endl;	break;
		default:							break;
		}

		cout << "\nDo you wanna continue? " << flush;
	} while (UserSayYes());
}

void InsertTree(BTree<char, 5> &bT)
{
	bT.Insert('a');
	bT.Insert('g');
	bT.Insert('f');
	bT.Insert('b');
	bT.Insert('k');
	bT.Insert('d');
	bT.Insert('h');
	bT.Insert('m');
	bT.Insert('j');
	bT.Insert('e');
	bT.Insert('s');
	bT.Insert('i');
	bT.Insert('r');
	bT.Insert('x');
	bT.Insert('c');
	bT.Insert('l');
	bT.Insert('n');
	bT.Insert('t');
	bT.Insert('u');
	bT.Insert('p');
	bT.Insert('z');
	bT.Insert('v');
	bT.Insert('o');
	bT.Insert('q');
	bT.Insert('w');
	bT.Insert('y');
}