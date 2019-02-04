//No.3
#include <iostream>

using namespace std;

int BinarySearch(
	/* in */ int item,
	/* in */ int data[],
	/* in */ int first,
	/* in */ int last )
	//	to perform binary search in a recursive way
	//	Precondition:	len <= INT_MAX / 2 && first < last
	//	Postcondition:	IF item is in data[], found == true && pos is determined
	//					ELSE found == flase && pos is unchanged
{
	int middle = (first + last) / 2;
	
	if (data[middle] == item)
	{
		return middle;	//found position
	}
	else if (first > last)
	{
		return -1;		//not found
	}

	else if (data[middle] > item)
	{
		return BinarySearch(item, data, first, middle - 1);
	}
	else if (data[middle] < item)
	{
		return BinarySearch(item, data, middle + 1, last);
	}

}
