#include <iostream>

using namespace std;

int main()
{
	for (int i = 1900; i <= 2000; i++)
	{
		if (i % 400 == 0 || 
			i % 4 == 0 && i % 100 != 0)
			cout << i << endl;
	}
	return 0;
}