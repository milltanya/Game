#include "State.h"

SState::SState() {
	time = clock();
	money = 0;
	population = 0;
	wealth = 0;
	happiness = 0;
}

SState::SState(const SState& s) {
	time = s.time;
	money = s.money;
	population = s.population;
	wealth = s.wealth;
	happiness = s.happiness;
}
	
SState::SState(int m, int p, int w, int h) {
	time = clock();
	money = m;
	population = p;
	wealth = w;
	happiness = h;
}