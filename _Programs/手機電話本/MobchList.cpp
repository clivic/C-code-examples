//*************************************************************************************************
//	Chain list implementation
//*************************************************************************************************

#include "MobchList.h"

Node::Node()
{
	entry.name = "";
	entry.phNum = "";
	next = NULL;
}

Node::Node(
	string nameIn,
	string phNumIn)
{
	entry.name = nameIn;
	entry.phNum = phNumIn;
	next = NULL;
}

void Node::NodePrint()
//	used to print itself
{
	cout << entry.name << ' ' 
		 << entry.phNum << endl;
}

//*************************************************************************************************

ChainList::ChainList()
{
	h = pt = ps = NULL;
	len = 0;
}

ChainList::ChainList(
	string nameIn,
	string phNumIn)
{
	h = new Node(nameIn,phNumIn);
	pt = ps = h;
	pt->next = NULL;
	len = 1;
}

void ChainList::FindPos(int i)
//	ps points to the ith member
{
	ps = h;
	if (i <= 0 || i > len)
	{
		cout << "Improper input, do nothing"
			<< '\n';
		return;
	}
	else
	{
		for (int j = 1; j < i; j++)
		{
			ps = ps->next;		//ps points to ith member
		}
	}
}

Node* ChainList::GetAdr() const
//	return h, or the first member's address
{
	return h;
}

int ChainList::GetLen() const
{
	return len;
}

string ChainList::GetName(/* in */ int i) 
{
	FindPos(i);
	return ps->entry.name;
}

string ChainList::GetPhNum(/* in */ int i)
{
	FindPos(i);
	return ps->entry.phNum;
}

ChainList::~ChainList()
{
	if (ps != NULL && pt != NULL && h != NULL)
	{
		ps = h;
		pt = ps->next;
		h = NULL;
		for (int i = 1; i < len; i++)
		{
			delete ps;
			ps = pt;
			pt = pt->next;
		}
		delete ps;
		ps = pt;
	}
}

void ChainList::Print()
//	cout every member's name and phone
//	if empty, cout "List empty."
{
	ps = h;
	for (int i = 0; i < len; i++)
	{
		ps->NodePrint();
		ps = ps->next;
	}	//ps is null after iteration
	if (!len) cout << "List empty." << endl;
}

void ChainList::Print(/* in */ int i)
//	cout ith member's name and phone
//	if no such member, cout "No found"
{
	if (i > len)
		cout << "No found." << endl;
	else
	{
		FindPos(i);
		ps->NodePrint();
	}
}

void ChainList::ModifyName(/* in */ int i)
//	modify name in specified pos
{
	FindPos(i);
	string nameIn;
	cout << "Please input the name, press [Enter] to end: " << flush;
	cin.sync();				//clear the cin buffer
	getline(cin, nameIn);
	ps->entry.name = nameIn;

}

void ChainList::ModifyNum(/* in */ int i)
//	modify phone number in specified pos
{
	FindPos(i);
	string numIn;
	cout << "Please input the phone number, press [Enter] to end: " << flush;
	cin.sync();				//clear the cin buffer
	getline(cin, numIn);
	ps->entry.phNum = numIn;
}

void ChainList::Add()
//	prompt and append a new number
//	Pre:	none
//	Post:	IF no member in chain list, h specified
//			ELSE h unchanged. && new member added
{
	string nameIn;
	string numIn;
	cout << "Creating a new friend...\n"
		<< "Please enter a name, press[Enter] to end :"
		<<  flush;
	cin.sync();				//clear the cin buffer
	getline(cin, nameIn);
	cout << "Please input the phone number, press [Enter] to end: " 
		<< flush;
	cin.sync();				//clear the cin buffer
	getline(cin, numIn);

	if (h == NULL)
	{
		ps = h = new Node();
		ps->entry.name = nameIn;
		ps->entry.phNum = numIn;
		pt = ps->next = NULL;
	}
	else
	{
		FindPos(len);
		pt = ps->next = new Node();
		pt->entry.name = nameIn;
		pt->entry.phNum = numIn;
		pt->next = NULL;
	}
	len++;
}

void ChainList::Delete(/* in */ int i)
//	Delete the (i)th member in the chain list.
//	Precondition:	i >= 0 && i <= len
//	postcondition:	IF i == 0, delete the first one
//					ELSE  delete the (i)th member
//					&& len--
//	Note: the member is not "removed" 
//		  but truly deleted.
{
	ps = h;
	if (i < 1 || i > len)
	{
		std::cout << "Improper input, do nothing"
			<< '\n';
		return;
	}
	else if (i == 1)
	{
		h = ps->next;
		delete ps;
		ps = NULL;
		len--;
	}
	else
	{
		//find the (i - 1)th member 
		for (int j = 2; j < i; j++)
		{
			ps = ps->next;
		}
		pt = ps->next;	//*pt is the member to be deleted
		ps->next = pt->next;
		delete pt;
		pt = NULL;
		len--;
	}
}

int ChainList::FindByName(const string& nameIn)
//	given the name and return its position("i"th)
//	if no found, return -1
//	&& IF found, ps points to the position
//	ELSE ps == NULL
{
	ps = h;
	for (int i = 1; i < len + 1; i++)
	{
		if (ps->entry.name == nameIn)
			return i;
		ps = ps->next;
	}	
	cout << "No found." << endl;
	return -1;
}

int ChainList::FindByPhNum(const string& phNumIn)
//	given the phone number and return its position("i"th)
//	if no found, return -1
//	&& IF found, ps points to the position
//	ELSE ps == NULL
{
	ps = h;
	for (int i = 1; i < len + 1; i++)
	{
		if (ps->entry.phNum == phNumIn)
			return i;
		ps = ps->next;
	}
	cout << "No found." << endl;
	return -1;
}

void ChainList::FindByName_Print(const string& nameIn)
{
	if (FindByName(nameIn) == -1);
	else ps->NodePrint();
}

void ChainList::FindByPhNum_Print(const string& phNum)
{
	if (FindByPhNum(phNum) == -1);
	else ps->NodePrint();
}