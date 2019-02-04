//*******************************************************************
//	test for while(cin >> value), calculate the sum of numbers input
//*******************************************************************
#include <iostream>

using namespace std;

int main()
{
	int sum = 0, val = 0;
	while (cin >> val)
		sum += val;
	cout << "The sum is: " << sum << endl;
	return 0;
}

//	Result:	
//	Still related to ctrl D...
