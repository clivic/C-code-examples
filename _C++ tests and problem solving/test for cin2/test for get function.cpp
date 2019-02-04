/*******************************************************************************************************************************************
This program is intended to test how "get" function operates, by inputting different data to see what will be proved.
*******************************************************************************************************************************************/

#include <iostream>

using namespace std;

void main()
{
	char ch1,ch2,ch3,tab;
	tab='\t';
	cout<<"Please input two chars and let's get them three--"<<endl;
	cin.get(ch1);
	cin.get(ch2);
	cin.get(ch3);
	cout<<"The outputs are: "<<ch1<<tab<<ch2<<tab<<ch3<<endl;
}
/*This proves that get() can get almost all chars in ASCII. For that matter, what get() gets is the character just behind.*/