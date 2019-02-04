#include <iostream>

using namespace std;

void Rev();

void main()
{
	Rev();
}

//*********************

//12's Rev
/*
void Rev()
{
	int num;
	cin >> num;
	if (cin)
	{
		Rev();
		cout << num << endl;
	}
}
*/

//13's Rev
void Rev()
{
	int num;
	cin >> num;
	if (cin)
	{
		cout << num << endl;
		Rev();
		cout << num << endl;
	}
}