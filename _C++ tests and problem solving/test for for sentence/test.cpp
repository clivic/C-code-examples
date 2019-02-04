/*******************************************************************************************************************************************
This program is aimed to test if for sentense can be used by 3 steps: start point, ceiling, and step.
And we add an array test to see if for sentence can be used without a brace.
*******************************************************************************************************************************************/


#include <iostream>
#include <string>

using namespace std;

void main()
{
	//cin && sum for sentence
	int sum=0,n;
	for (cin >> n; n<=10;n++)
	{sum=sum+n;}
	cout << sum << endl;
	
	//array for sentence
	int array[15];
	for (n = 1; n < 15; n++)
		array[n] = 0;
	for (n = 1; n < 15; n++)
		cout << array[n] << ' ';
	cout << endl;
}

//Result:	The results seem to be positive.
