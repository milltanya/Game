#ifndef GAME_CITYSTATE_H
#define GAME_CITYSTATE_H

#include "Building.h"
#include <vector>

struct SCityState {
	std::vector<std::vector<CBuilding*>> Field;
	SState State;
	SCityState(const SCityState& s);
	SCityState();
	SCityState(int w, int h);
	~SCityState();
};

#endif