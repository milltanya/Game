#ifndef GAME_HOUSE_H
#define GAME_HOUSE_H
#include "Building.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class CHouse : public CBuilding {
public:
	CHouse();
	explicit CHouse(const clock_t& current);
	void action(State& current) override;
	std::string getType() override;
private:
	clock_t prev_time;
	int level, action_time, action_cost;
};

class CHouseFactory : public CFactory {
public:
	CHouseFactory();
	CBuilding* create(const clock_t& current) override;
};


#endif
