#include <iostream>

using namespace std;

void Compare()
{
	int a1, a2, a3;		//virsion one
	int b1, b2, b3;		//virsion two
	cin >> a1 >> a2 >> a3
		>> b1 >> b2 >> b3;

	//judge 1
	if (a1 > b1)
		cout << "First" << endl;
	else if (a1 < b1)
		cout << "Second" << endl;
	else

	//judge 2
	if (a2 > b2)
		cout << "First" << endl;
	else if (a2 < b2)
		cout << "Second" << endl;
	else

	//judge 3
	if (a3 > b3)
		cout << "First" << endl;
	else if (a3 < b3)
		cout << "Second" << endl;
	else
		cout << "Same" << endl;
}

int main()
{
	int n;	//number of tests
	cin >> n;
	for (int i = 0; i < n; i++)
		Compare();
	return 0;
}