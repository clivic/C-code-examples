//***********************************************
//This program tests what if a string got from 
//cin is longer than the array defined.
//***********************************************

#include <iostream> 
//#include <cstring>	//indeed it isn't needed
#include <string>		//for getline(cin, str)

using namespace std;

void main()
{
	char cstr[11];		//10 + '\0'
	string str;
	
	cin >> cstr;
	//cin.get(cstr, 19);
	//cin.ignore(100, '\n');
	cout << "You have input:" << endl;
	cout << cstr << endl;
	cout << "The length of cstr now is:" << endl
		 << strlen(cstr) << endl;
}


//	Result:
//	If longer, it will automatically stretch the
//	cstr and erase the next memory attached to 
//	the cstr[10], replacing them with remaining 
//	what you've input, until a '\0', no matter
//	>> or get function, they are both so.
//	So if it erase some critical memories, it may
//	encounter problems.
//	And:
//	getline(cin, str) is in <string>, and the str 
//	seemed to be only string variable
//	(not cstring).

//***********************************************
//Additional test
//to verify our suspect of the getline function, 
//we make another main function.
/*
void main()
{
	char cstr[11];		//10 + '\0'
	string str;
	getline(cin, str);
	cout << "You have input:" << endl;
	cout << str << endl;
	cout << "The length of str now is:" << endl
		 << str.length() << endl;
}
*/

//	Result:
//	getline(cin, str) could only be used upon
//	string, not cstring perhaps, and it is in
//	<string>, while get(...) functions are in 
//	<iostream> perhaps.
//	And
//	getline(cin, str) seemed not to be a class
//	function, but a universal function uha.