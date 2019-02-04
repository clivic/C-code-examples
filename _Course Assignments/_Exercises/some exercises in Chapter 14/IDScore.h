//*************************************************************************************************
//This class expand TestScore class and stores students' name, score and ID
//*************************************************************************************************
#ifndef ID_H
#define ID_H
#include <string>
#include <iostream>
#include "TestScore.h"

using namespace std;

class IDScore : public TestScore
{
public:
	IDScore();
	IDScore(
		/* in */ string name,
		/* in */ int score,
		/* in */ int ID);
	int GetID() const;
private:
	int IDnumber;
};

#endif