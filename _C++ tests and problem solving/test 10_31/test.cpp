/************************************************
Problem A 10/31
************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	//input data from file
	ifstream fin;
	fin.open("input.txt");
	if (!fin)
	{
		cout << "Can't open data." << endl;
		return 1;
	}
	
	char l = 'l';
	char L = 'L';
	char r = 'r';
	char R = 'R';
	char current;
	int nownum;
	int num;		//number of lines
	int count(1);   //count line
	int totalL(0);		//total left
	int totalR(0);		//total right
	fin >> num;

	while (count <= num)
	{
		fin >> current;
		if (current == l ||
			current == L)
		{
			fin >> nownum;
			totalL = totalL + nownum;
		}
		else if (current == r ||
				 current == R)
		{
			fin >> nownum;
			totalR = totalR + nownum;
		}
		count++;
	}

	cout << "Total left is: " << totalL << endl;
	cout << "Total right is: " << totalR;
	return 0;
}
