//*******************************************************************
//	Test
//*******************************************************************
#include "Random.h"
#include "D:\Visual C++ programs\Utility\utility.h"

void Cin(/* inout */ char& input);
void Help();
void Introduction();
bool DoCalculation(char command, Random rand);
char GetCommand();

int main()
{
	Random r(false);
	Introduction();
	while (DoCalculation(GetCommand(),r));
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
		<< "For example, if the command R is entered, then" << endl
		<< "the program will test RandomReal." << endl
		<< endl

		<< " The valid commands are:" << endl
		<< "R - Test RandomReal" << endl
		<< "I - Test RandomInt" << endl
		<< "P - Test RandomPoisson" << endl
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
	while (ch != 'R' && ch != 'I' && ch != 'P' && ch != 'H' 
		&& ch != 'Q')
	{
		cout << "Please enter a valid command, or press [H] for help:"
			<< flush;
		cin >> ch;
		ch = toupper(ch);
	}
	return ch;
}

bool DoCalculation(char command, Random rand)
//	Pre:	command is valid
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'
{
	int num;
	double sum = 0;		//for calculating
	switch (command)
	{
	case 'R':
	case 'I':
	case 'P':
		
		cout << "Please input the number of calls: " << flush;
		Cin(num);
		int i;
		
			switch (command)
			{
			case 'R':
				for (i = 0; i < num; i++)
					sum += rand.RandomReal();	break;			
			case 'I':
				cout << "Then enter two boundaries, the lower and higher: " << flush;
				int high, low;
				Cin(low);
				Cin(high);
				for (i = 0; i < num; i++)
					sum += rand.RandomInt(low, high);	break;
			case 'P':
				cout << "Then enter the expected value: " << flush;
				double val;
				Cin(val);
				for (i = 0; i < num; i++)
					sum += rand.Poisson(val);
				break;
			}
			
		cout << "Then the average is: " << sum / (double)i << '.' << endl;
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
//	Note:	from utility package.
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