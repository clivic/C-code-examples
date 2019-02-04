/************************************************
This program is to compare the two characters you
have input.
************************************************/

#include <iostream>

using namespace std;

void main()
{
	cout << "This program is to compare the two"
		 << " characters you've input." << endl;
	cout << "Please input two characters: "
		 << "(noticing with no spaces.)"
		 << endl;
	char a, b, larger, smaller;
	cin.get(a);
	cin.get(b);
	larger = a > b ? a : b;
	smaller = a > b ? b : a;
	cout << "The larger char is " << larger
		 << " and the smaller one is " << smaller
		 << endl;
}