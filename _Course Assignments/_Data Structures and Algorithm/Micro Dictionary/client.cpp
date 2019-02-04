//*******************************************************************
//	Micro dictionary management
//*******************************************************************
#include "CmdCaseCrtl.h"

//tools for main function
void Introduction();
void Instruction();
bool DoCommand(	char command, 
				List<Record> &list, 
				HashTable &hashTable, 
				bool &searchState,
				bool &storageState);
char GetCommand();
Error_code Load(List<Record> &l, Record &temp);		//load CERT4(DOS) in traditional list
Error_code LoadHash(List<Record> &l, 
					HashTable &h, Record &temp);	//load CERT4(DOS) in hash table
ifstream fin("CERT4(DOS).TXT");

int main()
{
	List<Record> list;
	HashTable hashTable;
	Record temp;
	if (Load(list, temp) != success)
	{
		cerr << "Fail to load vocalburary in List, existed." << endl;
		return 1;
	}

	if (LoadHash(list, hashTable, temp) != success)
	{
		cerr << "Fail to load vocalburary in Hash Table, existed." << endl;
		return 1;
	}

	Introduction();
	Instruction();
	bool searchState = 1;	//Initialization. 1 represents accurate searching, and 0 fuzzy searching.
	bool storageState = 1;	//Initialization. 1 represents list storage, and 0 hash storage.
	while (DoCommand(GetCommand(), list, hashTable, searchState, storageState));
	return 0;
}

Error_code Load(List<Record> &l, Record &temp)
//	Post:	load the vocalbulary, if failed, return the Error_code. 
//			else return success.
{
	int num;	String word;	int fre;	String elt;	char str[100];
	bool initialResponse = true;
	while (fin >> num)	//read number(and prevent EOF)
	{
		initialResponse = false;
		fin.ignore(100, ',');			//ignore the comma
		
		//read word
		fin.getline(str, 100, ',');
		word = str;						//already ignored comma

		//read frequency
		fin >> fre;
		fin.ignore();					//ignore the comma

		//read explanation
		fin.getline(str, 100);			//already ignored comma
		elt = str;

		temp.WriteNum(num);
		temp.WriteWord(word);
		temp.WriteFrequency(fre);
		temp.WriteExplanation(elt);

		l.Insert(l.Size(), temp);
	} while (fin);
	if (initialResponse)	return fail;
	return success;
}

Error_code LoadHash(List<Record> &l, HashTable &h, Record &temp)
//	Post:	load the vocalbulary in List<Record> l into HashTable h, 
//			if failed, return the Error_code, else return success.
{
	int i = 0;
	for (; i < l.Size(); i++)
	{
		l.Retrieve(i, temp);
		h.Insert(temp);
	}
	if (i==0)	return fail;
	return success;
}

void Introduction()
{
	printf("Welcome to use MicroDictionary!\n");
	printf("This dictionary contains about 4.5 thousand words,\n");
	printf("and the so-called \"micro\" vocabulary is perhaps enough ");
	printf("for daily use.\n");
	printf("Wish you to have fun at learning!\n\n");

	printf("Notes: Please notice that the default searching way is accurate search.\n");
	printf("And for the commands, [T]est is for advanced efficiency test of search method,\n");
	printf("users can append a word into the vocabulary but are temporarily stored,\n");
	printf("after the program ends users can not refer to words they appended.\n");
	printf("It's a current technical defect, hope you can tolerent it.\n");
	printf("also users can delete them, but you can only delete the appended words,\n");
	printf("not the core words.\n");
	cout << endl;
}

void Instruction()
{
	printf("Command menu:\n");
	printf("[~] Use list storage searching.         [#] Use table storage searching.\n");
	printf("[A] Set accurate search.                [F] Set fuzzy search.\n");
	printf("[S] Start to search words Eng-Chi.      [H] Help.\n");
	printf("[N] New word store.                     [D] Delete word.\n");
	printf("[Q] Quit.\n");
	cout << endl;
	//Hiden: for inside testing:	[T] Test the sort method's efficiency.	
	//								[P] Print the vocabulary.
}

char GetCommand()
//	Post:	if not valid, continue prompting user to input
//			else return the command.
{
	char ch;		//command
	cout << "Select command and press <Enter>: " << flush;
	cin >> ch;
	ch = toupper(ch);
	while (ch != 'A' && ch != 'F' && ch != 'S' && ch != 'H' && ch != 'Q'
		&& ch != 'T' && ch != 'P' && ch != 'N' && ch != 'D' && ch != '~'
		&& ch != '#')
	{
		cout << "Please enter a valid command, or press [H] for help:"
			<< flush;
		cin >> ch;
		ch = toupper(ch);
	}
	return ch;
}

bool DoCommand(char command, List<Record> &list, HashTable &hashTable, bool &searchState, bool &storageState)
//	Pre:	command is valid.
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'.
{
	CmdCaseCtrl cmd(searchState, storageState, false);
	switch (command)
	{
	case '~':
		cmd.SetList();				break;

	case '#':
		cmd.SetHash();				break;

	case 'A':
		cmd.SetAcSearch();			break;

	case 'F':
		cmd.SetFzSearch();			break;

	case 'S':
		cmd.Search(list,hashTable);	break;

	case 'H':
		Instruction();				break;

	case 'T':
		cmd.Test(list, hashTable);	break;

	case 'P':
		cmd.Print(list, hashTable);	break;

	case 'N':
		cmd.AddNew(list, hashTable);break;

	case 'D':
		cmd.DelNew(list, hashTable);break;

	case 'Q':
		return false;
		break;
		
	}
	cmd.UpdateState(searchState, storageState);
	return true;
}