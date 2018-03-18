#ifndef HOUSE
#define HOUSE
#include "Building.h"

class CHouse : public CBuilding {
public:
	CHouse();
	virtual void action(State& current);
private:
	clock_t prev_time;
	int level, action_time, action_cost;
};

class CHouseFactory : public CFactory {
public:
	CHouseFactory();
	CBuilding* create();
};


#endif
