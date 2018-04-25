#include "House.h"
#include <ctime>
#include <string>

CHouse::CHouse() {
	prev_time = clock();
	level = 1;
	action_cost = 3;
	action_time = 2;
}

CHouse::CHouse(const clock_t& current) {
	prev_time = current;
	level = 1;
	action_cost = 3;
	action_time = 2;
}

std::string CHouse::getType() {
	return "House";
}

void CHouse::action(State& current) {
	if (((current.time - prev_time) >= CLOCKS_PER_SEC*action_time) && (current.wealth >= action_cost)) {
		current.population += level;
		current.wealth -= action_cost;
		prev_time = current.time;
	}
}

CHouseFactory::CHouseFactory() {
	type = "House";
}

CBuilding* CHouseFactory::create(const clock_t& current) {
	return new CHouse(current);
}
