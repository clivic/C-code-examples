#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;




int main()
{
	ifstream fin1;					  //for No.3
	ifstream fin2;					  //for No.4
	ifstream fin3;					  //for No.8
	ifstream fin4;					  //for No.14

	
	//No.1
	cout << "No.1 " << endl << endl;

	int number(-10);         //count from -10 to 10
	while (number <=10)
	{
		cout << number << '\n';
		number++;
	}
	cout << endl;


	//No.2
	cout << "No.2 " << endl << endl;

	number = 1;
	int recentlyNumber;       //different from number
	int sum(0);               //sum of 1 to 10000
	while (sum <= 10000)
	{
		sum = sum + number;
		number++;
	}

	recentlyNumber = number - 1;
	cout << "The sum is: " << sum << endl
		 << "And the recently added number is : "
		 << recentlyNumber << endl << endl;

	
	//No.3
	cout << "No.3 " << endl << endl;
	fin1.open("indata.txt");
	if (!fin1 || !fin2 || !fin3)
	{
		cout << "Can't open data." << endl;
		return 1;
	}
	int score;
	int average;
	number = 1;
	sum = 0;
	fin1 >> score;
	while (fin1 || number <= 20)
	{
		sum = sum + score;
		fin1 >> score;
		number++;
	}
	recentlyNumber = number - 1;
	average = sum / recentlyNumber;
	cout << "Their average number is: "
		 << average << '.' << endl << endl;
	fin1.close();
	fin1.clear(ios::goodbit);// ios::goodbit stands for good state of input
							 // and we can go on to operate. 
							 // meanwhile we can use clear function without
							 // it :)


	//No.4
	cout << "No.4 " << endl << endl;
	fin2.open("chapter6.txt");
	if (!fin1 || !fin2 || !fin3)
	{
		cout << "Can't open data." << endl;
		return 1;
	}
	number = 1;             //the line number              
	string curStr;          //the current string
	string findStr;         //the string we'll find
	getline(fin2, curStr);
	findStr = "code segment";
	cout << "The number of lines contain "
		 << "\"code segment\" are: " << endl;
	while (fin2)
	{
		if (curStr.find(findStr) != string::npos)
		{
			cout << number << endl;
		}
		number++;
		getline(fin2, curStr);
	}

	cout << endl << endl;    //format the output  
	fin2.close();
	fin2.clear(ios::goodbit);


	//No.5
	cout << "No.5 " << endl << endl;
	
	string answer;
	bool state = true, //It's a flag loop
		 yes; //The answer
	cout << "Please input the answer: yes or no:"
		 << endl << "Tips: you can input "
		 << "\"yes\" or \"Yes\" or \"no\" or \"No\"."
		 << endl;
	cin >> answer;
	while (state)
	{
		if (answer == "yes" ||
			answer == "Yes")
		{
			state = false;
			yes = true;
		}

		else if (answer == "no" ||
			 	 answer == "No" )
		{
			state = false;
			yes = false;
		}
		else if (answer == "0")
			return 0;
		else
		{
			cout << "The answer is not proper--"
				 << "\n" << "please input it"
				 << " again:" << endl;
			cout << "(You can also input "
				 << "number 0 to exit the program.)"
				 << endl;
			cin >> answer;
		}
	}	

	
	//No.6
	cout << "No.6 " << endl << endl;
	
	cout << "This program outputs the calenda of "
		 << "November, 2013." << endl << endl;
	cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat"
		 << endl;
	int startDay,			//the day of Nov.1st 
		days,				//number of days of Nov.
		seven(7),			//7 days in a week
		num(1),				//the date
		date;				//the current date of num variable
	
	startDay = 5;			//represents for Fri.
	date = startDay;
	days = 30;				//represents for days of Nov.
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


	//No.7:
	//It is individually made in another program called 
	//"calenda 2013 (exercise 6, 7 in Chapter 6".

	
	//No.8 
	cout << endl << "No.8" << endl << endl;

	cout << "This program reads all characters "
		 << "from textData.txt and outputs "
		 << "the percentage of character \'z\'."
		 << endl;
	int count(0), countZ(0);		//to count all, z
	char ch;					    //the current char
	double result;					//the percentage
	
	//open file
	fin3.open("textData.txt");
	if (!fin1 || !fin2 || !fin3)
	{
		cout << "Can't open data." << endl;
		return 1;
	}

	//read procedure
	fin3.get(ch);
	while (fin3)					
	{
		if (ch == 'z')
			countZ++;
		count++;
		fin3.get(ch);
	}
	result = float(countZ) / float(count);
	cout << "The percentage is then: " << endl
		 << fixed << setprecision(8)
		 << 100 * result << "%\n"; 
	fin3.close();
	fin3.clear(ios::goodbit);

	
	/*
	//No.9 
	//It's almost the same as No.8 and we hide it.
	cout << endl << "No.9" << endl << endl;

	cout << "This program reads all characters "
		 << "or the first 10000 characters "
		 << "from textData.txt and outputs "
		 << "the percentage of character \'z\'."
		 << endl;
	count = 0, countZ = 0;			//reinitiallize all, z
	
	//open file
	fin3.open("textData.txt");
	if (!fin1 || !fin2 || !fin3)
	{
		cout << "Can't open data." << endl;
		return 1;
	}

	//read procedure
	fin3.get(ch);
	while (fin3 || count < 10000)	//for No.9's requirement
	{
		if (ch == 'z')
			countZ++;
		count++;
		fin3.get(ch);
	}
	result = float(countZ) / float(count);
	cout << countZ << ' ' << count << '\n';
	cout << "The percentage is then: " << endl
		 << fixed << setprecision(8)
		 << 100 * result << "%\n"; 
	fin3.close();
	fin3.clear(ios::goodbit);

    */

	
	//No.10
	cout << endl << "No.10 " << endl << endl;
	
	cout << "This program output the Fibonacci"
		 << " numbers less than 30,000." << endl
		 << "each number will be output on a seperate line."
		 << endl;

	//pre and cur loop 
	int one = 1,  //initialization 
		two = 1,  
		thr = 1;  //stands for three 
	
	cout << one << endl;

	while (thr < 30000)
	{
		cout << thr << endl;
		one = two; //update
		two = thr; //update
		thr = one + two;
	}
	

	//No.11
	cout << endl << "No.11 " << endl << endl;
	
	cout << "This program output Fibonacci numbers less than 30,000 in a form."
		 << endl;
	one = two = thr = 1;		//reinitialization
	count = 1;					//this time to count the fibonacci numbers
	
	cout << left << setw(5) << count << one << endl;
	count++;					//the first number "1".

	do
	{
		cout << setw(5) << count << thr << endl;
		one = two;
		two = thr;
		thr = one + two;
		count++;
	}	while (thr < 30000);


	//No.12
	cout << endl << "No.12 " << endl << endl;
	
	cout << "Please input a number which stands for "
		 << "the number of stars output in one row."
		 << endl;
	
	count = 1;
	cin >> num;
	state = true;
	
	//flag loop
	while (state)
	{
		if (!cin || num <= 0)
		{
			cout << "The number is not valid."
				 << endl << "Please re input again."
				 << endl;
		}
		else
			state = false;
	}

	//output loop
	cout << '*';
	while (count < num)
	{
		count++;
		cout << '*';
	}


	//or:
	/*
	while (count <= num)
	{
		cout << '*';
		count++;
	}
	*/
	cout << endl << endl;


	//No.14
	cout << endl << "No.14 " << endl << endl;
	
	fin4.open("indata.txt");
	if (!fin4)
	{
		cout << "Can't open data." << endl;
		return 1;
	}
	
	cout << "According to \"indata\", the lines of asterrisks will be:"
		 << endl;

	fin4 >> num;		//priming reading	
	do
	{
		for (int i(1); i <= num; i++)
		{
			cout << '*';
		}
		cout << endl;
		fin4 >> num;
	}	while (fin4);
	fin4.close();
	fin4.clear(ios::goodbit);


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
		


