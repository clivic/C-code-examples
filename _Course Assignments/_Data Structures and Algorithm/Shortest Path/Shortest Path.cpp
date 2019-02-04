//*****************************************************************************
// Shortest path solution for Computer network
//*****************************************************************************
#include "utility.h"

enum Node{ A, B, C, D, E, F, G, H };
enum State{ ADJ, N_ADJ, SELF };

struct Dest
{
	int distance;
	int distanceNew;
	Node next;
	Node nextNew;
};

struct Table
{
	Dest dest[8];
	State adjList[8];
	void Renew(Table table[]);
};

void Table::Renew(Table table[])
//	Pre:	table should be size 8 array.
//	Post:	the table's destinatioin text are renewed.
{
	int newDist;

	for (int destNode = 0; destNode < 8; destNode++)
	{
		// inherit previous state
		dest[destNode].distanceNew = dest[destNode].distance;
		dest[destNode].nextNew = dest[destNode].next;
		if (dest[destNode].distance != 0)
		{
			// whether there are shorter paths through adjacent nodes
			for (int adjNode = 0; adjNode < 8; adjNode++)
			{
				if (adjList[adjNode] == ADJ)
				{
					newDist = dest[adjNode].distance + table[adjNode].dest[destNode].distance;
					if (newDist < dest[destNode].distanceNew)
					{
						// new text stored
						dest[destNode].distanceNew = newDist;
						dest[destNode].nextNew = (Node)adjNode;
					}					
				}
			}
		}
	}
}

void RenewAll(Table table[])
//	Pre:	table should be size 8 array.
//	Post:	all destinatioin text are renewed.
{
	table[0].Renew(table);
	table[1].Renew(table);
	table[2].Renew(table);
	table[3].Renew(table);
	table[4].Renew(table);
	table[5].Renew(table);
	table[6].Renew(table);
	table[7].Renew(table);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			table[i].dest[j].distance = table[i].dest[j].distanceNew;
			table[i].dest[j].next = table[i].dest[j].nextNew;
		}
	}
}

void InitializeA(Table &node)
{
	node.dest[0].distance = 0;
	node.dest[0].next = A;
	node.dest[1].distance = 4;
	node.dest[1].next = B;
	node.dest[2].distance = 999;
	node.dest[2].next = C;
	node.dest[3].distance = 999;
	node.dest[3].next = D;
	node.dest[4].distance = 10;
	node.dest[4].next = E;
	node.dest[5].distance = 999;
	node.dest[5].next = F;
	node.dest[6].distance = 999;
	node.dest[6].next = G;
	node.dest[7].distance = 999;
	node.dest[7].next = H;
	node.adjList[0] = SELF;
	node.adjList[1] = ADJ;
	node.adjList[2] = N_ADJ;
	node.adjList[3] = N_ADJ;
	node.adjList[4] = ADJ;
	node.adjList[5] = N_ADJ;
	node.adjList[6] = N_ADJ;
	node.adjList[7] = N_ADJ;
}

void InitializeB(Table &node)
{
	node.dest[0].distance = 4;
	node.dest[0].next = A;
	node.dest[1].distance = 0;
	node.dest[1].next = B;
	node.dest[2].distance = 2;
	node.dest[2].next = C;
	node.dest[3].distance = 999;
	node.dest[3].next = D;
	node.dest[4].distance = 4;
	node.dest[4].next = E;
	node.dest[5].distance = 3;
	node.dest[5].next = F;
	node.dest[6].distance = 3;
	node.dest[6].next = G;
	node.dest[7].distance = 999;
	node.dest[7].next = H;
	node.adjList[0] = ADJ;
	node.adjList[1] = SELF;
	node.adjList[2] = ADJ;
	node.adjList[3] = N_ADJ;
	node.adjList[4] = ADJ;
	node.adjList[5] = ADJ;
	node.adjList[6] = ADJ;
	node.adjList[7] = N_ADJ;
}

void InitializeC(Table &node)
{
	node.dest[0].distance = 999;
	node.dest[0].next = A;
	node.dest[1].distance = 2;
	node.dest[1].next = B;
	node.dest[2].distance = 0;
	node.dest[2].next = C;
	node.dest[3].distance = 2;
	node.dest[3].next = D;
	node.dest[4].distance = 1;
	node.dest[4].next = E;
	node.dest[5].distance = 999;
	node.dest[5].next = F;
	node.dest[6].distance = 999;
	node.dest[6].next = G;
	node.dest[7].distance = 3;
	node.dest[7].next = H;
	node.adjList[0] = N_ADJ;
	node.adjList[1] = ADJ;
	node.adjList[2] = SELF;
	node.adjList[3] = ADJ;
	node.adjList[4] = ADJ;
	node.adjList[5] = N_ADJ;
	node.adjList[6] = N_ADJ;
	node.adjList[7] = ADJ;
}

