//*******************************************************************
//	test for For loop's counter's scope
//*******************************************************************
#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	cout << "1 to 50's sum: ";
	for (int i(1); i <= 50; i++)
		sum += i;
	cout << sum << endl;

	sum = 0;
	cout << "51 to 100's sum: ";
	for (int i(51); i <= 100; i++)
		sum += i;
	cout << sum << endl;
}

//	Results:
//	In Visual Studio 2013, for loop's scope(its counter) is local,
//	while in Visual C++ 6.0, it isn't.(Please reference that test result)
//	Besides, i(1) and i = 1 are both available.