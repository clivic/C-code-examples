//*******************************************************************
//	To figure out what are the code below doing
//*******************************************************************

#include <iostream>

using namespace std;

const int MAX = 6;

typedef float vector[MAX];

float Figure(vector vector1)
{
	int a1, a4;
	float a2, a3;
	a1 = 0;
	a2 = vector1[a1];
	a3 = 0.0f;
	a4 = a1;
	for (a4 = 0; a4 < MAX; a4++)
	{
		a1 += 1;
		a2 = vector1[a1 - 1];
		a3 += a2;
	}
	a1 -= 1;
	a2 = a1;
	return (a2 = a3 / a2);
}

int main()
{
	vector v = {1,2,3,4,5,6};
	cout << Figure(v) << '\n' << flush;
	return 0;
}
