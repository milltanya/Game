#ifndef GAME_CITYSTATE_H
#define GAME_CITYSTATE_H

#include "Building.h"

struct SCityState {
	CBuilding*** Field;
	int width, height;
	SState State;
	SCityState();
	SCityState(int w, int h);
	~SCityState();
};

#endif GAME_CITYSTATE_H