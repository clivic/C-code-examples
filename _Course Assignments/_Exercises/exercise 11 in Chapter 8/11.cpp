#include <iostream>

using namespace std;

bool Exhausted(int);

int main()
{
	int filmRolls;
	cin >> filmRolls; 
	cout << Exhausted(filmRolls);
	return 0;
}

//***********************************************

bool Exhausted(/* in */ int roll)
{
	static total(0);
	total += roll;
	if (total >= 1000)
	{
		total = 0;
		return true;
	}
	return false;
}