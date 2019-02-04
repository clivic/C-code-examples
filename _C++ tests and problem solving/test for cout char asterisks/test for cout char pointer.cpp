//*******************************************************************
//	Test for cout char*
//*******************************************************************
#include <iostream>
using namespace std;

int main()
{
	char ch = 48;
	char *p = &ch;
	cout << p << endl;
	return 0;
}

//	Results:
//	As long as the thing you want to cout is char*, c++ compiler will
//	automatically cout its containing continously until a \0 is met,
//	unlike other pointers like int* that output their address.