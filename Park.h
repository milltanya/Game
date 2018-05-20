#ifndef GAME_PARK_H
#define GAME_PARK_H
#include "Building.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class CPark : public CBuilding {
public:
	CPark();
	explicit CPark(const clock_t& current);
	void action(SState& current) override;
	std::string getType() override;
private:
	clock_t prev_time;
	int level, action_time;
};

class CParkFactory : public CFactory {
public:
	CParkFactory();
	CBuilding* create(const clock_t& current) override;
};


#endif
