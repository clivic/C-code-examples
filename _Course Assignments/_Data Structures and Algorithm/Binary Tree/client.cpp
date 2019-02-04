//*******************************************************************
//	Client to drive all the trees in the DOS interface.
//	Uses:	DoCommand and GetCommand structure.
//*******************************************************************
#include "AVL_Tree.h"
#include "Key and Record.h"
#include "CmdCaseCtrl.h"

//tools for main function
void Introduction();
void Instruction();
bool DoCommand(char command, BinaryTree<int> &bT);
char GetCommand();

void main()
{
	BinaryTree<int> binTree;
	Introduction();
	Instruction();
	while (DoCommand(GetCommand(), binTree));
}

void Introduction()
{
	printf("Welcome to the tree test!\n");
	cout << endl;
}

void Instruction()
{
	printf("Command menu:\n");
	printf("[A] Append a new integer.               [D] Delete the integer in the tree.\n");
	printf("[P] Print the tree in three orders.     [H] Help.\n");
	printf("[L] Leaves number returned.             [S] Size of the tree returned.\n");
	printf("[I] Interchange the tree left and right.[C] Clear the whole Tree\n");
	printf("[Q] Quit.\n");
	cout << endl;
}

char GetCommand()
//	Post:	if not valid, continue prompting user to input
//			else return the command.
{
	char ch;		//command
	cout << "Select command and press <Enter>: " << flush;
	cin >> ch;
	ch = toupper(ch);
	while (ch != 'A' && ch != 'D' && ch != 'P' && ch != 'H' && ch != 'L'
		&& ch != 'S' && ch != 'I' && ch != 'C' && ch != 'Q')
	{
		cout << "Please enter a valid command, or press [H] for help:"
			<< flush;
		cin >> ch;
		ch = toupper(ch);
	}
	return ch;
}

bool DoCommand(char command, BinaryTree<int> &bT)
//	Pre:	command is valid.
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'.
{
	CmdCaseCtrl cmd;
	switch (command)
	{
	case 'A':
		cmd.Append(bT);			break;

	case 'D':
		cmd.Delete(bT);			break;

	case 'P':
		cmd.Print(bT);			break;

	case 'H':
		Instruction();			break;

	case 'L':
		cmd.GetLeaves(bT);		break;

	case 'S':
		cmd.GetSize(bT);		break;

	case 'I':
		cmd.InterchangeLR(bT);	break;

	case'C':
		cmd.ClearTree(bT);		break;

	case 'Q':
		return false;			break;
	}
	return true;
}