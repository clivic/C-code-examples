#include"hehe.h"
#include<iostream>
using namespace std;

void instructions();
int user_says_yes();

int main()   
{
	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations"<< endl;
	while (user_says_yes()){
		configuration.update();
		configuration.print();
		cout<<"Continue viewing new generations"<<endl;
	}
	return 0;
}

void instructions()
/*
pre:
post:
*/
{
cout << "welcome to 1-dimensional Life." << endl;
cout << "this game uses a grid of size "
     <<maxcol<<"in which"<<endl;
cout << "each cell can either be occupied by an organism or not ."<<endl;
cout << "the occupied cells change from generation to generation "<<endl;
cout << "according to the number of neighboring cells which are alive . "
     << endl;}

int  user_says_yes()
{
	int  c;
	int initial_response = 1 ;
	do{
		if (initial_response)
			cout << "(y,n)?" <<flush;
		else 
			cout << "Response with either y or n: " <<flush;
		do{
			c = cin.get();
		} while (c == '\n'|| c == ' ' || c == '\t');
		initial_response = 0 ;
	} while ( c != 'y' && c!='Y' && c !='n'&& c!= 'N');
	return (c == 'y'|| c == 'Y');
}
