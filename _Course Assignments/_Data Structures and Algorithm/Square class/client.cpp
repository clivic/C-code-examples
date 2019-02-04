#include "Square class Specification.h"
#include <iostream>

using namespace std;

int main()
{
	Square square(5, 3);
	square.Write();
	cout << "Its square is: " << square.CSquare() << endl;
	cout << "And its circunference is: " << square.
		CCircum() << endl;
	return 0;
}