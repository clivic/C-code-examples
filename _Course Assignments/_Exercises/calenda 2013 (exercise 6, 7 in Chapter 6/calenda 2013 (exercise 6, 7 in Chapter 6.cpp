/********************************************************************
This program is designed to make the calenda of Year 2013.
Version 1.0.0
********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int seven(7);			//7 days in a week

void MonthCalendar(int startDay, int days, int& date);


int main()
{
	cout << "This program outputs the calenda of "
		 << "year 2013." << endl << endl;
	int date = 2;			//represents for January 1st.

	cout << "January" << endl;
	MonthCalendar(date, 31, date);

	cout << "February" << endl;
	MonthCalendar(date, 28, date);

	cout << "March" << endl;
	MonthCalendar(date, 31, date);

	cout << "April" << endl;
	MonthCalendar(date, 30, date);

	cout << "May" << endl;
	MonthCalendar(date, 31, date);

	cout << "June" << endl;
	MonthCalendar(date, 30, date);

	cout << "July" << endl;
	MonthCalendar(date, 31, date);

	cout << "August" << endl;
	MonthCalendar(date, 31, date);

	cout << "September" << endl;
	MonthCalendar(date, 30, date);

	cout << "October" << endl;
	MonthCalendar(date, 31, date);

	cout << "November" << endl;
	MonthCalendar(date, 30, date);

	cout << "December" << endl;
	MonthCalendar(date, 31, date);
	
	
}

//*******************************************************************

void MonthCalendar(/* in */ int startDay,		//Month.1st 
				   /* in */ int days,			//days for each month
				   /* out */ int& date)			//the current date of 
												//num variable and 
												//the next start day
{
	cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat"
		 << endl;
	
	int num(1);				//the date			
	
	startDay = date;		
	date = startDay;
	if (startDay > 6)
	{
		startDay = 0;
		date = 0;
	}
	cout << setw(3 + 6 * startDay - 1) << num ;
	num++;
	date++;
	
	while (num <= days)
	{
		if (date > 6)
		{
			date = 0;
			cout << endl << setw(2) << num;
		}
		else
		{
			cout << setw(6) << num;
		}
		num++;
		date++;
	}
	cout << endl << endl;

}