#include <iostream>
#include <string>
#include <cctype>        //stands for "C-char type


using namespace std;

void LowerCount(istream& cin, int& count);  //to count lower case characters

void TimeAdd1(int& days1, int& hours1, int& minutes1, 
			 int days2, int hours2, int minutes2);     //to add time

void TimeAdd2(int& days1, int& hours1, int& minutes1, int& seconds1, 
			 int days2, int hours2, int minutes2, int seconds2);     //to add time (more precise)

void SeasonPrint(int month, int day, ostream& cout);   //to tell season 

//No.12 function

void LowerCount(/* in */ istream& cin,
				/* out */ int& count)
/*	This function counts lowercase alphabets in one cin line.
	Precondition : cin is valid.
	Postcondition: output the number of lowercase characters.				*/
{	
	cout << "Please input a line and we count its number of lower characters." 
		 << endl;
	//string line;
	//string current;
	//current = line;
	count = 0;
	char a;
	cin.get(a);
	while (a!='\n')
	{
		if (islower(a))
		{
			count++;
		}
		
		cin.get(a);
	}
	
	/*a = current.substr(0,1);
	if (islower(a))
		{
			count++;
		}*/
	cout << "There are " << count << " lowercase characters in the line you've input." 
		 << endl;
}

//***************************************************************************************

//No.16 function

void TimeAdd1(/* inout */ int& days1,
			 /* inout */ int& hours1,
			 /* inout */ int& minutes1, 
			 /* in */ int days2, 
			 /* in */ int hours2,
			 /* in */ int minutes2)
{
	if (hours1 > 23 || hours1 < 0 ||
		hours2 > 23 || hours2 < 0 ||
		minutes1 > 59 || hours1 < 0 ||
		minutes2 > 59 || hours2 < 0 )
	{
		cout << "The value isn't legal." << endl; 
	}

	//add minutes
	
	bool addmin1(0); //upcase of minutes adding
	
	if (minutes1 + minutes2 > 59)
	{
		addmin1 = 1;
		minutes1 = minutes1 + minutes2 - 60;
	}
	else
	{
		addmin1 = 0;
		minutes1 = minutes1 + minutes2;
	}

	//add hours

	bool addhou1(0); //upcase of hours adding

	if (hours1 + hours2 + addmin1 > 23)
	{
		addhou1 = 1;
		hours1 = hours1 + hours2 + addmin1 - 24;
	}
	else
	{
		addhou1 = 0;
		hours1 = hours1 + hours2 + addmin1;
	}

	//add days

	days1 = days1 + days2 + addhou1;

}

//***************************************************************************************

//No.17 function

void TimeAdd2(/* inout */ int& days1,
			 /* inout */ int& hours1,
			 /* inout */ int& minutes1, 
			 /* inout */ int& seconds1,
			 /* in */ int days2, 
			 /* in */ int hours2,
			 /* in */ int minutes2,
			 /* in */ int seconds2)
{
	if (hours1 > 23 || hours1 < 0 ||
		hours2 > 23 || hours2 < 0 ||
		minutes1 > 59 || hours1 < 0 ||
		minutes2 > 59 || hours2 < 0 ||
		seconds1 > 59 || seconds1 < 0 ||
		seconds2 > 59 || seconds2 < 0 )
	{
		cout << "The value isn't legal." << endl; 
	}

	//add seconds

	bool addsec1(0); //upcase of seconds adding
	
	if (seconds1 + seconds2 > 59)
	{
		addsec1 = 1;
		seconds1 = seconds1 + seconds2 - 60;
	}
	else
	{
		addsec1 = 0;
		seconds1 = seconds1 + seconds2;
	}

	//add minutes
	
	bool addmin1(0); //upcase of minutes adding
	
	if (minutes1 + minutes2 + addsec1 > 59)
	{
		addmin1 = 1;
		minutes1 = minutes1 + minutes2 + addsec1 - 60;
	}
	else
	{
		addmin1 = 0;
		minutes1 = minutes1 + minutes2 + addsec1;
	}

	//add hours

	bool addhou1(0); //upcase of hours adding

	if (hours1 + hours2 + addmin1 > 23)
	{
		addhou1 = 1;
		hours1 = hours1 + hours2 + addmin1 - 24;
	}
	else
	{
		addhou1 = 0;
		hours1 = hours1 + hours2 + addmin1;
	}

	//add days

	days1 = days1 + days2 + addhou1;
}

//***************************************************************************************

//No.18 function

void SeasonPrint(/* in */ int month, 
				 /* in */ int day,
				 /* out */ ostream& out)	//out put season

 // Prints the season given month and day.
 // Precondition: 
 //		month is validated &&
 //		day is validated.
 //	Postcondtion: 
 //		cout the season name.
					
{
	string season;    

	if (day >= 21)
	{
		if (month >= 3 && month <= 5)
			season = "Spring";
		else if (month >= 6 && month <= 8)
			season = "Summer";
		else if (month >= 9 && month <= 11)
			season = "Autumn";
		else
			season = "Winter";
	}

	else
	{
		if (month >= 4 && month <= 6)
			season = "Spring";
		else if (month >= 7 && month <= 9)
			season = "Summer";
		else if (month >= 10 && month <= 12)
			season = "Autumn";
		else
			season = "Winter";
	}

	out << "The season is: " << season << '.' << endl;
}













void main()
{
	int count(0);
	LowerCount(cin, count);  //No.12
	//SeasonPrint(3, 7, cout); //No.18
	
}

	