#include "Linked_List.h"

void Print(char &n);

void Introduction();
void Instruction();
bool DoCalculation(char command, List<char> &l);
char GetCommand();

//	convenient functions for List
template <class List_entry>
Error_code InsertFrist(const List_entry &x, List<List_entry> &list);

template <class List_entry>
Error_code InsertLast(const List_entry &x, List<List_entry> &list);

template <class List_entry>
Error_code RemoveFrist(List_entry &x, List<List_entry> &list);

template <class List_entry>
Error_code RemoveLast(List_entry &x, List<List_entry> &list);

template <class List_entry>
Error_code RetrieveMedian(List_entry &x, List<List_entry> &list);

template <class List_entry>
Error_code Copy(List<List_entry> &dest, List<List_entry> &source);

template <class List_entry>
Error_code Split(List<List_entry> &source, List<List_entry> &oddList, List<List_entry> &evenList);

int main()
//	test of the List Class
{
	List <char> chars;
	Introduction();
	Instruction();
	while (DoCalculation(GetCommand(), chars));

	return 0;
}

void Introduction()
//	Post:	cout introductions
{
	cout << "Welcome to the test of the List Class!\n" << flush;
}

void Instruction()
//	Post:	cout instructions
{
	cout << "Please enter a valid command:" << endl
		<< "[?]push to list   [P]print all" << endl
		<< "[S]search for an element	[C]clear the list" << endl
		<< "[#]report the size of the list	[D]delete an element" << endl
		<< "[Q]uit." << endl;
}

char GetCommand()
//	Post:	if not valid, continue prompting user to input
//			else return the command
{
	char ch;		//command
	cout << "Select command and press <Enter>: " << flush;
	cin >> ch;
	ch = tolower(ch);
	while (ch != '?' && ch != 's' && ch != 'p' && ch != 'q' &&
		   ch != 'c' && ch != '#' && ch != 'd')
	{
		Instruction();
		cin >> ch;
	}
	return ch;
}

bool DoCalculation(char command, List <char> &l)
//	Pre:	command is valid
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'
{
	char ch, ch2; 
	unsigned int pos;
	bool found = false;
	switch (command)
	{
	case '?':
		cout << "Please input a character: " << flush;
		Cin(ch);
		cout << "Then the position to insert? " << flush;
		Cin(pos);
		if(l.Insert(pos, ch) != success)
			cout << "Warning: List full, lost number." << endl;
		break;
	case 's':
		cout << "Please input the character you want to search for: " << flush;
		Cin(ch);
		for (int i = 0; i < l.Size(); i++)
		{
			l.Retrieve(i, ch2);
			if (ch == ch2)
			{
				cout << "Position " << i << ", find for \'" << ch << "\'." << endl;
				found = true;
			}
		}
		if (!found)
		cout << "No found." << endl;
		break;
	case 'p':
		if (l.Empty())	
			cout << "No entries." << endl;
		else
		{
			cout << "The entries are:" << endl;
			l.Traverse(Print);
		}
		break;
	case '#':
		cout << "Size: " << l.Size() << endl;
		break;
	case 'c':
		l.Clear();
		break;
	case 'd':
		cout << "Please input the position of the character you want to delete: " << flush;
		Cin(pos);
		if (l.Remove(pos, ch2) != success)
			cout << "No found." << endl;
		break;
	case 'q':
		cout << "Test finished.\n" << flush;
		return false;
	}
	return true;
}

void Print(char &n)
{
	cout << n << endl;
}

template <class List_entry>
Error_code InsertFrist(List_entry &x, List<List_entry> &list)
//	Post:	x is added to the head of the list.
//	Note:	If the function fails, it will return a diagnostic error code.
{
	return list.Insert(0, x);
}

template <class List_entry>
Error_code InsertLast(List_entry &x, List<List_entry> &list)
//	Post:	x is added to the bottom of the list.
//	Note:	If the function fails, it will return a diagnostic error code.
{
	return list.Insert(list.Size(), x);
}

template <class List_entry>
Error_code RemoveFrist(List_entry &x, List<List_entry> &list)
//	Post:	The first entry is removed from the head of the list,
//			and stored in x.
//	Note:	If the function fails, it will return a diagnostic error code.
{
	return list.Remove(0, x);
}

template <class List_entry>
Error_code RemoveLast(List_entry &x, List<List_entry> &list)
//	Post:	The last entry is removed from the head of the list,
//			and stored in x.
//	Note:	If the function fails, it will return a diagnostic error code.
{
	return list.Remove(list.Size() - 1, x);
}

template <class List_entry>
Error_code RetrieveMedian(List_entry &x, List<List_entry> &list)
//	Post:	The central entry(if odd numbers of entries in the list)
//			or the left-central entry is retrieved to x.
//	Note:	If the function fails, it will return a diagnostic error code.
{
	return list.Retrieve((list.Size() - 1) / 2, x);
}

template <class List_entry>
Error_code Copy(List<List_entry> &dest, List<List_entry> &source)
//	Post:	Copy all entries from source to dest, for it will not fail,
//			the function always return success.
{
	if (&source == &dest)	return success;
	dest.Clear();
	for (int i = 0; i < source.Size(); i++)
	{
		List_entry x;
		source.Retrieve(i, x);
		dest.Insert(i, x);
	}
	return success;
}

template <class List_entry>
Error_code Split(List<List_entry> &source, List<List_entry> &oddList, List<List_entry> &evenList)
//	Pre:	oddList and evenList should not be the same as source or same as each other.
//	Post:	Copies all entries from source so that entries in odd-numbered positions are kept in 
//			oddList, and even-numbered in evenList.The original entries in oddList and evenList
//			will be discarded. For it will not fail, the function always return success.
//			If one of oddList and evenList is the same as source, do nth to that list.
{
	//oddList
	if (&source != &oddList)
	{
		oddList.Clear();
		for (int i = 0; 2 * i + 1 < source.Size(); i++)
		{
			List_entry x;
			source.Retrieve(2 * i + 1, x);
			oddList.Insert(i, x);
		}
	}
	if (&source != &evenList)
	{
		evenList.Clear();
		for (int i = 0; 2 * i < source.Size(); i++)
		{
			List_entry x;
			source.Retrieve(2 * i, x);
			evenList.Insert(i, x);
		}
	}
	return success;
}
