#ifndef ROAD
#define ROAD
#include "Building.h"

class CRoad : public CBuilding {
private:
	CRoad();
	virtual void action(State& current);
	virtual std::string getType();
public:
	static CBuilding& getInstance();
};

#endif