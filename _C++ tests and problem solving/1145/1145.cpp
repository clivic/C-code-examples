#include <iostream>

using namespace std;

int main()
{
	int input, max, i(2);
	cin >> max >> input;
	while (i <= 9)
	{
		if (input > max)
			max = input;
			cin >> input;
		i++;
	}
		if (input > max)
			max = input;
	cout << max << endl;
}