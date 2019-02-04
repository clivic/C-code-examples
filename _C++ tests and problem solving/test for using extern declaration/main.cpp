/************************************************
This program is to test the use of variable
declaration other than definition - extern.
And it by the way test if the constant is related
to it.
************************************************/

#include <iostream>

using namespace std;

int a = 5;

int OutPut(int n);

int main()
{	
	int x;		 //the number user input
	const int a = 3;  //for the function uses 
					  //external variable,
					  //it will ignore this 
				      //constant.
	cout << "This program is to test extern "
		 << "declaration." << endl;
	cout << "Please enter a number and we "
		 << "mutiply it by 5." << endl;
	cin >> x;
	cout << "Then it is: "
		 << OutPut(x) << endl;   //in "sub" file

	return 0;
}
	
/*Result: It turns out that constant couldn't be 
externed, for it's not a variable.
while const could be declared in almost any where 
in a .cpp file.*/