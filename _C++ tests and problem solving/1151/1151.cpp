#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double x1, x2, squaredDelta;
	squaredDelta = sqrt(pow(b,2) - 4 * a * c);
	if (squaredDelta < 0)
	{
		cout << "no answer" << endl;

	}
	else if (!squaredDelta)
	{
		x1 = -b / (2 * a);
		cout << fixed << setprecision(4) << x1 << endl;
	}
	else
	{
		x1 = (-b - squaredDelta) / (2 * a);
		x2 = (-b + squaredDelta) / (2 * a);
		cout << fixed << setprecision(4) << x1 << ' ' << x2 << endl;
	}
	return 0;
}