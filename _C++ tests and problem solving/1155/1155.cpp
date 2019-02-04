#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x, y;
	int a;
	cin >> x >> a >> y;
	cout << fixed << setprecision(6)
		 << x + a % 3 * (int) (x + y) % 2 / 4
		 << endl;
	return 0;
}