//*******************************************************************
//	Inverse function
//*******************************************************************
#include "ChainList.h"

void Inverse(Node* &first)
//	Pre:	first != NULL
//	Post:	(in Chinese)
//			通过遍历一趟链表，将链表中所有结点的链接方向逆转。
//			要求逆转结果链表的表头指针h指向原链表的最后一个结点。 
{
	Node *ph = first, *ps, *pt, *po;

	////Judge if the chainlist contains only one member:
	//if (first->next == first)
	//	return;

	//find the last entry
	pt = first;
	while (pt->next != first)
	{
		pt = pt->next;
	}	//pt points to the last one

	ps = ph->next->next;
	po = ph->next;
	ph->next = pt;

	while (ps != pt)
	{
		po->next = ph;
		ph = po;
		po = ps;
		ps = ps->next;
	}
	po->next = ph;
	ps->next = po;

	first = pt;

}

void Introduction();
void Instructions();

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

int main()
{
	Introduction();
	do
	{
		Instructions();
		unsigned int n;
		Cin(n);
		ChainList list(n);

		cout << "Original list:" << endl;
		list.Print();

		Node* address = list.GetAdr();
		Inverse(address);
		cout << "Current list:" << endl;
		Node* ps = address;
		for (int i = 0; i < list.GetLen(); i++)
		{
			std::cout << ps->key << std::endl;
			ps = ps->next;
		}
		cout << "Do you anna continue? " << flush;
	} while (UserSayYes());
	return 0;
}

void Introduction()
{
	cout << "Test of the Inverse of ChainList\n"
		<< endl;
}

void Instructions()
{
	cout << "Please enter a size of the ascending sequence list start from 1, \n"
		<< "and it should be an positive integer: " << flush;
}