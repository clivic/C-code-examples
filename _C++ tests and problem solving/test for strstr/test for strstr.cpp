//*************************************************************************************************
//This program tests the use of strstr.
//*************************************************************************************************

#include <iostream>
#include <cstring>

using namespace std;

void main()
{
	char toStr[] = "hello everyone";
	char fromStr[] = "llo";
	cout << strstr(toStr, fromStr) << endl;	//assumed to output "llo everyone".
	cout << strstr(toStr, "now") << endl;	//assumed to output NULL.
}

//	Results:
//	The second sentence's memory perhaps has some problems, it stops to work...
//	It remains unknown what "NULL" is...
