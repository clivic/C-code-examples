//*******************************************************************
//	temperature chart
//	this program reads a series of 24 hourly temperatures from a file
//	and outputs a bar chart for the day.
//	file name is sepecified for input convenience -- "Daytemp.txt"
//	Notes: temperature entered should be in range -30 ~ 120 F
//*******************************************************************
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

ifstream fin;

const int NUM = 24;					//num of temperatures to be read

bool TestInput()
//	to verify the input is valid
{
	if (!fin)
	{
		cout << "Can't open data." << endl;
		return false;
	}
	else
		return true;
}

string Bar(/* in */		int temp,
		   /* inout */	string& str)
//	to convert the temperature to a bar consists of stars, each of which
//	represents 3 degrees
//	Preconditions:	temp is in range of -30 ~ 120
//	Postconditions:	a bar of stars are returned
{
	temp = abs(temp);
	str = "";						//initialization 
	int len;						//number of stars
	len = temp / 3 + temp % 3 /2;	//to format the bar, making it:
									//2,3,4 are all one * 
									//while 5,6,7 are all two* ...
	for (int i = 0; i < len; i++)
		str += '*';
	return str;
}

//main function
int main()
{
	//file open and test
	fin.open("Daytemp.txt");
	if (!TestInput())
		return 1;
	
	//chart head format
	cout << "Temperatures for 24 hours:\n"
		 << right << setw(7) << -30 
		 << setw(9) << 0
		 << setw(10) << 30
		 << setw(10) << 60
		 << setw(10) << 90
		 << setw(11) << 120 << endl;

	//read in
	int count(0);		//num of temperatures have been read
	int temp;			//current temperature
	string str = "";	//asteristics bar
	
	for (; count < NUM; count++)
	{
		fin >> temp;
		cout << setw(4) << temp << setw(11);

		if (temp < 0)
			cout << Bar(temp, str) << '|' << endl;
		else
			cout << ' ' << '|' << Bar(temp, str) << endl;
	}

	return 0;
}