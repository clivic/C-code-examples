#include <iostream>

using namespace std;

void main()
{
	char a('a');
	char b('\001');
	cout << a + 1 << endl;
	cout << a + b << endl;
	cout << char(a + b) << endl;
}

/*	Result:
	The cout stream outputs the data type of the expression.
	So char + char yields int, char + int also yileds int.
	(Without explicit type corecion.)						*/