#ifndef GAME_BUILDING_H
#define GAME_BUILDING_H

#include "State.h"
#include <string>

class CBuilding {
public:
	virtual void action(SState& current) = 0;
	virtual std::string getType() = 0;
}; 

class CFactory {
public:
	std::string type;
	virtual CBuilding* create(const clock_t& current) = 0;
};

#endif
