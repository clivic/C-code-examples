#include <iostream>

using namespace std;

int main()
{
	int n;		//the one you input
	cin >> n;
	if (n % 3 == 0 && n % 5 == 0)
		cout << "can" << endl;
	else
		cout << "cannot" << endl;
	return 0;
}