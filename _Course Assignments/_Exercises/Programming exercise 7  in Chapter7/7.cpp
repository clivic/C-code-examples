//**************************************************************
//This program is difficult perhaps!
//**************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Function prototypes
void Compare(string key, string& number,
			 string answer, int& count);


//Related to file
ifstream fin;
ofstream fout;
		
void Compare(/* in */ string key,
		     /* inout */ string& number,
		     /* inout */ string answer,
			 /* inout */ int& count)
{
	//judge length
	if (key.length() < answer.length())
	{
		fout << number << '\t' << "Too many answers"
			 << endl;
		return;
	}
	
	else if (key.length() > answer.length())
	{
		fout << number << '\t' << "Too few answers"
			 << endl;
		return;
	}

	//compare
	string currentChK;      //Current char of key
	string currentChA;      //Current char of answer
	int countS(0);			//while's condition

	currentChK = key.substr(countS,1);
	currentChA = answer.substr(countS,1);

	while (countS < answer.length())
	{

		if (currentChA != "a" &&
			currentChA != "b" &&
			currentChA != "c" &&
			currentChA != "d" &&
			currentChA != "e" &&
			currentChA != "f")  
			
			//judge validity
			{
				fout << number << '\t' << "Invalid Answers"
					 << endl;
				return;
			}

		if (currentChK == currentChA)
			{
				count++;
			}
		
		countS++;
		currentChK = key.substr(countS,1);
		currentChA = answer.substr(countS,1);
	}
	
		fout << number << '\t' << count << endl;
		
}
	



int main()
{
	string key;

	//input file
	fin.open("exams.dat");
	fout.open("scores.dat");
	if (!fin)
	{
		fout << "Can't open data." << endl;
		return 1;
	}
	
	
		

	//read key
	fin >> key;
	string number;         //Students ID
	string answer;		   //Studnets' answer
		
	fin >> number >> answer;

	
	//Reading process
	while (fin)
	{
		int count(0);	   //count for objective answers
		Compare(key, number, answer, count);
		fin >> number >> answer;
		
	}
	fin.close();
	fout.close();
	cout << "Result has been stored succesfully!" << endl;

	return 0;
}
		



