#include <iostream>
#include <string>
#include "planets.h"

using namespace std;

//function prototypes
void NamePrint(int num);

int main()
{
	unsigned int num;
	cin >> num;
	if (num >= 11)
	{
		cout << "Error" << '\n';
		return 1;
	}
	NamePrint(num) ;
	return 0;

}

//***********************************************

void NamePrint(int num)	
{
	Planets planet = (Planets) num;
	
	switch (planet)
	{
	case (MERCURY)	:	cout << "Mercury"	<< '\n';	break;
	case (VENUS)	:	cout << "Venus"		<< '\n';	break;
	case (EARTH)	:	cout << "Earth"		<< '\n';	break;
	case (MOON)		:	cout << "Moon"		<< '\n';	break;
	case (MARS)		:	cout << "Mars"		<< '\n';	break;
	case (JUPITER)	:	cout << "Jupiter"	<< '\n';	break;
	case (SATURN)	:	cout << "Saturn"	<< '\n';	break;
	case (URANUS)	:	cout << "Uranus"	<< '\n';	break;
	case (NEPTUNE)	:	cout << "Neptune"	<< '\n';	break;
	case (PLUTO)	:	cout << "Pluto"		<< '\n';	break;
	}
}