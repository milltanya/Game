#include "Work.h"
#include <iostream>

CWork::CWork() {
	prev_time = clock();
	level = 1;
	action_cost = 3;
	action_time = 2;
	symbol = 'W';
}

void CWork::action(State& current) {
	if (((current.time - prev_time) / CLOCKS_PER_SEC >= action_time) && (current.happiness >= action_cost)) {
		current.money += level;
		current.wealth += level;
		current.happiness -= action_cost;
		std::cout << "New taxes were collected. Money increase = " << level << std::endl;
		prev_time = current.time;
	}
}

CWorkFactory::CWorkFactory() {
	type = "Work";
}

CBuilding* CWorkFactory::create() {
	return new CWork;
}