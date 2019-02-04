//*******************************************************************
//	test for For loop's counter's scope
//*******************************************************************
#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	cout << "1 to 50's sum: ";
	for (int i = 1; i <= 50; i++)
		sum += i;
	cout << sum << endl;

	sum = 0;
	cout << "51 to 100's sum: ";
	for (int i = 51; i <= 100; i++)
		sum += i;
	cout << sum << endl;
}

//	Results:
//	In Visual C++ 6.0, for loop's scope(its counter) isn't local for the loop,
//	while in Visual Studio 2013, it is.(Please reference that test result)
