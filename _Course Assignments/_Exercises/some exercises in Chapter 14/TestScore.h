//*************************************************************************************************
//This class stores students' name and score
//*************************************************************************************************
#ifndef TS_H
#define TS_H
#include <string>

using namespace std;

class TestScore
{
public:
	TestScore();
	TestScore(
		/* in */ string name,
		/* in */ int score);
	string GetName() const;
	int GetScore() const;
private:
	string studentName;
	int studentScore;
};

#endif