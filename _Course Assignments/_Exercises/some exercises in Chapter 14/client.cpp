//*************************************************************************************************
//This is the driver tests the three classes.
//*************************************************************************************************
#include "Exam.h"
#include "IDScore.h"
#include "TestScore.h"
//#include <iostream>

using namespace std;

void main()
{
	string name;
	int score;
	int ID;

	//test for "Testscore"
	cout << "test for \"Testscore\" " << endl;
	cout << "Please enter studnets' name and score: \n";
	cin >> name >> score;
	TestScore studnetOrigin1(name, score);
	cout << "studnetOrigin1:	" 
		 << studnetOrigin1.GetName() << '\t' 
		 << studnetOrigin1.GetScore() << endl;

	//test for "IDscore.h"
	cout << "test for \"IDscore\"" << endl;
	cout << "Please enter studnets' name, score and ID: \n";
	cin >> name >> score >> ID;
	IDScore studnet1(name, score, ID);
	cout << "studnet1:	" 
		 << studnet1.GetName() << '\t' 
		 << studnet1.GetScore() << '\t' 
		 << studnet1.GetID() << endl;

	//test for "Exam.h"
	cout << "test for \"Exam.h\"" << endl;
	Exam sei2013;
	sei2013.Set(studnet1, 0);
	cout << sei2013.GetMark
}