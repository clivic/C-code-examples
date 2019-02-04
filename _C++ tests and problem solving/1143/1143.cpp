#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	long double t(0), i(1);
	while (i <= 99)
	{
		t = t + 1.0 / i;
		i++;
		t = t - 1.0 / i;
		i++;
	
	}
	cout << fixed << setprecision(8) << t << endl;
	return 0;
}		
