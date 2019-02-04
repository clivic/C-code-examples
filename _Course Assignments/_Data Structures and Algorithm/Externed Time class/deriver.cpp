//*******************************************************************
//	Driver to test virtual functions
//*******************************************************************
#include "EXTTIME.H"
#include "TIME.H"
#include <iostream>

using namespace std;

void Print(/* in */ Time& time)
//write time in a format using virtual member function Write()
{
	cout << "***************************************" << endl;
	cout << "Time is: ";
	time.Write();
	cout << "\n***************************************" << endl;
}
void main()
{
	ExtTime timeE(13, 20, 7, CST);
	Time time(13, 20, 7);
	Print(timeE);
	cout << endl << endl;
	Print(time);
}
