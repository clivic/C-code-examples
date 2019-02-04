////*************************************************************************************************
////	Test2: for the Stack Stack -- Demonstration
////*************************************************************************************************
//#include "Linked_Stack.h"
//#include "Linked_Stack.cpp"
//
//template <class Type>
//void Cin(/* inout */ Type& input);
//
//void Introduction();
//void Help();
//bool DoCalculation(char command, Stack <char> &q);
//char GetCommand();
//
//int main()
////	Post:	test stack by a menu-given interface
////	Uses:	Stack Stack(version: array_circle), functions Introduction,
////			SoCalculation, GetCommand and Help.
//{
//	Stack <char> stock;
//	Introduction();
//	while (DoCalculation(GetCommand(), stock));
//
//	return 0;
//}
//
//void Introduction()
////	Pre:	none
////	Post:	cout Help messages
//{
//	Help();
//}
//
//void Help()
////	Pre:	none
////	Post:	cout Help messages
//{
//	cout << endl
//		<< "This program allows the user to enter one command" << endl
//		<< "(but only one) on each input line." << endl
//		<< "For example, if the command P is entered, then" << endl
//		<< "the program will pop the top entry of the stack." << endl
//		<< endl
//
//		<< " The valid commands are:" << endl
//		<< "A - Add(push) an item into stack." << endl
//		<< "P - Pop the front of the stack." << endl
//		<< "R - Pop and print the front entry." << endl
//		<< "# - The current size of the stack." << endl
//		<< "C - Clear the whole stack (same as delete)." << endl
//		<< "H - This help screen." << endl
//		<< "Q - Quit." << endl;
//}
//
//char GetCommand()
////	Pre:	none
////	Post:	if not valid, continue prompting user to input
////			else return the command
//{
//	char ch;		//command
//	cout << "Select command and press <Enter>: " << flush;
//	cin >> ch;
//	ch = toupper(ch);
//	while (ch != 'A' && ch != 'P' && ch != 'R' && ch != '#'
//		&& ch != 'C' && ch != 'H' && ch != 'Q')
//	{
//		cout << "Please enter a valid command, or press [H] for help:"
//			<< flush;
//		cin >> ch;
//		ch = toupper(ch);
//	}
//	return ch;
//}
//
//bool DoCalculation(char command, Stack <char> &s)
////	Pre:	command is valid
////	Post:	do according to the command, and return false unless 
////			command is 'Q' or 'q'
//{
//	char p;
//	switch (command)
//	{
//	case 'A':
//		cout << "Enter a character: " << flush;
//		Cin(p);
//		if (s.push(p) == overflow)
//			cout << "Warning: Stack full, lost number." << endl;
//		else
//			cout << "Pushed successfully!" << endl;
//		break;
//
//	case 'P':
//		if (s.pop() == underflow)
//			cout << "Stack empty." << endl;
//		else
//			cout << "Popped successfully!" << endl;
//		break;
//
//	case 'R':
//		
//		if (s.top(p) == underflow)
//			cout << "Stack empty." << endl;
//		else
//		{
//			cout << p << endl;
//			s.pop();
//			cout << "Popped successfully!" << endl;
//		}
//		break;
//
//	case '#':
//		cout << "Current size: " << s.size() << endl;
//		break;
//
//	case 'C':
//		s.clear();
//		cout << "Cleared successfully!" << endl;
//		break;
//
//	case 'H':
//		Help();
//		break;
//
//	case 'Q':
//		cout << "Test finished.\n" << flush;
//		return false;
//	}
//
//	return true;
//}
//
//template <class Type>
//void Cin(/* inout */ Type& input)
////	Pre:	the object for cin should support "cin operation".
////	Post:	cin a number && IF cin breaks down,
////			prompt user to re-enter the object && clear the cin.	
////	Note:	for template, should include utility.cpp.
//{
//	cin >> input;
//	//prevent the case of not number
//	while (!cin)
//	{
//		cout << "Invalid input, please input again: " << flush;
//		cin.clear();
//		cin.sync();
//		cin >> input;
//	}
//}