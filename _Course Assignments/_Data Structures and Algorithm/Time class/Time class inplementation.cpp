/**************************************************************************************************
This is the Time class's Inplementation file.
**************************************************************************************************/

#include "Time class specification.h"
#include <iostream>
#include <string>

using namespace std;

/*	private members of the class:
	int hrs;
	int mins;		
	int secs;					*/

//*************************************************************************************************

Time::Time()
/*	Initialize the time when defining a class type variable or constant
	It's default.
	Postcondition:	hrs == mins == secs == 0.							*/
{
	hrs = 0;
	mins = 0;
	secs = 0;
}

//*************************************************************************************************

Time::Time(/* in */ int hours,
		   /* in */ int minutes,
		   /* in */ int seconds)
/*	Initialize the time when defining a class type variable or constant
	It's initialized by client.
	Postcondition:	hrs == hours && mins == minutes && secs == seconds	*/
{
	hrs = hours;
	mins = minutes;
	secs = seconds;
}

//*************************************************************************************************

void Time::SetTime(/* in */ int hours,
				   /* in */ int minutes,
				   /* in */ int seconds)
/*	Set the time by client.
	Postcondition:	hrs == hours && mins == minutes && secs == seconds	*/

{
	hrs = hours;
	mins = minutes;
	secs = seconds;
}

//*************************************************************************************************

void Time::Increment()
/*	Add one second to the current variable or constant.				  
	Precondition:	hrs: 0 ~ 23, mins: 0 ~ 59, secs: 0 ~ 59.			
	Postcondition:	time add a second according to clock form.			*/
{
	secs++;
	if (secs > 59)
	{
		secs = 0;
		mins++;
		if (mins > 59)
		{
			mins = 0;
			hrs++;
			if (hrs > 23)
			{
				hrs = 0;
			}
		}
	}
}

//*************************************************************************************************

void Time::Write() const
/*	cout the time in 24-hour form	
	Postcondition:	cout in the form HH:MM:SS.							*/
{
	if (hrs < 10)
		cout << '0';
	std::cout << hrs << ':';
	
	if (mins < 10)
		cout << '0';
	std::cout << mins << ':';
	
	if (secs < 10)
		cout << '0';
	std::cout << secs;
}

//*************************************************************************************************

bool Time::Equal(/* in */ Time another) const
/*	compare the time between itself and the another
	Postcondition:	1 is return if they are equal,	otherwise 0.		*/
{
	return (hrs == another.hrs &&
			mins == another.mins &&
			secs == another.secs);
}

//*************************************************************************************************

bool Time::LessThan(/* in */ Time another) const
/*	compare the time between itself and the another
	Postcondition:	1 is return if itself is less than the another,
	otherwise 0.														*/
{
	return (hrs < another.hrs ||
			hrs == another.hrs && mins < another.mins ||
			hrs == another.hrs && mins == another.mins && secs < another.secs);
}

//*************************************************************************************************

void Time::WriteAmPm()
/*	prints the time in 12-hour rather than 24-hour form, 
	adding AM or PM at the end.
	Precondition:	hrs: 0 ~ 23, mins: 0 ~ 59, secs: 0 ~ 59. 
	Postcondition:	cout the form HH:MM:SS AM(or PM) && HH is in 0 ~ 12.*/
{
	std::string foreOrAfter;			//forenoon or after noon -- AM or PM
	
	if (hrs > 12)
	{
		hrs -= 12;
		foreOrAfter = "PM";
	}
	else
		foreOrAfter = "AM";
	
	if (hrs < 10)
		cout << '0';
	std::cout << hrs << ':';
	
	if (mins < 10)
		std::cout << '0';
	std::cout << mins << ':';
	
	if (secs < 10)
		cout << '0';
	std::cout << secs;
	std::cout << ' ' << foreOrAfter;
}
		

