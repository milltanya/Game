#ifndef PARK
#define PARK
#include "Building.h"

class CPark : public CBuilding {
public:
	CPark();
	virtual void action(State& current);
	virtual std::string getType();
private:
	clock_t prev_time;
	int level, action_time;
};

class CParkFactory : public CFactory {
public:
	CParkFactory();
	CBuilding* create();
};


#endif
