/**************************************************************************************************
To_do list
We use the List class to create a larger list ADT -- To_do list, which includes many states.
**************************************************************************************************/

#include "list.h"
#include <iostream>

using namespace std;

class To_do
{
private:
	List Done;
	List Partial;
	List Undone;

public:
	void Add()
	{
		
	
	void MarkDone	(/* in */ DataType item);
	void MarkPartial(/* in */ DataType item);
	void Delete		(/* in */ DataType item);
	void Print		();
};



