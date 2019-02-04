/************************************************
This program is to do some of the exercises 
in Chapter 5.
************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

void main(void)
{
	/*No.1
	moon = "blue" || moon = "Blue";*/

	/*No.3
	if (infile)
		infile >> somestring;*/

	/*No.6
	bool1 && !bool2 || !bool1 && bool2;*/

	/*No.7
	if (!(score <= 100 && score >= 0))
		cout << "The score is not in the range!"
			 << endl;*/
	
	/*No.8
	if (!(score <= 100 && score >= 0))
		cout << "The score is not in the range!"
			 << endl;
	else 
	{
		scoreTotal = scoreTotal + score;
		scoreCount++;
	}*/

	//No.9
	cout << "No.9" << endl << endl;
	ifstream infile1;
	ifstream infile2;
	ofstream outfile;

	infile1.open("data1.txt");
	infile2.open("data2.txt");
	outfile.open("out.out");

	int a, b, lesser;
	infile1 >> a;
	infile2 >> b;
	
	if (!infile1 && !infile2)
	{
		cout << "Both input streams have had problems."
			 << endl;
	}
	
	else if (!infile1 && infile2)
	{
		cout << "infile1 stream have broken down."
			 << endl
			 << "We extract a value from infile2."
			 << endl;
		infile2 >> lesser;
		outfile << lesser;
	}
	
	else if (!infile2 && infile1)
	{
		cout << "infile2 stream have broken down."
			 << endl
			 << "We extract a value from infile1."
			 << endl;
		infile1 >> lesser;
		outfile << lesser;
	}
	
	else
	{
		cout << "The lesser value has been writtened"
			 << " into \"out\" file.";
		
		if (a < b)
		{
			lesser = a;
			infile1 >> a;
		}
		
		else
		{
			lesser = b;
			infile2 >> b;
		}
			outfile << lesser;
	}
	infile1.close;
	infile2.close;
	outfile.close;

	//No.10
	/*
	if (score > 100)
		cout << "Duffer.";
	else if (score > 80)
		cout << "Weekend regular.";
	else if (score > 72)
		cout << "Competitive player.";
	else if (score > 68)
		cout << "Turn pro!";
	else 
		cout << "Time to go on tour!";
	*/
	
	//No.11
	//This problem is to output the least one among 3 numbers.
	cout << '\n' << "No.11" << endl << endl;
	cout << "This problem is to output the least "
		 << "one among 3 numbers." << endl;
	cout << "Please input the 3 numbers:" << endl;
	double least, count1, count2, count3;
	cin >> count1 >> count2 >> count3;
	
	if (count1 < count2)
	{
		if (count1 < count3)
			least = count1;
		else 
			least = count3;
	}
	
	else
	{
		if (count2 < count3)
			least = count2;
		else 
			least = count3;
	}
	
	cout << "Then the least number(s) is/are:"
		 << endl;
	if (least == count1)
		cout << least << endl;
	if (least == count2)
		cout << least << endl ;
	if (least == count3)
		cout << least << endl ;
	else;
	
	//No.13

	cout << endl << endl;
	cout << "No.13" << endl << endl;
	double area, root;
	cout << "This problem is to output the" 
		 << " square root of the area" << endl;
	cout << "Please input the value of area."
		 << endl;
	cin >> area;
	bool state;
	state = (area >= 0);
	if (state)
		cout << "Then the root is:" << endl
			 << sqrt(area) << endl;
	else
	{
		cout << "it's negative, we take its "
			 << "absolute value." << endl;
		area = fabs(area);
		cout << "So the root is:" << endl
			 << sqrt(area) << endl << endl;
	}
}

