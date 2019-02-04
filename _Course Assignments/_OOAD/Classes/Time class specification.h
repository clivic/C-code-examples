/**************************************************************************************************
This is the Time class's Specification file.
It contains: 2 constructors, SetTime, Increment, Write, Equal, LessThan
**************************************************************************************************/

class Time
{
public:
		Time();
		/*	Initialize the time when defining a class type variable or constant
			It's default.
			Postcondition:	hrs == mins == secs == 0.							*/
		
		Time(/* in */ int hours,
			 /* in */ int minutes,
			 /* in */ int seconds);
		/*	Initialize the time when defining a class type variable or constant
			It's initialized by client.
			Postcondition:	hrs == hours && mins == minutes && secs == seconds	*/

		void SetTime(/* in */ int hours,
				     /* in */ int minutes,
					 /* in */ int seconds);
		/*	Set the time by client.
			Postcondition:	hrs == hours && mins == minutes && secs == seconds	*/

		void Increment();
		/*	Add one second to the current variable or constant.				  
			Precondition:	hrs: 0 ~ 23, mins: 0 ~ 59, secs: 0 ~ 59.		
			Postcondition:	time add a second according to clock form.*/
		
		void Write() const;
		/*	cout the time in 24-hour form	
			Postcondition:	cout in the form HH:MM:SS.							*/

		bool Equal(/* in */ Time another) const;
		/*	compare the time between itself and the another
			Postcondition:	1 is return if they are equal,	otherwise 0.
							and this class should be in same day of the other	*/

		bool LessThan(/* in */ Time another) const;
		/*	compare the time between itself and the another
			Postcondition:	1 is return if itself is less than the another,
			otherwise 0.	and this class should be in same day of the other	*/

		void WriteAmPm();
		/*	prints the time in 12-hour rather than 24-hour form, 
			adding AM or PM at the end.
			Precondition:	hrs: 0 ~ 23, mins: 0 ~ 59, secs: 0 ~ 59. 
			Postcondition:	cout the form HH:MM:SS AM(or PM) && HH is in 0 ~ 12.*/


private:
		int hrs;
		int mins;
		int secs;
};