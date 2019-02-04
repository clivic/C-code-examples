#include <iostream>
#include <string>

using namespace std;

void main()
{
	string str;
	cout << "Please input a string:  " << endl;		//interactive ioput
	getline(cin, str);
	cout << "The string you've input is:  "<<endl
		 << str <<endl;								//echo printing
	cout << "The substring \"str.substr(0,-0.3)\" is:  " << str.substr(0,-0.3) << endl;
	cout << "The substring \"str.substr(0,100)\" is:  " << str.substr(0,100) << endl;
	cout << "The substring \"str.substr(0,-65536)\" is:  " << str.substr(0,-2) << endl;
}