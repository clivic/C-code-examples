/***************************************************************************************************************************************************
This program is a test to find if finding in a long sentense for an expression or a word and then outputting it is available.
And meanwhile another test to see if the length of a word can be replaced by an identifier to simplify the interface of the program.Let us see it..
***************************************************************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string::size_type pClivic ,pHappy ,pAhha,len;//define the position of the words of the string size
	string clivic;
	clivic = "Clivic";
	string aLongString="Hello my name is Clivic Thomas Ravel. Nice to meet you! I'm very happy to be here tonight... ahha!";
	len = clivic.length();//to measure the length of "Clivic"
	pClivic=aLongString.find("Clivic");//find the positon
	pHappy =aLongString.find("happy");
	pAhha = aLongString.find("ahha!");
	cout<< "The words we want to find is as following: "<<endl;
	cout<< aLongString.substr(pClivic,len)<<endl;//numbers stand to the length of the words we want to find
	cout<< aLongString.substr(pHappy,5)<<endl;
	cout<< aLongString.substr(pAhha,5)<<endl;
}