void InitializeD(Table &node)
{
	node.dest[0].distance = 999;
	node.dest[0].next = A;
	node.dest[1].distance = 999;
	node.dest[1].next = B;
	node.dest[2].distance = 2;
	node.dest[2].next = C;
	node.dest[3].distance = 0;
	node.dest[3].next = D;
	node.dest[4].distance = 2;
	node.dest[4].next = E;
	node.dest[5].distance = 999;
	node.dest[5].next = F;
	node.dest[6].distance = 999;
	node.dest[6].next = G;
	node.dest[7].distance = 999;
	node.dest[7].next = H;
	node.adjList[0] = N_ADJ;
	node.adjList[1] = N_ADJ;
	node.adjList[2] = ADJ;
	node.adjList[3] = SELF;
	node.adjList[4] = ADJ;
	node.adjList[5] = N_ADJ;
	node.adjList[6] = N_ADJ;
	node.adjList[7] = N_ADJ;
}

void InitializeE(Table &node)
{
	node.dest[0].distance = 10;
	node.dest[0].next = A;
	node.dest[1].distance = 4;
	node.dest[1].next = B;
	node.dest[2].distance = 1;
	node.dest[2].next = C;
	node.dest[3].distance = 2;
	node.dest[3].next = D;
	node.dest[4].distance = 0;
	node.dest[4].next = E;
	node.dest[5].distance = 2;
	node.dest[5].next = F;
	node.dest[6].distance = 999;
	node.dest[6].next = G;
	node.dest[7].distance = 999;
	node.dest[7].next = H;
	node.adjList[0] = ADJ;
	node.adjList[1] = ADJ;
	node.adjList[2] = ADJ;
	node.adjList[3] = ADJ;
	node.adjList[4] = SELF;
	node.adjList[5] = ADJ;
	node.adjList[6] = N_ADJ;
	node.adjList[7] = N_ADJ;
}

void InitializeF(Table &node)
{
	node.dest[0].distance = 999;
	node.dest[0].next = A;
	node.dest[1].distance = 3;
	node.dest[1].next = B;
	node.dest[2].distance = 999;
	node.dest[2].next = C;
	node.dest[3].distance = 999;
	node.dest[3].next = D;
	node.dest[4].distance = 2;
	node.dest[4].next = E;
	node.dest[5].distance = 0;
	node.dest[5].next = F;
	node.dest[6].distance = 4;
	node.dest[6].next = G;
	node.dest[7].distance = 999;
	node.dest[7].next = H;
	node.adjList[0] = N_ADJ;
	node.adjList[1] = ADJ;
	node.adjList[2] = N_ADJ;
	node.adjList[3] = N_ADJ;
	node.adjList[4] = ADJ;
	node.adjList[5] = SELF;
	node.adjList[6] = ADJ;
	node.adjList[7] = N_ADJ;
}

void InitializeG(Table &node)
{
	node.dest[0].distance = 999;
	node.dest[0].next = A;
	node.dest[1].distance = 3;
	node.dest[1].next = B;
	node.dest[2].distance = 999;
	node.dest[2].next = C;
	node.dest[3].distance = 999;
	node.dest[3].next = D;
	node.dest[4].distance = 999;
	node.dest[4].next = E;
	node.dest[5].distance = 4;
	node.dest[5].next = F;
	node.dest[6].distance = 0;
	node.dest[6].next = G;
	node.dest[7].distance = 999;
	node.dest[7].next = H;
	node.adjList[0] = N_ADJ;
	node.adjList[1] = ADJ;
	node.adjList[2] = N_ADJ;
	node.adjList[3] = N_ADJ;
	node.adjList[4] = N_ADJ;
	node.adjList[5] = ADJ;
	node.adjList[6] = SELF;
	node.adjList[7] = N_ADJ;
}

