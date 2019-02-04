#include <iostream>
#include <string>

using namespace std;

void Rec(string word);

void main()
{
	Rec("abcdefg");
}

//*********************

void Rec(string word)
{
	if (word.length() > 0)
	{
		cout << word.substr(0, 1);
		Rec(word.substr(1, word.length() - 2));
		cout << word.substr(word.length() - 1, 1) << endl;
	}
}
