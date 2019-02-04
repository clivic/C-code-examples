#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x=1111111111111.111111111;
	double y=2222222222222.222222222;
	cout << fixed << setprecision(4)
		 << (x + y) << endl;
	return 0;
}
