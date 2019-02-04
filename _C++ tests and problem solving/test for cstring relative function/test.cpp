/**************************************************************************************************
This program test how to use cstring relative functions.
**************************************************************************************************/

#include <iostream>

using namespace std;

void main()
{
	char str1[] = "hello ";
	char str2[] = "world";
	char * address = strcpy(str1, str2);
	cout << str1 << str2 << endl;
	cout << address;
}
