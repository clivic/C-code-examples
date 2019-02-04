//***********************************************
//	test for some escape sequences especially
//	\v(vertical tab), \f(form feed)
//***********************************************
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello" 
		 << '\v'
		 << '\f'
		 << "world!" << endl;
	return 0;
}