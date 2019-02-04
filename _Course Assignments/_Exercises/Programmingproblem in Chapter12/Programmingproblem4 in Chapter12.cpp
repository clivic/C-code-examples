/**************************************************************************************************
Palindrome program
This program judges the palindrome in a less restricted way -- ignoring its punctuations and 
capturulization and blanks.  
**************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

//function prototypes
string Process(/* in */ string);
string Reverse(/* in */ string);
bool Compare  (/* in */ string str1,
			   /* in */ string str2);
void Output(/* in */ bool);

int main()
{
	string str, strR;									//sentence and its reverse
	unsigned int lenI,									//length initial
				 len;									//length after truncated
	bool compareResult;
	//cout << "Please input a sentence:" << endl;
	getline(cin, str);
	lenI = str.length();
	str = Process(str);
	len = str.length();

	strR = Reverse(str);
	compareResult = Compare(str, strR);

	//output result
	cout << strR << endl;
	Output(compareResult);

	return 0;
}

//*************************************************************************************************

//function implementations
string Process(/* in */ string str)
//	this function is to discard punctuations and spaces in the passed-in string and convert it to
//	lower case.
//	Precondition:	str.length() > 0.
//	Postcondition:	str processed is out, without spaces && punctuations && in lower case.
{
	string strA;									
	strA = "";
	for (unsigned int i(0); i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
		if (islower(str[i]))
			strA += str[i];
	}
	return strA;
}

//*************************************************************************************************

string Reverse(/* in */ string str)
//	this function is to reverse the str passed in.
//	Precondition:	str.length() > 0.
//	Postcondition:	str[0]..[str.length() - 1] reversed to str[str.length() - 1]..str[0].
{
	string strR;									
	strR = "";
	for (int i(str.length() - 1); i >= 0; i--)
		strR += str[i];
	return strR;
}

//*************************************************************************************************

bool Compare  (/* in */ string str1,
			   /* in */ string str2)
//	this function is to compare two strings to judge if they are equal.
//	Precondition:	str1 && str2 are defined.
//	Postcondition:	return true if equal, else false.
{
	if (str1 == str2)
		return true;
	else 
		return false;
}

//*************************************************************************************************

void Output(/* in */ bool result)
//	this function is to translate(output) bool value true to "yes", false to "no".
//	Precondition:	result is 0 or nonzero.
//	Postcondition:	output "yes" if nonzero, "no" else. 
{
	if (result)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
