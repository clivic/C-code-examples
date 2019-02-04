//*************************************************************************************************
//	Two way Chain list implementation
//*************************************************************************************************
#include "Chain List (two_way).h"
#include <iostream>

Node2::Node2(type item)
{
	key = item;
	precede = NULL;
	next = NULL;
}

ChainList2::ChainList2(type n)
{
	type i = 1;
	h = new Node2(i);
	ps = h;
	for (i += 1; i <= n; i++)
	{
		pt = new Node2(i);
		ps->next = pt;
		pt->precede = ps;
		ps = ps->next;
	}
	pt->next = h;	//circle
	len = n;
}

//***********************************************