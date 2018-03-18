#include "House.h"
#include <iostream>

CHouse::CHouse() {
	symbol = 'H';
	prev_time = clock();
	level = 1;
	action_cost = 3;
	action_time = 2;
}

void CHouse::action(State& current) {
	if (((current.time - prev_time) / CLOCKS_PER_SEC >= action_time) && (current.wealth >= action_cost)) {
		current.population += level;
		current.wealth -= action_cost;
		std::cout << "New people were born. Population increase = " << level << std::endl;
		prev_time = current.time;
	}
}

CHouseFactory::CHouseFactory() {
	type = "House";
}

CBuilding* CHouseFactory::create() {
	return new CHouse;
}