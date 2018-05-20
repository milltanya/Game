#ifndef GAME_WORK_H
#define GAME_WORK_H
#include "Building.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class CWork : public CBuilding {
public:
	CWork();
	explicit CWork(const clock_t& current);
	void action(SState& current) override;
	std::string getType() override;
private:
	clock_t prev_time;
	int level, action_time, action_cost;
};

class CWorkFactory : public CFactory {
public:
	CWorkFactory();
	CBuilding* create(const clock_t& current) override;
};


#endif
