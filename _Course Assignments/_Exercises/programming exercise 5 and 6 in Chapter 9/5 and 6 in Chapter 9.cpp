/**************************************************************************************************
Time Translator:
This program is to read a time in numeric form and print it in English.
And the user can choose to continue to input times after reading a time or end directly.
**************************************************************************************************/

#include <iostream>
#include <string>			//for output
using namespace std;

//function prototypes
void Translate(int, int);
bool Judge();

int main()
{
	int  hour, 
		 min;
	bool ifContinue;
	do
	{
		//invalid input preventing
		do
		{
			cout << "Enter time: ";
			cin >> hour >> min;
			if (hour >= 24 || hour < 0 || min >= 60 || hour < 0)
				cout << "The input of time is not object, please input it again." << endl;
		}	while (hour >= 24 || hour < 0 || min >= 60 || hour < 0);

		Translate(hour, min);
		ifContinue = Judge();
	}	while (ifContinue);
	cout << "Thank you for your using!" << endl;
	return 0;
}

//*************************************************************************************************

void Translate(/* in */	int hour, 
			   /* in */	int min)
/*	This function translates time in numeric form into English expression form.
	Precondtion:	time is in objective state.
	Postcondition:	a statement expressing time is output.										 */

{
	string hourE,			//hour expressed in English
		   min1E,			//minute of second digit expressed in English
		   min2E,			//minute of first digit expressed in English
		   period;			//AM or PM

	if (hour == 12 && min == 0)
	{
		cout << "Noon" << endl;
		return;
	}
	else if (hour == 0 && min == 0)
	{
		cout << "Midnight" << endl;
		return;
	}

	else
	if (hour >= 0 && hour <= 11)
		period = "AM";
	else
		period = "PM";

	//switch hour
	switch (hour)
	{
		case (0)	:	hourE = "Zero";		break;
		case (1)	:
		case (13)	:	hourE = "One";		break;
		case (2)	:
		case (14)	:	hourE = "Two";		break;
		case (3)	:
		case (15)	:	hourE = "Three";	break;
		case (4)	:
		case (16)	:	hourE = "Four";		break;
		case (5)	:
		case (17)	:	hourE = "Five";		break;
		case (6)	:
		case (18)	:	hourE = "Six";		break;
		case (7)	:
		case (19)	:	hourE = "Seven";	break;
		case (8)	:
		case (20)	:	hourE = "Eight";	break;
		case (9)	:
		case (21)	:	hourE = "Nine";		break;
		case (10)	:
		case (22)	:	hourE = "Ten";		break;
		case (11)	:
		case (23)	:	hourE = "Eleven";	break;
	}

	//switch by min1E
	switch (int(min / 10))
	{
		case (0)	:	min1E = "";				break;
		case (2)	:	min1E = "twenty ";		break;
		case (3)	:	min1E = "thirty ";		break;
		case (4)	:	min1E = "fourty ";		break;
		case (5)	:	min1E = "fifty ";		break;
	}

	//switch by min2E
	switch (min % 10)
	{
		case (0)	:	min2E = "";				break;
		case (1)	:	min2E = "one ";			break;
		case (2)	:	min2E = "two ";			break;
		case (3)	:	min2E = "three ";		break;
		case (4)	:	min2E = "four ";		break;
		case (5)	:	min2E = "five ";		break;
		case (6)	:	min2E = "six ";			break;
		case (7)	:	min2E = "seven ";		break;
		case (8)	:	min2E = "eight ";		break;
		case (9)	:	min2E = "nine ";		break;
	}

	//switch by special 10 to 19
	switch (int(min))
	{
		case (10)	:	{min1E = "ten ";		min2E = "";		break;}
		case (11)	:	{min1E = "eleven ";		min2E = "";		break;}
		case (12)	:	{min1E = "twelve ";		min2E = "";		break;}
		case (13)	:	{min1E = "thirteen ";	min2E = "";		break;}
		case (14)	:	{min1E = "fourteen ";	min2E = "";		break;}
		case (15)	:	{min1E = "fifteen ";	min2E = "";		break;}	
		case (16)	:	{min1E = "sixteen ";	min2E = "";		break;}
		case (17)	:	{min1E = "seventeen ";	min2E = "";		break;}
		case (18)	:	{min1E = "eighteen ";	min2E = "";		break;}
		case (19)	:	{min1E = "nighteen ";	min2E = "";		break;}
	}

	//judge special o'clock
	if (min == 0)
	{	
		min1E = "o'clock ";
		min2E = "";
	}

	cout << hourE << ' ' << min1E << min2E << period << endl;	
}

//*************************************************************************************************

bool Judge()
/*	This function is to judge whether to continue to input time.
	Precondion:		not needed.
	Postcondition:	value "true"(to continue) or "false"(to stop) is returned to main function.	 */

{
	cout << "Please input \"Y\" or \"N\" to tell us whether to continue inputting:" << endl;
	char answer;
	cin >> answer;
	
	
	while (answer != 'Y' && answer != 'y' &&
		   answer != 'N' && answer != 'n')
	{
		cout << "Your input isn't valid, please input your answer again:" << endl;	
		cin >> answer;
	}

	if (answer == 'Y' || answer == 'y')
		return true;
	else
		return false;
}
