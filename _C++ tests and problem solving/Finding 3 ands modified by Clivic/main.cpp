/************************************************
Finding 3 "ands" program
This program is intended to find the word "and"
in the sentence user input, and this update 
virsion is more some intelligent, for it can 
identify the no-found situation.
************************************************/
#include <iostream>
#include <string> 

using namespace std;

void main()
{
	cout << "Please input the sentence:" << endl;
	string sentence, str1, str2;
	getline(cin, sentence);
	string::size_type first, second, third;
	cout << "The input sentence is:" << endl
		 << sentence << endl << endl;
	first = sentence.find("and");
	
	if (first == string::npos)
	{
		cout << "The first and cannot be found."
			 << endl;
		first = 0;
	}
	else
		cout << "The first position is: " 
		<< first << " position." << endl;
	
	str1 = sentence.substr(first + 1, sentence.length() - first - 1);
	
	second = str1.find("and");
	if (second == string::npos)
	{
		cout << "The second and cannot be found."
			 << endl;
		second = 0;
	}
	else
		cout << "The second position is: " 
		<< first + second + 1 << " position."
		<< endl;

	str2 = str1.substr(second + 1, str1.length() - second - 1);

	third = str2.find("and");
	if (third == string::npos)
	{
		cout << "The third and cannot be found."
			 << endl;
	}
	else
		cout << "The third position is: " 
		<< first + second + third + 2<< " position."
		<< endl;
}