/**************************************************************************************************
This program counts the number of 'e' in a string input
**************************************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count(0);				//count for 'e'
	string inLine;
	getline(cin, inLine);
	
	//scanning
	for(int i(0); i <= inLine.length() - 1; i++)
	{
		if (inLine[i] == 'e')
			count++;
	}
	cout << count << endl;

	return 0;
}