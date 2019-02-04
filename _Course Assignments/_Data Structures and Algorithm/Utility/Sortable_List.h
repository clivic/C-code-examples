//*******************************************************************
//	Sortable list specification
//*******************************************************************
#ifndef SORTABLELIST
#define SORTABLELIST
#include "List.h"

template <typename List_entry>
class SortableList : public List<List_entry>
{
public:
	//SortableList
	void BubbleSort();
	void InsertionSort();
	void SelectionSort();
	void ShellSort();
	void QuickSort();
	void HeapSort();
	void MergeSort();

protected:
	//functions for BubbleSort and SelectionSort
	void Swap(int low, int high);
	int MaxEntryPos(int low, int high);
	//functions for InsertionSort and ShellSort
	void InsSortInterval(int start, int increment);
	//functions for QuickSort
	void RecursiveQuickSort(int low, int high);
	int Partition(int low, int high);
	//functions for HeapSort
	void BuildHeap();
	void InsertHeap(const List_entry &current, int low, int high);
	//functions for MergeSort
	void Divide(int low, int high);
	void Compare(int low, int mid, int high);
	//data member for MergeSort's operation
	List_entry tmp[MAX_LIST];
	//function to clear tmp array
	void ClearTmp();
};

template <class List_entry>
void MergeSort(SortableList<List_entry> &myList);

//*******************************************************************

template <class List_entry>
void SortableList<List_entry>::BubbleSort()
//	Pre:	List_Entry should be comparable.
//	Post:	The entries of the Sortable list have been rearranged so that 
//			the keys in all the entries are sorted into nondecreasing order. 
//	Uses:	Auxillary function Swap and the contiguous List 
//			implementation of Chapter 6.
{
	for (int i = 0; i < Size() - 1; i++)
		for (int j = 0; j <Size() - 1 - i; j++)
		{		//don't compare last element again for it is the largest.
			if (entry[j]>entry[j + 1])
				Swap(j, j + 1);
		}
}

template <class List_entry>
void SortableList<List_entry>::InsertionSort()
//	Pre:	List_Entry should be comparable.
//	Post:	The entries of the Sortable list have been rearranged so that 
//			the keys in all the entries are sorted into nondecreasing order. 
//	Uses:	Auxillary function InsSortInterval and the contiguous List 
//			implementation of Chapter 6.
{
	InsSortInterval(0, 1);
}

template <class List_entry>
void SortableList<List_entry>::SelectionSort()
//	Pre:	List_Entry should be comparable.
//	Post:	The entries of the Sortable list have been rearranged so 
//			that the keys in all the entries are sorted into 
//			nondecreasing order.
//	Uses:	Auxillary function MaxEntryPos, Swap and the contiguous List 
//			implementation of Chapter 6.
{
	for (int position = count - 1; position > 0; position--) 
	{
		int max = MaxEntryPos(0, position);
		Swap(max, position);
	}
}

template <class List_entry>
int SortableList<List_entry>::MaxEntryPos(int low, int high)
//	Pre:	low and high are valid positions in the Sortable list and low <= high.
//			&& List_Entry should be comparable.
//	Post:	The position of the entry between low and high with the largest key is
//			returned.
//	Uses:	The contiguous List implementation of Chapter 6.
{
	int largest, current;
	largest = low;
	for (current = low + 1; current <= high; current++)
		if (entry[largest] < entry[current])
			largest = current;
	return largest;
}

template <class List_entry>
void SortableList<List_entry>::Swap(int low, int high)
//	Pre:	low and high are valid positions in the Sortable list.
//			&& List_Entry should be comparable.
//	Post:	The entry at position low is Swapped with the entry at position high.
//	Uses:	The contiguous List implementation of Chapter 6. 
{
	List_entry temp;
	temp = entry[low];
	entry[low] = entry[high];
	entry[high] = temp;
}

template <class List_entry>
void SortableList<List_entry>::ShellSort()
//	Post:	The entries of the Sortable list have been rearranged so 
//			that the keys in all the entries are sorted into 
//			nondecreasing order.
//	Uses:	InsSortInterval 
{
	int increment,							// spacing of entries in sublist
		start;								// starting point of sublist
	increment = count;
	do 
	{
		increment = increment / 3 + 1;
		for (start = 0; start < increment; start++)
			InsSortInterval(start, increment); // modified Insertion sort
	} while (increment > 1);
}

