#ifndef WORK
#define WORK
#include "Building.h"

class CWork : public CBuilding {
public:
	CWork();
	CWork(const clock_t& current);
	virtual void action(State& current);
	virtual std::string getType();
private:
	clock_t prev_time;
	int level, action_time, action_cost;
};

class CWorkFactory : public CFactory {
public:
	CWorkFactory();
	CBuilding* create(const clock_t& current);
};


#endif
