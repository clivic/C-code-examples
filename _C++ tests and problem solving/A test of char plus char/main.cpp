/*******************************************************************************************************************************************
This program is to test what will be output when a char was added to another char and stored in to a string type or a int type. And by the 
way to figure out what if a char is added to a string.
*******************************************************************************************************************************************/


#include <iostream>
#include <string>

using namespace std;

const string a="a";
const char b='5';
void main()
{
	string str;
	str='5'+'a';
	cout<<str<<endl; //The value of a string type stored of char + char.               -----------1.

	int num;
	num='5'+'a';
	cout<<num<<endl; //The value of a int type stored of char + char.                  -----------2.

	string plus;
	plus="a"+'5';
	cout<<plus<<endl; //The value of a string if different types were added up.      -----------3.

	int numplus;
	numplus="a"+'5';
	cout<<numplus<<endl; //The value of a number if different types were added up.   -----------4.

	cout<<a+b<<endl;

}

//Results: It seems that only no.1 , no.2 and no.3, no.5 are available, while no.1 displays char data, for it's regarded as an addition, so it plus the two
//characters by their ASCII code and achieve a result to display the corresponding character. 
//And no.2 displays the ASCII code of their addition.
//no.3 is executible while isn't desired code. It will be normal while defined as constants(no.5).
