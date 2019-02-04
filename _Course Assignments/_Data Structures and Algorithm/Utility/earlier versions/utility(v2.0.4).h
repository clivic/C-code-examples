//*******************************************************************
//	Utility Package specification
//	version 2.0.4
//	General introduction:	
//		The Utility header file and source file provides many useful
//		tool for the client to use conveniently, and including many
//		standard header files in usage.
//		And some function(s) in this header file use(s) templates. 
//		It integrate the specification and implementation of the 
//		utility class into this head file, for convenient use
//		of clients. (only need to include this header file)
//	Updates (from versioin 2.0.3):
//		It includes <fstream> and <iomanip>.
//	Notes:
//		any clients using the whole Utility Package should include 
//		this header file into the project to run properly, and also
//		include it in the client source file when necessary.
//*******************************************************************
#ifndef UTILITY
#define UTILITY

#include <iostream>
#include <Queue>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
 
bool UserSayYes();

template <class Type>
void Cin(/* inout */ Type& input);

enum Error_code {success, underflow, overflow, range_exceed, 
				 fail, not_present};

//*******************************************************************

//	Definitions
template <class Type>
void Cin(/* inout */ Type& input)
//	Pre:	the object for cin should support "cin operation".
//	Post:	cin a number && IF cin breaks down,
//			prompt user to re-enter the object && clear the cin.	
//	Note:	for template, should include utility.cpp.
{
	cin >> input;
	//prevent the case of not number
	while (!cin)
	{
		cout << "Invalid input, please input again: " << flush;
		cin.clear();
		cin.sync();
		cin >> input;
	}
}

#endif