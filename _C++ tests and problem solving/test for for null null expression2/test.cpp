#include <iostream>

using namespace std;

int main()
{
	int count = 1;

	for (;;count+=1)
		if (count < 3)
			cout << count;
		else
			break;


	return 0;
}