#ifndef ROAD
#define ROAD
#include "Building.h"

class CRoad : public CBuilding {
private:
	CRoad();
	virtual void action(State& current);
public:
	static CBuilding& getInstance();
};

#endif