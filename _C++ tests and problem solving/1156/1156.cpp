#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x, y;
	int a, b;
	cin >> a >> b >> x >> y;
	cout << fixed << setprecision(6)
		 << (float)(a + b) / 2 + (int)x % (int)y 
		 << endl;
	return 0;
}