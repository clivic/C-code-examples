//*******************************************************************
//	Random class specification
//*******************************************************************
#ifndef RAND
#define RAND
#include <cmath>
#include <limits>
#include <time.h>

using namespace std;

class Random
{
public:
	Random(/* in */ bool pseudo = true);
	double RandomReal();
	int RandomInt(
		/* in */ int low,
		/* in */ int high);
	int Poisson(/* in */ double mean);
private:
	int seed;
	int mutiplier;
	int addon;
	int Generate();
};

#endif