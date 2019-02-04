//*************************************************************************************************
//	Chain list implementation
//*************************************************************************************************

#include "chainList.h"
#include <iostream>

Node::Node(type item, Node* addOn)
{
	key = item;
	next = addOn;
}

ChainList::ChainList(type n)
//	Post:	constructed && the next of the last entry is
//			the first entry.
{
	type i = 1;
	h = new Node(i);
	ps = h;
	pt = h;	//for the case that n = 1
	for (i += 1; i <= n; i++)
	{
		pt = new Node(i);
		ps->next = pt;
		ps = ps->next;
	}
	pt->next = h;
	len = n;
}

Node* ChainList::GetAdr() const
//	return h, or the first member's address
{
	return h;
}

type ChainList::GetItem(/* in */ int i)
//	return the "i"th member of type "type"
//	default "type" is int
//	if i is improper, for it's circulate,
//	it will return to the head to continue
//	when reaching the bottom
{
	ps = h;
	if (i <= 0 || i > len)
	{
		i %= len;
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

type ChainList::GetItem_Change(/* in */ int i)
//	return the "i"th member of type "type"
//	default "type" is int
//	if i is improper, for it's circulate,
//	it will return to the head to continue
//	when reaching the bottom
{
	type key = GetItem(i);	
	h = ps;			//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!only for Joserf problem
	return key;
}

Node ChainList::GetMember(/* in */ int i)
//	return the "i"th member
//	if i is improper, for it's circulate,
//	it will return to the head to continue
//	when reaching the bottom
{
	ps = h;
	if (i <= 0 || i > len)
	{
		i %= len;
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

int ChainList::GetLen() const
{
	return len;
}

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

void ChainList::ReplaceItem(/* in */ int i,	/* in */ type item)
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

void ChainList::Replace(/* in */ int i, /* inout */ Node* &member)
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
		//find the last entry
		pt = h;
		while (pt->next != h)
		{
			pt = pt->next;
		}

		member->next = ps->next;
		ps = NULL;
		delete h;
		h = member;
		pt->next = h;
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

void ChainList::Insert(/* in */ int i, /* in */ type item)
//	create a dynamic Node and given the item passed in,
//	and insert it into the chain list
//	between (i)th and (i + 1)th items
//	precondition:	i >= 0 && i <= len
//	postcondition:	IF i == 0, insert at the head
//					ELSE IF i == len, at the end
//					ELSE, between (i)th and (i+1)th
{
	ps = h;	
	if (i < 0 || i > len)
	{
		std::cout << "Improper input, do nothing"
				  << '\n';
		return;
	}
	Node* pNew = new Node(item);
	if (i == 0)
	{
		//find the last entry
		pt = h;
		while (pt->next != h)
		{
			pt = pt->next;
		}

		pNew->next = ps;
		h = pNew;
		pt->next = h;
		pNew = NULL;
		len++;
	}
	else
	{
		//find the (i)th member 
		for (int j = 2; j <= i; j++)
		{
			ps = ps->next;
		}
		pNew->next = ps->next;
		ps->next = pNew;
		pNew = NULL;
		len++;
	}
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
		//find the last entry
		pt = h;
		while (pt->next != h)
		{
			pt = pt->next;
		}

		h = ps->next;
		delete ps;
		ps = NULL;
		pt->next = h;
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

void ChainList::Clear()
{
	ps = h->next;
	pt = ps->next;
	h->next = NULL;
	h = NULL;
	for (int i = 1; i < len; i++)
	{
		delete ps;
		ps = pt;
		pt = pt->next;
	}
	delete ps;
	ps = pt;
	len = 0;
}

//Safty Guards
ChainList::~ChainList()
{
	Clear();
}

ChainList::ChainList(const ChainList& original)
//	Pre:	There is no assurence for a newly allocated dynamic location
//			to fail in this function.
//	Note:	copy constructor
{
	Node* pTemp, *po = original.h;
	if (po == NULL)	h = NULL;
	else
	{
		h = pTemp = new Node(po->key);
		while (po->next != h)
		{
			po = po->next;
			pTemp->next = new Node(po->key);
			pTemp = pTemp->next;
		}
		pTemp->next = h;
	}
	len = original.len;
}

ChainList& ChainList::operator = (const ChainList& original)
//	Pre:	There is no assurence for a newly allocated dynamic location
//			to fail in this function.
//	Post:	the stack is reset as a copy of Stack original.
{
	//judge for identity
	if (this == &original)	return *this;

	//clear then copy
	Clear();
	Node* pTemp, *pNew, *po = original.h;
	if (po == NULL)	h = NULL;
	else
	{
		pNew = pTemp = new Node(po->key);
		while (po->next != h)
		{
			po = po->next;
			pTemp->next = new Node(po->key);
			pTemp = pTemp->next;
		}
		pTemp->next = h;
		h = pNew;
	}
	len = original.len;
	return *this;
}