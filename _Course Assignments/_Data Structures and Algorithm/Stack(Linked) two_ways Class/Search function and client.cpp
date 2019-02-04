//*******************************************************************
//	Search function client
//*******************************************************************
#include "Linked_Stack.h"

void Introduction();
void Instruction();
template <class Node_entry>
Node<Node_entry>*Search(/* in */ Node<Node_entry> *head,
						/* in */ Node<Node_entry> *& p,
						/* in */ Node_entry key);
int main()
{
	int num;
	
	//initialization stack
	Stack <int> s;
	for (int i = 100; i >= 10; i -= 10)
		s.Push(i);
	
	Node <int> *p = s.GetTop();
	Introduction();
	do
	{
		Instruction();
		Cin(num);
		
		Node <int> *result;
		result = Search(s.GetTop(), p, num);
		if (result == NULL)
			cout << "No found." << endl;
		else
			cout << "The key is: " << result->entry << ", found." << endl;
		cout << "Do you wanna continue? " << flush;
	} while (UserSayYes());
}

void Introduction()
{
	cout << "Welcome to the test of Search function!\n"
		<< "You are supposed to enter a number for search and find out\n"
		<< "what 10 elements are exactly in the list." << endl << endl;
}

void Instruction()
{
	cout << "Please input the number you want to search: " << flush;
}

template <class Node_entry>
Node<Node_entry>*Search(/* in */ Node<Node_entry> *head,
	/* in */ Node<Node_entry> *& p,
	/* in */ Node_entry key)
{
	Node<Node_entry> *pTemp = p;	
	if (pTemp->entry == key)
	{
		p = pTemp;
		return p;
	}
	
	while (pTemp != NULL && pTemp->entry >= key)	//search precede
	{
		if (pTemp->entry == key)
		{
			p = pTemp;
			return p;
		}
		cout << pTemp->entry << ' ';	// precede steps
		pTemp = pTemp->precede;
	}
	
	while (pTemp != NULL && pTemp->entry <= key)	//search next
	{
		if (pTemp->entry == key)
		{
			p = pTemp;
			return p;
		}
		cout << pTemp->entry << ' ';	// precede steps
		pTemp = pTemp->next;
	}
	return NULL;
}