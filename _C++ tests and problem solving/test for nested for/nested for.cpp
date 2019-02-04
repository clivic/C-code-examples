/************************************************
This program tests for a nested for statement
************************************************/

#include <iostream>

using namespace std;

int main()
{	
	//nested for
	for (int x(1); x <= 10; x++)		//outermost
		for (int y(1); y <= 10; y++)	//middle
			for (int z(1); z <= 10; z++)//innermost
				cout << x << '+' << y
					 << '+' << z << '='
					 << ' '  
					 <<x + y + z << endl;
	return 0;
}

//result:	for x, 10 times;
//			for y, 100 times;
//			for z, 1,000 times;