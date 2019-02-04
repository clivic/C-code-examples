//*************************************************************************************************
//Client code (a drive class)
//*************************************************************************************************

#include "sortedList.h"
#include <iostream>

using namespace std;

void main()
{
	SortedList list;
	DataType str1 = "hello:)";
	list.InsertOnce(str1);
	list.Insert(str1);
	list.Delete(str1);
	list.Print();
}