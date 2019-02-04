//*******************************************************************
//	Sortable list(linked) specification
//*******************************************************************
#include "Linked_List.h"

template <class List_entry>
class SortableList : public List
{
public:
	void InsertionSort();
};

//*******************************************************************

template <class List_entry>
void SortableList<List_entry>::InsertionSort()
//	Pre:	List_Entry should be comparable.
//	Post:	The entries of the Sortable list have been rearranged so that 
//			the keys in all the entries are sorted into nondecreasing order. 
//	Uses:	Methods for the class Record and the contiguous List 
//			implementation of Chapter 6.
{
	Node<List_entry>	firstUnsorted,
						lastSorted,
						current,
						trailing;
	if (head != NULL)				//if empty, no need to sort
	{
		lastSorted = head;
		while (head->next != NULL)	//if one entry, also no need to sort
		{
			firstUnsorted = head->next;

			//Case 1: head comparision
			if (firstUnsorted->entry)
			{
				lastSorted->next = firstUnsorted->next;
				firstUnsorted->next = head;
				head = firstUnsorted;
			}
			//Case 2: middle comparison
			else
			{
				trailing = head;
				current = trailing->next;
				while (firstUnsorted->entry > current->entry)
				{
					trailing = current;
					current = trailing->next;
				}	//firstUnsorted now should be between *trailing and *current

				if (firstUnsorted == current)
					lastSorted = firstUnsorted;
				else
				{
					lastSorted->next = firstUnsorted->next;
					firstUnsorted->next = current;
					trailing->next = firstUnsorted;
				}
			}
		}
	}
}
