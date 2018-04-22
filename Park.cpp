#include "Park.h"
#include <iostream>

CPark::CPark() {
	CPark(clock());
}

CPark::CPark(const clock_t& current) {
	prev_time = current;
	level = 1;
	action_time = 2;
}

std::string CPark::getType() {
	return "Park";
}

void CPark::action(State& current) {
	if ((current.time - prev_time) / CLOCKS_PER_SEC >= action_time) {
		current.happiness += level;
		prev_time = current.time;
	}
}

CParkFactory::CParkFactory() {
	type = "Park";
}

CBuilding* CParkFactory::create(const clock_t& current) {
	return new CPark(current);
}
