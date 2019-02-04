//*************************************************************************************************
//	Test of the Stack class -- Porland Caculator
//*************************************************************************************************
#include "Stack.h"
#include "Stack.cpp"
//#pragma comment(lib,"ws2_32.lib")
//
//// client.cpp: 定义控制台应用程序的入口点。
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

void Introduction();
void Instruction();
bool DoCalculation(char command, Stack <double> &s);
char GetCommand();

int main()
//	Reverse Porland Calculation
{
	Stack <double> storedNums;
	Introduction();
	Instruction();
	while (DoCalculation(GetCommand(), storedNums));

	return 0;
}

void Introduction()
//	Pre:	none
//	Post:	cout introductions
{
	cout << "Welcome to use Reverse Polish calculator!\n" << flush;
}

void Instruction()
//	Pre:	none
//	Post:	cout instructions
{
	cout << "Please enter a valid command:" << endl
		<< "[?]push to stack   [=]print top" << endl
		<< "[+] [-] [*] [/]   are arithmetic operations" << endl
		<< "[Q]uit." << endl;
}

char GetCommand()
//	Pre:	none
//	Post:	if not valid, continue prompting user to input
//			else return the command
{
	char ch;		//command
	cout << "Select command and press <Enter>: " << flush;
	cin >> ch;
	ch = tolower(ch);
	while (ch != '?' && ch != '+' && ch != '-' && ch != '*'
		&& ch != '/' && ch != '=' && ch != 'q')
	{
		Instruction();
		cin >> ch;
	}
	return ch;
}

bool DoCalculation(char command, Stack <double> &s)
//	Pre:	command is valid
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'
{
	double p, q;
	switch (command)
	{
	case '?':
		cout << "Enter a real number: " << flush;
		cin >> p;
		//prevent the case of not number
		while (!cin)
		{
			cout << "Not digit, please input again: " << flush;
			cin.clear();
			cin.sync();
			cin >> p;
		}
		if (s.push(p) == overflow)
		{
			cout << "Warning: Stack full, lost number." << endl;
		}
		break;

	case '+':
	case '-':
	case '*':
	case '/':
		if (s.top(p) == underflow)
			cout << "Stack empty." << endl;
		else
		{
			s.pop();
			if (s.top(q) == underflow)
			{
				cout << "Stack contains only one entry." << endl;
				s.push(p);		//return back the entry
			}
			else
			{
				s.pop();
				switch (command)
				{
				case '+':
					s.push(p + q);	break;	//can't overflow 
				case '-':
					s.push(q - p);	break;
				case '*':
					s.push(p * q);	break;
				case '/':
					s.push(q / p);	break;
				}
			}
		}
		break;

	case '=':
		if (s.top(p) == underflow)
			cout << "Stack empty." << endl;
		else
			cout << p << endl;
		break;

	case 'q':
		cout << "Calculation finished.\n" << flush;
		return false;
	}

	return true;
}