//*************************************************************************************************
//	Chain list implementation
//*************************************************************************************************

#include "chainList.h"
#include <iostream>

Node::Node(type item)
{
	key = item;
}

ChainList::ChainList(type n)
{
	type i = 1;
	h = new Node(i);
	ps = h;
	for (i += 1; i <= n; i++)
	{
		pt = new Node(i);
		ps->next = pt;
		ps = ps->next;
	}
	pt->next = NULL;
	len = n;
}

//***********************************************

Node* ChainList::GetAdr() const
//	return h, or the first member's address
{
	return h;
}

//***********************************************

type ChainList::GetItem(/* in */ int i)
//	return the "i"th member of type "type"
//	default "type" is int
//	if i is improper, message output && 
//	first one returned
{
	ps = h;
	if (i <= 0 || i > len)
	{
		std::cout << "Improper input, return first one"
			<< '\n';
	}
	else
	{
		for (int j = 2; j <= i; j++)
		{
			ps = ps->next;
		}
	}
	return ps->key;
}

//***********************************************

Node ChainList::GetMember(/* in */ int i)
//	return the "i"th member
//	if i is improper, message output && 
//	first one returned
{
	ps = h;
	if (i <= 0 || i > len)
	{
		std::cout << "Improper input, return first one"
				  << '\n';
	}
	else
	{
		for (int j = 2; j <= i; j++)
		{
			ps = ps->next;
		}
	}
	return *ps;
}

//***********************************************

int ChainList::GetLen() const
{
	return len;
}

//***********************************************

ChainList::~ChainList()
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

//***********************************************

void ChainList::Print()
//	cout every item of type "type" each in one line
//	default "type" is int
//	if i is improper, message output && 
//	first one returned
{
	ps = h;
	for (int i = 0; i < len; i++)
	{
		std::cout << ps->key << std::endl;
		ps = ps->next;
	}	//ps is null after iteration
}

//***********************************************

void ChainList::ReplaceItem(
	/* in */ int i,
	/* in */ type item)
//	replace the item in specified pos
{
	ps = h;
	if (i <= 0 || i > len)
	{
		std::cout << "Improper input, do nothing"
			<< '\n';
		return;
	}
	else
	{
		for (int j = 2; j <= i; j++)
		{
			ps = ps->next;
		}
		ps->key = item;
	}
}

//***********************************************

void ChainList::Replace(
	/* in */ int i,
	/* inout */ Node* &member)
	//	replace the member in specified pos
	//	precondition:	
	//		member should point to a Node struct
	//	postcondition:
	//		the pointer "member" points to member
	//		equals NULL && this struct member is
	//		absorbed into the ChainList &&
	//		the original one is deleted
{
	ps = h;
	if (i <= 0 || i > len)
	{
		std::cout << "Improper input, do nothing"
			<< '\n';
		return;
	}
	else if (i == 1)
	{
		member->next = ps->next;
		ps = NULL;
		delete h;
		h = member;
	}
	else
	{
		//find the member before to be replaced one
		for (int j = 2; j < i; j++)
		{
			ps = ps->next;
		}	
		member->next = ps->next->next;
		delete(ps->next);
		ps->next = member;
	}

	member = NULL;
}

//***********************************************

void ChainList::Insert(
	/* in */ int i, 
	/* inout */ Node* &member)
//	insert a Node type member into the chain list
//	between (i)th and (i + 1)th items
//	precondition:	i >= 0 && i <= len
//	postcondition:	IF i == 0, insert at the head
//					ELSE IF i == len, at the end
//					ELSE, between (i)th and (i+1)th
//					&& the pointer "member" 
//					points to member equals NULL				 
//					&& this struct member is	
//					absorbed into the ChainList
//					&& len++
{
	ps = h;
	if (i < 0 || i > len)
	{
		std::cout << "Improper input, do nothing"
				  << '\n';
		return;
	}
	else if (i == 0)
	{
		member->next = ps;
		h = member;
		member = NULL;
		len++;
	}
	else
	{
		//find the (i)th member 
		for (int j = 2; j <= i; j++)
		{
			ps = ps->next;
		}
		member->next = ps->next;
		ps->next = member;
		member = NULL;
		len++;
	}
}

//***********************************************

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