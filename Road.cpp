#include "Road.h"
#include <iostream>

CRoad::CRoad() {
	symbol = 'R';
}

void CRoad::action(State& current) {}

CBuilding& CRoad::getInstance() {
	static CRoad instance;
	return instance;
}