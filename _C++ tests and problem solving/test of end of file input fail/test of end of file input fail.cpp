/************************************************
This program is to test what if end-of-file 
state happen, and even in a loop environment.
************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "We read in a entire line in a file"
		 << " \"line\"." << endl;
	ifstream fin;
	fin.open("line.txt");
	char input;
	//Test of non-objective situation.
	if (!fin)
	{
		cout << "The input file isn't objective."
			 << endl;
		return 1;
	}
	
	//While loop
	fin.get(input);
	while (input != '\n')
	{
		cout << input;
		fin.get(input);
	}

	cout << endl << "Reading is over!" << endl;
	return 0;
}

//For in the txt"line", there hasn't been a new-line
//character typed in the end of the line--
//So it seems failed the it becomes infinite loop.
//And in the fail state it will infinitely output
//the last character.