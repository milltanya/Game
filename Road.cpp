﻿#include "Road.h"
#include <ctime>
#include <string>

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