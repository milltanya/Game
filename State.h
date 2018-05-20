#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <ctime>

struct SState
{
	clock_t time;
	int money, population, wealth, happiness;
	SState();
	SState(int m, int p, int w, int h);
};

#endif
