#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	string b;
	string::size_type position;

    cout << "please write a string ";
	cin >> a;
	position = a.length();
	b = a.substr(position,1);
	position--;
	while (position >= 0)
	{
		b = b+a.substr(position,1);
			position--;
	}
	cout << b<<endl;
	if (a == b)
		cout << endl << "is a palindrome" << endl;
	else 
		cout << endl << "is not a palindrome" << endl;
	return 0;
}