void InitializeH(Table &node)
{
	node.dest[0].distance = 999;
	node.dest[0].next = A;
	node.dest[1].distance = 999;
	node.dest[1].next = B;
	node.dest[2].distance = 3;
	node.dest[2].next = C;
	node.dest[3].distance = 999;
	node.dest[3].next = D;
	node.dest[4].distance = 999;
	node.dest[4].next = E;
	node.dest[5].distance = 999;
	node.dest[5].next = F;
	node.dest[6].distance = 999;
	node.dest[6].next = G;
	node.dest[7].distance = 0;
	node.dest[7].next = H;
	node.adjList[0] = N_ADJ;
	node.adjList[1] = N_ADJ;
	node.adjList[2] = ADJ;
	node.adjList[3] = N_ADJ;
	node.adjList[4] = N_ADJ;
	node.adjList[5] = N_ADJ;
	node.adjList[6] = N_ADJ;
	node.adjList[7] = SELF;
}

void InitializeAll(Table table[])
//	Pre:	table should be size 8 array.
//	Post:	the network is initialized.
{
	InitializeA(table[0]);
	InitializeB(table[1]);
	InitializeC(table[2]);
	InitializeD(table[3]);
	InitializeE(table[4]);
	InitializeF(table[5]);
	InitializeG(table[6]);
	InitializeH(table[7]);
}

void Introduction()
{
	cout << "Welcome to The simulation of IP layer shortest path calculation!\n"
		<< "This is the speculated simulation for the assignment of the graph given.\n"
		<< "Have a good time!\n" << flush;
}

void Instruction()
{
	cout << "Command Menu:" << endl
		<< "[S]Get start             [A]Find once a time" << endl
		<< "[O]Find in certain times [R]Reset the network" << endl
		<< "[H]Help for Command Menu [P]Print all nodes" << endl
		<< "[Q]Quit." << endl;
}

char GetCommand()
//	Post:	if not valid, continue prompting user to input
//			else return the command.
{
	char ch;		//command
	cout << "Select command and press <Enter>: " << flush;
	cin >> ch;
	ch = tolower(ch);
	while (ch != 's' && ch != 'a' && ch != 'r' && ch != 'o'
		&& ch != 'p' && ch != 'h' && ch != 'q')
	{
		cout << "Please enter a valid command, or press [H] for help:"
			<< flush;
		cin >> ch;
		ch = tolower(ch);
	}
	return ch;
}

void PrintNode(Table &node, const char &no)
//	Pre:	should be used after RenewAll().
//	Post:	Post out node form.
{
	string blankForm = "          ";
	int unitLen = blankForm.length();
	cout << "Node " << no << ":\n"
		<< "Node      " << "Distance  " << "Next Node\n";
	for (int i = 0; i < 8; i++)
		cout << (char)('A' + i) << blankForm.substr(0, unitLen - 1)
		<< setw(unitLen) << left << node.dest[i].distance
		<< setw(unitLen) << left << (char)('A' + node.dest[i].next) << endl;
	cout << endl;
}

void PrintAll(Table table[])
//	Pre:	should be used after RenewAll() and table should be size 8 array.
//	Post:	Post out all node's forms.
{
	cout << "************************************************\n" << endl;
	for (int i = 0; i < 8; i++)
		PrintNode(table[i], (char)('A'+i));
	cout << "************************************************\n" << endl;
}

void StartSimulation(int num, Table table[])
//	Pre:	used by DoOperation().
//	Post:	simulate and output the results in demand formally.
{
	cout << "Starting to renew forms in every nodes..." << endl;
	for (int i = 0; i < num; i++)	//five times is enough
		RenewAll(table);
	cout << "Finished.\n" << endl;
	PrintAll(table);
}

bool DoOperation(char command, Table table[])
//	Pre:	command is valid.
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'.
{
	int num = 1;
	switch (command)
	{
	case 's':
		StartSimulation(5, table);
		break;

	case 'a':
		StartSimulation(1, table);
		break;

	case 'o':
		cout << "Please input the times you wanna find: ";
		Cin(num);
		StartSimulation(num, table);
		break;

	case 'r':
		cout << "Reseting..." << endl;
		InitializeAll(table);
		cout << "Finished.\n" << endl;
		break;

	case 'p':
		cout << "There are the current situation:" << endl;
		PrintAll(table);
		break;

	case 'h':
		Instruction();
		break;

	case 'q':
		cout << "Simulation exited.\n" << flush;
		return false;
	}
	return true;
}

int main()
{
	Table table[8];
	InitializeAll(table);
	Introduction();
	Instruction();
	while (DoOperation(GetCommand(), table));
	return 0;
}