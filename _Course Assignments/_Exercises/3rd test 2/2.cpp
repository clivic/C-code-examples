#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int Stat(string);

int main()
{
	string str;
	getline(cin, str);
	cout << Stat(str) << endl;
	return 0;
}

//***********************************************

int Stat(string str)
{
	int count(0);
	for(int i(0); i < str.length() - 1; i++)
	{
		if ( isupper(str[i]) )  
		{
			count++;
		}
	}
	return count;
}