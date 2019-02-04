//*************************************************************************************************
//All implementations of class TestScore, IDScore, Exam
//*************************************************************************************************
#include "TestScore.h"
#include "IDScore.h"
#include "Exam.h"
#include <iostream>

using namespace std;

//1,2,3 problems

//TestScore implementation
TestScore::TestScore()
{
	studentName = "No student";
	studentScore = 100;
}
TestScore::TestScore(/* in */ string name,
					 /* in */ int score)
{
	studentName = name;
	studentScore = score;
}

string TestScore::GetName() const
{
	return studentName;
}

int TestScore::GetScore() const
{
	return studentScore;
}

//IDScore implementation
IDScore::IDScore()
{
}
IDScore::IDScore(/* in */ string name,
				 /* in */ int score,
				 /* in */ int ID)
	: TestScore(name, score)
{
	IDnumber = ID;
}

int IDScore::GetID() const
{
	return IDnumber;
}

//*************************************************************************************************

//4,5 problems

//Exam implementation
Exam::Exam()
{
}

void Exam::Set(
			/* in */ IDScore student,
			/* in */ int position)
{
	marks[position] = student;
}

IDScore Exam::GetMark(/* in */ int position) const
{
	return marks[position];
}

