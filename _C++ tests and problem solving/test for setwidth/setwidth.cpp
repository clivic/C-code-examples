#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a(10), b(9876);
	char ch('c');

    //set left Justified
    cout << setiosflags(ios::left);
	cout << "********************" << endl
		 << setfill(' ') << setw(6) << a << setw(7) << b << setw(7) << "water" << endl;
	
	//set right Justified and test if char could be set width
	cout << right << setw(7) << ch << endl;
	return 0;
}