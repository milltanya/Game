#ifndef WORK
#define WORK
#include "Building.h"

class CWork : public CBuilding {
public:
	CWork();
	virtual void action(State& current);
private:
	clock_t prev_time;
	int level, action_time, action_cost;
};

class CWorkFactory : public CFactory {
public:
	CWorkFactory();
	CBuilding* create();
};


#endif
