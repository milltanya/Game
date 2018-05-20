#ifndef GAME_ROAD_H
#define GAME_ROAD_H
#include "Building.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class CRoad : public CBuilding {
private:
	CRoad();
	void action(SState& current) override;
	std::string getType() override;
public:
	static CBuilding& getInstance();
};

#endif