/************************************************
Format Names program
the program is to output various name format to a
file. For the little time, I have to omit the 
concrete comments here. We can consult them on 
P139 later.
************************************************/

#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("name.txt");
	fout.open("name.out");

	string socialNum, firstName, lastName;
	string middleName, initial;

	fin >> socialNum >> firstName >> middleName
		>> lastName;

	initial = middleName.substr(0,1) + '.';

	fout << "The required formats are: " << endl
		 << socialNum << endl;
	fout << "     " << firstName << ' '
		 << middleName << ' ' << lastName <<endl;
	fout << "     " << lastName << ", "
		 << firstName << ' ' << middleName<<endl;
	fout << "     " << lastName << ", "
		 << firstName << ' ' << initial << endl;
	fout << "     " << firstName << ' '
		 << initial << endl;
}