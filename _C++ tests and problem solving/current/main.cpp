#include "class.h"
#include <iostream>

int main()
{
	Time time1(19,40,00);
	Time time2;
	std::cout << "Write time1: ";
	time1.Write();
	std::cout << std::endl;

	std::cout << "Write time2: ";
	time2.Write();
	std::cout << std::endl;

	time2.Increment();
	std::cout << "Incremented time2: ";
	time2.Write();
	std::cout << std::endl;
	
	std::cout << "AM/PM time1: ";
	time1.WriteAmPm();
	std::cout << std::endl;

	std::cout << "Compare time1 and time2:\n"
			  << "Less than?  " << time1.LessThan(time2) << std::endl
			  << "equal to?   " << time1.Equal(time2) << std::endl;

	time1.SetTime(8, 50, 35);
	std::cout << "Seted time1 and AM/PM: ";
	time1.Write();
	std::cout << std::endl;
	time1.WriteAmPm();
	std::cout << std::endl;

	return 0;
}
