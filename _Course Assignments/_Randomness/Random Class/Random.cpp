//*******************************************************************
//	Random class implementation
//*******************************************************************
#include "Random.h"

Random::Random(/* in */ bool pseudo)
//	Post:	The values of seed, addon, and multiplier are
//			initialized.The seed is initialized randomly 
//			only if pseudo == false.
{
	addon = 5923;
	mutiplier = 2743;
	if (pseudo)
		seed = 1;
	else
		seed = time(NULL) % INT_MAX;
}

double Random::RandomReal()
//	Post:	A random real number between 0 and 1 is returned.
{
	double max = INT_MAX + 1.0;
	double set = (double)Generate();
	set = ((set >= 0) ? set : (set + max));
	return set / max;
}

int Random::RandomInt(
	/* in */ int low,
	/* in */ int high)
	//	Post:	A random integer between low and high is returned.
{
	if (high < low)	return RandomInt(high, low);
	return (int)((high - low + 1) * RandomReal()) + low;
}

int Random::Poisson(/* in */ double mean)
//	Post: A random integer, reflecting a Poisson distribution
//	with parameter mean, is returned.
{
	double limit = exp(-mean);
	double product = RandomReal();
	int count = 0;
	while (product > limit) 
	{
		count++;
		product *= RandomReal();
	}
	return count;
}

//*******************************************************************

int Random::Generate()
//	Post: The seed is replaced by a pseudorandom successor.
{
	seed *= mutiplier;
	seed += addon;
	return seed;
}