template <class List_entry>
void SortableList<List_entry>::InsSortInterval(int start, int increment)
//	Pre:	List_Entry should be comparable.
//	Post:	Sort the every entries by "increment" intervals, and start 
//			at position "start".
//	Uses:	the contiguous List implementation of Chapter 6.
{
	int firstUnsorted;	// position of first unsorted entry
	int position;		// searches sorted part of list
	List_entry current;	// holds the entry temporarily removed from list
	for (firstUnsorted = start + increment; firstUnsorted < count; firstUnsorted += increment)
		if (entry[firstUnsorted] < entry[firstUnsorted - increment])
		{
			current = entry[firstUnsorted];	// Pull unsorted entry out of the list
			position = firstUnsorted;
			do
			{
				entry[position] = entry[position - increment];
				position -= increment;
			} while (position > start && current < entry[position - increment]);
			entry[position] = current;
		}
}

template <class List_entry>
void MergeSort(SortableList<List_entry> &myList)
//	Pre:	List_Entry should be comparable.
//	Post:	The entries of the Sortable list have been rearranged so 
//			that the keys in all the entries are sorted into 
//			nondecreasing order.
//	Note:	Using the mind of Divide and Conquer. 
//	Uses:	myList's methods MergeSort.
{
	myList.MergeSort();
}

template <class List_entry>
void SortableList<List_entry>::MergeSort()
//	Pre:	List_Entry should be comparable.
//	Post:	The entries of the Sortable list have been rearranged so 
//			that the keys in all the entries are sorted into 
//			nondecreasing order.
//	Note:	Using the mind of Divide and Conquer. 
//	Uses:	Divide, Compare and the contiguous List implementation of Chapter 6.
{
	Divide(0, Size() - 1);
}

template <class List_entry>
void SortableList<List_entry>::Divide(int low, int high)
//	Pre:	List_Entry should be comparable.
//	Post:	Divide the sublist from position low to position high into
//			two lists: one from low to mid and the other from mid + 1
//			to high.
//	Uses:	Compare and the contiguous List implementation of Chapter 6.
{
	if (high == low)	return;

	int mid = (low + high) / 2;
	Divide(low, mid);	//length high - low + 1 
	Divide(mid + 1, high);
	Compare(low, mid, high);
}

template <class List_entry>
void SortableList<List_entry>::Compare(int low, int mid, int high)
//	Pre:	List_Entry should be comparable.
//	Post:	Merge the two lists and put it to the array tmp, which start at low
//			and mid + 1. At last things in the tmp are copied to the corresponding
//			positions in the calling Sortablelist.
//	Uses:	the contiguous List implementation of Chapter 6.
{
	int	i = low,		//for first splited "list" 
		j = mid + 1,	//for second splited "list"
		k = 0;			//for temp array
	while (i <= mid && j <= high)
	{
		if (entry[i] <= entry[j])	tmp[k++] = entry[i++];
		else						tmp[k++] = entry[j++];
	}

	//deal with remaining elements
	for (; i <= mid; i++)
		tmp[k++] = entry[i];
	for (; j <= high; j++)
		tmp[k++] = entry[j];

	for (i = low, k = 0; i <= high; i++, k++)
		entry[i] = tmp[k];
	ClearTmp();
}


template <class List_entry>
void SortableList<List_entry>::QuickSort()
//	Pre:	List_Entry should be comparable.
//	Post:	The entries of the Sortable list have been rearranged so that 
//			the keys in all the entries are sorted into nondecreasing order. 
//	Uses:	Auxillary function RecursiveQuickSort and the contiguous List 
//			implementation of Chapter 6.
{
	RecursiveQuickSort(0, count - 1);
}

