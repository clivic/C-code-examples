/*******************************************************************************************************************************************
This program is intended to test how "cin" operates, by inputting different data to see what will be proved.
*******************************************************************************************************************************************/

#include <iostream>

using namespace std;

void main()
{
	int a,b,c;
	float x;
	char ch;
	cout<<"Please input int a, char ch and intc: "<<endl;
	cin>>a>>ch>>c;
	cout<<a<<"\t"<<ch<<"\t"<<c<<endl;

}
//It proves that :
//1.you can only input 1 char to store in char. For example, 2Q6 is the same as 2 Q 6.
//2.what you put in is a "char", not an ASCII code. so when you store 5 into a variable, you get "5", not an "Enquiry" :) !