/**************************************************************************************************
This program is to read in a char and convert it to int number and output it if the char is numeric
or output '#' if not.
**************************************************************************************************/

#include <iostream>
#include <cctype>						//for judge

using namespace std;

int main()
{
	char ch;							//input char
	cin >> ch;
	if (isdigit(ch))
	{
		cout << int (ch - '0') << endl;	//char's inside value
	}
	else
	{
		cout << '#' << endl;
	}
	return 0;
}