#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin;
void TestInput();                 //to verify the input is valid

//definition of TestInput()
void TestInput()
{
	if (!fin)
	{
		cout << "Can't open data." << endl;
		return;
	}
}

//main function
int main()
{
	//No.4
	//This program is to judge if the sentence input by user is a palindrome. 

	cout << "No.4" << endl << endl;
	
	cout << "Palindrome" << endl
		 << "Please enter a sentence, and we judge if it is a palindrome. " << endl;
	
	string sen = "";			 //sentence definition
	string rSen = "";			 //reversed-sentence definition
	string a;					 //every character definition
	int i(0);                    //counter definition
	
	getline(cin, sen);

	while (i <= sen.length() - 1)
	{
		a = sen.substr(i, 1);
		rSen = a + rSen;
		i++;
	}
	cout << "You've entered string: " << sen << endl;
	cout << "And the reversed string is: " << rSen << endl;
	if (sen == rSen)
		cout << "And it is a palindrome." << endl << endl;
	else
		cout << "And it is not a palindrome." << endl << endl;


	
	//test for char + string
	cout << "This mini program tests if char could be concatenated to string value."
		 << endl;
	char k = 'a';
	string str1 = "bc";
	string str2 = "";
	cout << k + str1 << endl; //directly cout the result
	str2 = k + str1;		  
	cout << str2 << endl;	  //cout by the median variable
	cout << "The result is: \"yes\"!" << endl << endl;

	//result: both are available!

	//No.5
	//this program find the email address. 
	cout << "No.4" << endl << endl;

	cout << "This program find the email address from the \"mail.dat\"." << endl
		 << "And it will be stored in file addresses.dat." << endl;
	
	//files in
	fin.open("mail.dat");
	TestInput();      
	string current;                 //The string to judge if contains @
	fin >> current;
	while (fin)
	{
		if (current.find('@') != string::npos)
		{
			cout << current << endl;
		}
	
		fin >> current;
	}
	
	
	
	
	
	return 0;

}

















//The following codes are not available.

/*
	cin.get(a);
	while (cin)
	{
		sen = sen + a;
		rSen = a + rSen; 
		cin.get(a);
	}
	cout << "You've entered string: " << sen << endl;
	cout << "And the reversed string is: " << rSen << endl;
	if (sen == rSen)
		cout << "And it is a palindrome." << endl;
	else
		cout << "And it is not a palindrome." << endl;
	*/