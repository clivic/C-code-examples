//*************************************************************************************************
//This program tests what is the "overwright" of the "toStr" in its specification.
//*************************************************************************************************

#include <iostream>
#include <cstring>

using namespace std;

void main()
{
	char toStr[] = "hello everyone";
	char fromStr[] = "hello";
	//cout << strcpy(toStr, fromStr) << endl;
	cout << strcpy(fromStr, toStr) << endl;
}

//	Results:
//	"overwrite" means erasing all and then write.
