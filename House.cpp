#include "House.h"
#include <iostream>

CHouse::CHouse() {
	prev_time = clock();
	level = 1;
	action_cost = 3;
	action_time = 2;
}

std::string CHouse::getType() {
	return "House";
}

void CHouse::action(State& current) {
	if (((current.time - prev_time) / CLOCKS_PER_SEC >= action_time) && (current.wealth >= action_cost)) {
		current.population += level;
		current.wealth -= action_cost;
		prev_time = current.time;
	}
}

CHouseFactory::CHouseFactory() {
	type = "House";
}

CBuilding* CHouseFactory::create() {
	return new CHouse;
}
