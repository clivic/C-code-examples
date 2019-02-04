//*******************************************************************
//Ordered List Class's specification
//	Version 1.0
//	General introduction :
//		It's an orderedlist using template, which could automaticlly
//		insert the entry you wanna put into in the proper ascending
//		position, or judge whether can replace an entry according to
//		its order,
//		It's derived from List.h, so please don't forget to include
//		List.h and besides, it also can be derived.
//	Note:	using "Utility"'s utility .h and .cpp, List.h
//*******************************************************************
#ifndef OLIST
#define OLIST
#include "List.h"
#include "utility.h"

template <class List_entry>
class OrderedList : public List<List_entry>
{
public:
	Error_code Insert(const List<List_entry> &x);
	Error_code Insert(int position, const List<List_entry> &x);
	Error_code Replace(int position, const List<List_entry> &x);
};


//*******************************************************************

//OrderedList Class Implementation
template <class List_entry>
Error_code OrderedList <List_entry>::Insert(const List_entry &x)
//	Post:	If the OrderedList<List_entry> is not full, the function succeeds: 
//			The List_entry x is inserted into the list, following the 
//			last entry of the list with a strictly lesser key (or in 
//			the first list position if no list element has a lesser key).
//	Else: the function fails with the diagnostic Error_code overflow.
{
	int size = Size();
	int pos;
	for (pos = 0; pos < size; pos++)
	{
		List_entry entry;
		Retrieve(pos, entry);
		if (x < entry) break;
	}
	return List<List_entry>::Insert(pos, x);
}

template <class List_entry>
Error_code OrderedList <List_entry>::Insert(int position, const List_entry &x)
//	Post:	If the Ordered list is not full, 0 <= position <= n , where n 
//			is the number of entries in the list, and the List_entry x can be 
//			inserted at position in the list, without disturbing the list order, 
//			then the function succeeds: Any entry formerly in position and all 
//			later entries have their position numbers increased by 1 and x 
//			is inserted atposition of the List.
//	Else: the function fails with a diagnostic Error_code.
{
	List_entry entry;
	if (position > 0)
	{
		Retrieve(position - 1, entry);
		if (x < entry)
			return fail;
	}
	if (position < Size())
	{
		Retrieve(position, entry);
		if (x > entry)
			return fail;
	}
	return List<List_entry> ::Insert(position, x);
}

template <class List_entry>
Error_code OrderedList <List_entry>::Replace(int position, const List_entry &x)
//	Post:	If the Ordered list is not full, 0 <= position <= n , where n 
//			is the number of entries in the list, and the List_entry x can be 
//			replaced at position in the list, without disturbing the list order, 
//			then the function succeeds: the entry at the position is replaced 
//			by x.
//	Else: the function fails with a diagnostic Error_code.
{
	if (position < 0 || position >= count)	return range_exceed;
	List_entry entry;
	if (position > 0)
	{
		Retrieve(position - 1, entry);
		if (x < entry)	return fail;
	}
	if (position < count - 1)
	{
		Retrieve(position + 1, entry);
		if (x > entry)	return fail;
	}
	entry[position] = x;
	return success;
}

//Search function -- Binary Search
template <class List_entry>
Error_code BinarySearch1(const OrderedList<List_entry> &list, const List_entry &target, int &position)
//	Pre:	bottom and top define the range in the list to search for the target.
//	Post:	If a List_entry in the range of locations from bottom totop inthe list has
//			key equal to target, then position locates one such entry and a code
//			of success is returned. Otherwise, the Error code of not present is
//			returned and position becomes undefined.
//	Uses:	methods of the classes List and List_entry. 
//	Note:	Forgetful Version Binary Search		
{
	List_entry data;
	int bottom = 0, top = list.Size() - 1;
	while (bottom < top) 
	{
		int mid = (bottom + top) / 2;
		list.Retrieve(mid, data);
		if (data < target)
			bottom = mid + 1;
		else
			top = mid;
	}
	if (top < bottom)	return not_present;
	else 
	{
		position = bottom;
		list.Retrieve(bottom, data);
		if (data == target) return success;
		else return not_present;
	}
}

template <class List_entry>
Error_code BinarySearch2(const OrderedList<List_entry> &list, const List_entry &target, int &position)
//	Pre:	bottom and top define the range in the list to search for the target.
//	Post:	If a List_entry in the range of locations from bottom totop inthe list has
//			key equal to target, then position locates one such entry and a code
//			of success is returned. Otherwise, the Error code of not present is
//			returned and position becomes undefined.
//	Uses:	methods of the classes List and List_entry. 
//	Note:	Recognizing Equality Binary Search.
{
	List_entry data;
	int bottom = 0, top = list.size() - 1;
	while (bottom <= top) 
	{
		position = (bottom + top) / 2;
		list.Retrieve(position, data);
		if (data == target) return success;
		if (data < target) bottom = position + 1;
		else top = position - 1;
	}
	return not_present;
}

#endif

