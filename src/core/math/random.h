#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <cstdlib>
#include <ctime>

class Random {
public:
	Random (size_t seed)
	{
		srand(seed);
	}
	Random ()
	{
		srand(time(nullptr));
	}

	virtual ~Random ()
	{

	}

	int get(int min, int max)
	{
		int rd =min+rand()%(max-min+1);
		return rd;
	}

private:

};


#endif
