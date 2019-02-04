#ifndef EXAM_H
#define EXAM_H
#include "IDScore.h"
#include <string>

using namespace std;

const int ARRAYLENGTH = 100;
class Exam
{
private:
	IDScore marks[ARRAYLENGTH];
public:
	Exam();
	void Set(
		/* in */ IDScore student,
		/* in */ int position);
	IDScore GetMark(/* in */ int position) const;
};

#endif