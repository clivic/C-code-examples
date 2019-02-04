//*******************************************************************
//	Polynomial Arithmatic program
//*******************************************************************
#include "utility.h"
#include "Linked_Stack.h"
#include "Polynomial.h"

Stack<Polynomial> storedPolys;
void introduction();
void instructions();
bool do_command(char command, Stack<Polynomial> &storedPolys);
char get_command();

int main()
//Post:	The program has executed simple polynomial arithmetic
//		commands entered by the user.
//Uses:	The classes Stack and Polynomial and the functions
//		introduction, instructions, do_command, and get_command.
{
	introduction();
	instructions();
	while (do_command(get_command(), storedPolys));
}

void introduction()
{
	cout << "Welcome to use Polynomial Arithmatic program. It is version 1.0, and has these properties:\n"
		<< "1. We can enter many polynomial expressions as we like to do calculations.\n"
		<< "2. It supports Addition, Substraction, Production of polynomials, not yet quotients now.\n" 
		<< "3. We should use commands to do the corresponding operations.\n\n"
		<< flush;
}

void instructions()
{
	cout << "Please enter a valid command:" << endl
		<< "[?] Read a Polynomial" << endl
		<< "[=] Return Top Polynomial" << endl
		<< "[+] Sum two Polynomial" << endl
		<< "[-] Difference two Polynomial" << endl
		<< "[*] Multiply one Polynomial with a Term" << endl
		<< "[q] Quit." << endl;
}

char get_command()
//	Post:	if not valid, continue prompting user to input
//			else return the command
{
	char command;
	cout << "Select command and press <Enter>:";
	cin >> command;
	command = tolower(command);
	while (command != '?' && command != '=' && command != '+' &&
		   command != '-' && command != '*' && command != 'q')
	{
		instructions();
		cin >> command;
		command = tolower(command);
	}
	return command;
}

bool do_command(char command, Stack<Polynomial> &storedPolys)
//	Pre:	The first parameter specifies a valid calculator command.
//	Post:	The command specified by the first parameter
//			has been applied to the Stack of Polynomial
//			objects given by the second parameter.
//			A result of true is returned unless command == 'q'.
//	Uses:	The classes Stack and Polynomial.
{
	Polynomial p, q, r;

	switch (command)
	{
	case '?':
		p.Read();
		if (storedPolys.Push(p) == overflow)
			cout << "Warning: Stack full, lost polynomial." << endl;
		break;

	case '=':
		if (storedPolys.Empty())
			cout << "Stack empty." << endl;
		else
		{
			storedPolys.Top(p);
			p.Print();
		}
		break;

	case '+':
	case '-':
	case '*':
		if (storedPolys.Empty())
			cout << "Stack empty." << endl;
		else
		{
			storedPolys.Top(p);
			storedPolys.Pop();
			if (storedPolys.Empty()) 
			{
				cout << "Stack has just one polynomial." << endl;
				storedPolys.Push(p);
			}
			else
			{
				storedPolys.Top(q);
				storedPolys.Pop();
				
				switch (command)
				{
				case '+':
					r.SumPoly(q, p);
					break;
				case '-':
					r.DifferencePoly(q, p);
					break;
				case '*':
					r.ProductPoly(q, p);
					break;
				}
				
				if (storedPolys.Push(r) == overflow)
					cout << "Warning: Stack full, lost polynomial." << endl;
			}
		}
		break;

	case 'q':
		cout << "Calculation finished." << endl;
		return false;
	}
	return true;
}
