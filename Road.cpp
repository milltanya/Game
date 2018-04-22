#include "Road.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

CRoad::CRoad() {
}

void CRoad::action(State& current) {}

CBuilding& CRoad::getInstance() {
	static CRoad instance;
	return instance;
}

std::string CRoad::getType() {
	return "Road";
}