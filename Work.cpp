#include "Work.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

CWork::CWork() {
	CWork(clock());
}

CWork::CWork(const clock_t& current) {
	prev_time = current;
	level = 1;
	action_cost = 3;
	action_time = 2;
}

std::string CWork::getType() {
	return "Work";
}

void CWork::action(State& current) {
	if (((current.time - prev_time) / CLOCKS_PER_SEC >= action_time) && (current.happiness >= action_cost)) {
		current.money += level;
		current.wealth += level;
		current.happiness -= action_cost;
		prev_time = current.time;
	}
}

CWorkFactory::CWorkFactory() {
	type = "Work";
}

CBuilding* CWorkFactory::create(const clock_t& current) {
	return new CWork(current);
}