template <class List_entry>
void SortableList<List_entry>::RecursiveQuickSort(int low, int high)
//	Pre:	low and high are valid positions in the Sortable list. 
//	Post:	The entries of the Sortable list have been rearranged so 
//			that their keys are sorted into nondecreasing order.
//	Uses:	Contiguous List implementation of Chapter 6, 
//			RecursiveQuickSort, and Partition.
{
	int pivotPos;
	if (low < high) { // Otherwise, no sorting is needed.
		pivotPos = Partition(low, high);
		RecursiveQuickSort(low, pivotPos - 1);
		RecursiveQuickSort(pivotPos + 1, high);
	}
}

template <class List_entry>
int SortableList<List_entry>::Partition(int low, int high)
//	Pre:	low and high are valid positions of the Sortable list, 
//			with low <= high .
//	Post:	The center (or left center) entry in the range between 
//			indices low and high of the Sortable list has been chosen 
//			as a pivot. All entries of the Sortable list between 
//			indices low and high , inclusive, have been rearranged 
//			so that those with keys less than the pivot come before 
//			the pivot and the remaining entries come after the pivot. 
//			The final position of the pivot is returned.
//	Uses:	Swap(int i, int j) (interchanges entries in positions i 
//			and j of a Sortable list), the contiguous List 
//			implementation of Chapter 6.
{
	List_entry pivot;
	int i,						//used to scan through the list
		lastSmall;				//position of the last key less than pivot

	// use centre entry as pivot 
	Swap(low, (low + high) / 2);
	pivot = entry[low];			
	lastSmall = low;
	for (i = low + 1; i <= high; i++)
		/* At the beginning of each iteration of this loop, we have the following conditions:
		If low < j <= lastSmall then entry[j].key < pivot.
		If lastSmall < j < i then entry[j].key >= pivot.*/
		if (entry[i] < pivot) 
		{
			lastSmall++;
			Swap(lastSmall, i); //Move large entry to right and small to left.
		}
	Swap(low, lastSmall);		//Put the pivot into its proper position.
	return lastSmall;
}

template <class List_entry>
void SortableList<List_entry>::HeapSort()
//	Post:	The entries of the Sortable list have been rearranged so that their keys
//			are sorted into nondecreasing order.
//	Uses:	The contiguous List implementation of Chapter 6, BuildHeap, and InsertHeap.
{	
	List_entry current; //temporary storage for moving entries
	int lastUnsorted;	//Entries beyond last unsorted have been sorted.
	BuildHeap();		//First phase: Turn the list into a heap.
	for (lastUnsorted = count - 1; lastUnsorted > 0; lastUnsorted--)
	{
		current = entry[lastUnsorted];				//Extract last entry from list.
		entry[lastUnsorted] = entry[0];				//Move top of heap to the end
		InsertHeap(current, 0, lastUnsorted - 1);	//Restore the heap
	}
}

template <class List_entry>
void SortableList<List_entry>::InsertHeap(const List_entry &current, int low, int high)
//	Pre:	The entries of the Sortable list between indices low + 1 and 
//			high, inclusive, form a heap. The entry in position low will 
//			be discarded. 
//	Post:	The entry current has been inserted into the Sortable list 
//			and the entries rearranged so that the entries between indices 
//			low and high, inclusive, form a heap.
//	Uses:	The class Record, and the contiguous List implementation of 
//			Chapter 6.
{
	int large; //position of child ofentry[low] with the larger key
	large = 2 * low + 1;//large is now the left child oflow.
	while (large <= high) 
	{
		if (large < high && entry[large] < entry[large + 1])
			large++;	//large is now the child oflow with the largest key.
		if (current >= entry[large])
			break;		//current belongs in position low.
		else
		{				//Promote entry[large] and move down the tree.
			entry[low] = entry[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	entry[low] = current;
}

template <class List_entry>
void SortableList<List_entry>::BuildHeap()
//	Post:	The entries of the Sortable list have been rearranged so 
//			that it becomes a heap.
//	Uses:	The contiguous List implementation of Chapter 6, and InsertHeap.
{
	int low;		//All entries beyond the positionlow form a heap.
	for (low = count / 2 - 1; low >= 0; low--) 
	{
		List_entry current = entry[low];
		InsertHeap(current, low, count - 1);
	}
}

template <class List_entry>
void SortableList<List_entry>::ClearTmp()
//	Post:	Clear the array tmp used for MergeSort.
{
	tmp[0] = '\0';
}

#endif