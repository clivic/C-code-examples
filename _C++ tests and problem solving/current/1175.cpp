#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double f;
	cin >> f;

	double c = 5.0 * (f - 32.0) / 9.0;
	cout << fixed << setprecision(2)
		 << c << endl;
	return 0;
}