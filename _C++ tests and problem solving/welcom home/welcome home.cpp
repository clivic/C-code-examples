/************************************************
This programe output a "welcoming home" message
************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//asterisks
//this function is to output asterisks,
//It's parametre is given by number of lines
void Asterisks(int line)
{
	int count(1);
	while (count <= line)
	{
		cout << "*******************************"
			 << endl;
		count++;
	}
}

//***********************************************

int main()
{
	string asterisk;
	Asterisks(2);
	asterisk = "*******************************";
	cout << setw(asterisk.length() - 10)
		 << "Welcome home!" << endl;
	Asterisks(4);
	return 0;
}


/*Infact, a funtion could havn't had function
prototype, as long as it is put ahead of its 
caller. And it can also have a lot of prototypes.
*/