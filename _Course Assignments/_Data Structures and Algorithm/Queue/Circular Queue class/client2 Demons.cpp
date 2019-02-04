//*************************************************************************************************
//	Test2: for the Queue Queue -- Demonstration
//*************************************************************************************************
#include "Queue.h"
#include "Queue.cpp"
//#include "D:\Visual C++ programs\Utility\Utility.cpp"

template <class Type>
void Cin(/* inout */ Type& input);

void Introduction();
void Help();
bool DoCalculation(char command, Queue <char> &q);
char GetCommand();

int main()
//	Post:	test queue by a menu-given interface
//	Uses:	Queue Stack(version: array_circle), functions Introduction,
//			SoCalculation, GetCommand and Help.
{
	Queue <char> storedNums;
	Introduction();
	while (DoCalculation(GetCommand(), storedNums));

	return 0;
}

void Introduction()
//	Pre:	none
//	Post:	cout Help messages
{
	Help();
}

void Help()
//	Pre:	none
//	Post:	cout Help messages
{
	cout << endl
		<< "This program allows the user to enter one command" << endl
		<< "(but only one) on each input line." << endl
		<< "For example, if the command S is entered, then" << endl
		<< "the program will serve the front of the queue." << endl
		<< endl

		<< " The valid commands are:" << endl
		<< "A - Append the next input character to the extended queue." << endl
		<< "S - Serve the front of the queue." << endl
		<< "R - Retrieve and print the front entry." << endl
		<< "# - The current size of the queue." << endl
		<< "C - Clear the whole queue (same as delete)." << endl
		<< "P - Print the queue." << endl
		<< "H - This help screen." << endl
		<< "Q - Quit." << endl;
}

char GetCommand()
//	Pre:	none
//	Post:	if not valid, continue prompting user to input
//			else return the command
{
	char ch;		//command
	cout << "Select command and press <Enter>: " << flush;
	cin >> ch;
	ch = toupper(ch);
	while (ch != 'A' && ch != 'S' && ch != 'R' && ch != '#'
		&& ch != 'C' && ch != 'P' && ch != 'H' && ch != 'Q')
	{
		cout << "Please enter a valid command, or press [H] for help:"
			<< flush;
		cin >> ch;
		ch = toupper(ch);
	}
	return ch;
}

bool DoCalculation(char command, Queue <char> &q)
//	Pre:	command is valid
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'
{
	char p;
	switch (command)
	{
	case 'A':
		cout << "Enter a character: " << flush;
		Cin(p);
		if (q.Append(p) == overflow)
			cout << "Warning: Queue full, lost number." << endl;
		else
			cout << "Appended successfully!" << endl;
		break;

	case 'S':
		if (q.Serve() == underflow)
			cout << "Queue empty." << endl;
		else
			cout << "Served successfully!" << endl;
		break;

	case 'R':
		if (q.ServeAndRetrieve(p) == underflow)
			cout << "Queue empty." << endl;
		else
		{
			cout << p << endl;
			cout << "Served successfully!" << endl;
		}
		break;

	case '#':
		cout << "Current size: " << q.Size() << endl;
		break;

	case 'C':
		q.Clear();
		cout << "Cleared successfully!" << endl;
		break;

	case 'P':
		q.Print();
		break;

	case 'H':
		Help();
		break;

	case 'Q':
		cout << "Test finished.\n" << flush;
		return false;
	}

	return true;
}

template <class Type>
void Cin(/* inout */ Type& input)
//	Pre:	the object for cin should support "cin operation".
//	Post:	cin a number && IF cin breaks down,
//			prompt user to re-enter the object && clear the cin.	
//	Note:	for template, should include utility.cpp.
{
	cin >> input;
	//prevent the case of not number
	while (!cin)
	{
		cout << "Invalid input, please input again: " << flush;
		cin.clear();
		cin.sync();
		cin >> input;
	}
}