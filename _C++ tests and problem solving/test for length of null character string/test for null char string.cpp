/************************************************
This program tests the length of "\0", "\0\0".
************************************************/
#include <iostream>
#include <string>

using namespace std;

void main()
{
	//implicit "\0" string
	string str1("c");
	cout << (str1.substr(1, -1)).length() << endl;

	//explicit "\0" string
	string str2("\0");
	cout << str2.length() << endl;

	//explicit "\0\0" string
	str2 += "\0";
	cout << str2.length() << endl;

	//explicit "\0" string initialized by char
	string str3('\0');
	cout << str3.length() << endl;	//couldn't
									//work 
									//properly
}

/*	Results:
	They are all 0.								*/
