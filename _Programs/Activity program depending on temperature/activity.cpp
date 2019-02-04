/************************************************
Activity program
This program outputs an appropriate activity for
the corresponding temperature.
************************************************/

#include <iostream>

using namespace std;

void main()
{
	double temp; //temperature
	cout << "Please input the temperature in "
		 << "Fahrenheit format." << endl;
	cin >> temp;
	cout << "The current temperature is then: "
		 << temp << endl; //echo printing
	if (temp > 120)
		cout << "It's too hot perhaps, unrealastic..."
		     << endl;
	else if (temp > 85)
		cout << "The appropriate sport is "
		     << "swimming." << endl;
	else if (temp > 70)
		cout << "The appropriate sport is "
		     << "tennis." << endl;
	else if (temp > 32)
		cout << "The appropriate sport is "
		     << "golf." << endl;
	else if (temp > 0)
		cout << "The appropriate sport is "
		     << "skiing." << endl;
	else 
		cout << "The appropriate sport could only be "
		     << "dancing... perhaps." << endl;
}
