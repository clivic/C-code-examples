/************************************************************************************************************************************
This program is to fillinthe blanks, doing 10, 11 exercises.
************************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inData;
ofstream outData;
const double PI = 3.1415926535897932384626;
float radius;
float circumference;
float area;
string input;

int main()
{
	cout << "Please enter the input data name:" << endl;
	cin >> input;
	inData.open(input.c_str());
	outData.open("outData.dat");
	inData >> radius;
	circumference = radius * 2 * PI;
	area = radius * radius * PI;
	cout << "For the first circle, the circumference is "
		 << circumference << " and the area is " << area << endl;
	outData << radius << " " << circumference << " " << area
		 << endl;
	
	inData >> radius;
	circumference = radius * 2 * PI;
	area = radius * radius * PI;
	cout << "For the second circle, the circumference is "
		 << circumference << " and the area is " << area 
		 << endl;
	outData << radius << " " << circumference << " " << area
		 << endl;
	return 0;
}