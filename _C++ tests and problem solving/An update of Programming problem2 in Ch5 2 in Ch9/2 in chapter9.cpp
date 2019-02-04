//*************************************************************************************************
//This is the third edition of the program "diffrent weight on different planets"
//using switch sentences.
//version 1.2.1
//*************************************************************************************************

#include <iostream>
#include <string>						//for input
#include <cctype>						//for input convenience

using namespace std;

//function prototype
double Result(double weight, string name);

int main()
{
	//prompts
	cout << "This program is to let you know how you weigh on the planet or other named asters "
		 << "in solar system." << endl << endl;
	cout << "Please input your weight of kilo first and then enter the exact name of the planet." << endl
		 << endl 
		 << "(Tips: there are 9 planets in solar system, and you can also input \"moon\"." << endl
		 << "And the first character should be capitalized.)" << endl << endl
		 << "You can enter \"q\" or \"Q\" to quit." << endl;
	
	//variables
	string name,						//name input
		   nameI;						//name initial
	double result,
		   weight;

	cin >> weight >> name;
	nameI = name;

	//to upper all characters for unity
	string::size_type i;				//for loop below
	
	while (cin)
	{
		for (i = 0; i < name.length(); i++)
		{
			name[i] = toupper(name[i]);
		}

		cout << "Your weight entered is " << weight << " kilograms," << endl;
		result = Result(weight, name);
		if (result - 0.0 <= 0.00001)
			cout << "Perhaps the planet you've entered hasn't been detected in solar system hah..." << endl
				 << "Please enter the name again." << endl << endl;
        else
			cout << "and you weigh on the " << nameI << "--" << endl
			 << result << " kilograms." << endl << endl;
		cout << "Please input your weight of kilo first and then enter the exact name of the planet." << endl;
		cin >> weight >> name;
		nameI = name;
	}
 
	cout << "Thank you for your using!" << endl;
	return 0;
}

//*************************************************************************************************
	
double Result(/* in */ double weight,
			  /* in */ string name)
/*	this function is to compute the result and the print of error message.
	Precondition:	name != "Q". 
	Postcondition:	weight corresponding to planets, and 0 for prompting invalid input.	 */

{
	unsigned int judge;					//for case statements 
	double result;						//for result
	if		(name == "MERCURY") judge = 1;
	else if (name == "VENUS")	judge = 2;
	else if (name == "EARTH")	judge = 0;
	else if (name == "MOON")	judge = 3;
	else if (name == "MARS")	judge = 4;
	else if (name == "JUPITER") judge = 5;
	else if (name == "SATURN")	judge = 6;
	else if (name == "URANUS")	judge = 7;
	else if (name == "NEPTUNE") judge = 8;
	else if (name == "PLUTO")	judge = 9;
	else						judge = 10;

	switch (judge)
	{
		case (1) : result = weight * 0.4155;	break;
		case (2) : result = weight * 0.8975;	break;
		case (0) : result = weight * 1.0000;	break;
		case (3) : result = weight * 0.1660;	break;
		case (4) : result = weight * 0.3507;	break;
		case (5) : result = weight * 2.5374;	break;
		case (6) : result = weight * 1.0677;	break;
		case (7) : result = weight * 0.8947;	break;
		case (8) : result = weight * 1.1794;	break;
		case (9) : result = weight * 0.0899;	break;
		case (10): return 0.0;					break;
	}
	return result;
}


	
