/*************************************************************
This program uses get() function.
*************************************************************/
#include <iostream>
using namespace std;

int main ()
{
    char  char1;
    char  char2;
    char  char3;
    char  char4;
	int i(2), j(3), k(5);

    cout  << "Input four characters.  Press Return."  << endl;
    //cin >> char1  >> char2  >> char3  >> char4;
	cin >> i >> j >> k;
    //cout  << char1  << char2  << char3  << char4;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;

    return 0;
}
