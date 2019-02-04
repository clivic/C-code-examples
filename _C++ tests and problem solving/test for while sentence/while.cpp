/*******************************************************************************************************************************************
This program is aimed to test if while sentense can be used by 2 steps: start point, ceiling, and out of the block setting the step.
*******************************************************************************************************************************************/


#include <iostream>
#include <string>

using namespace std;

void main()
{
	int sum = 0, n;
	cin >> n;
	while ( n<=10)
	{sum=sum+n;
	n++;}
	cout << sum << endl;
}
//The result seems to be positive.
