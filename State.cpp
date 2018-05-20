#include "State.h"

SState::SState() {
	/// онструктор по умолчанию
	time = clock();
	money = 0;
	population = 0;
	wealth = 0;
	happiness = 0;
}

SState::SState(const SState& s) {
	/// онструктор копировани€
	time = s.time;
	money = s.money;
	population = s.population;
	wealth = s.wealth;
	happiness = s.happiness;
}
	
SState::SState(int m, int p, int w, int h) {
	/// онструктор по данным значени€м денег, населени€, благополучи€ и счасть€
	time = clock();
	money = m;
	population = p;
	wealth = w;
	happiness = h;
}