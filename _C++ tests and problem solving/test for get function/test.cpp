/************************************************
This program is to test if "get" fuction could
only get a char in char instead of string value
************************************************/

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string str;
	char ch;
	//cin.get(str);
	cin.get(ch);
	//cout << str << endl;
	cout << ch << endl;
}

//The result is that :
//"get" function could only be inplemented to
//and stored into char variable, rather than 
//string variables...
	