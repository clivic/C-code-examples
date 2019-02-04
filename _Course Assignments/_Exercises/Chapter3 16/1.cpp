#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//constant
const string str1="you ought to start with logic";
const string str2="ou";

//the main function
void main()
{
	cout<<"The length of string1 is: "<<str1.length()<<endl;
	cout<<"The position of string2 in string1 is: "<<str1.find(str2)<<endl;
	cout<<"The substring in string1 for lenth of 25 beginning from the fifth character is: "<<str1.substr(4,25)<<endl;
	cout<<"The position of string2 in the above substring is: "<<str1.substr(4,25).find(str2)<<endl;
	cout<<"The substring in string1 for lenth of 3 beginning from character\"l\" is: "<<str1.substr(str1.find("logic"),3)<<endl;
	cout<<"The position of string2's 1-char sbustring in string1's 5-char substring beginning at 25th character is: "
		<<str1.substr(24,5).find(str2.substr(0,1))<<endl;
	cout<<"The postion of \"end\" in string1 is: "<<str1.find("end")<<endl;
}
/* The experinence:
	1.using function"find", you should find a "string" type, so when using literal string, you should use "" .
	2.the fuction name is substr(), not substring().*/