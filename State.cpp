#include "State.h"

SState::SState() {
	time = clock();
	money = 0;
	population = 0;
	wealth = 0;
	happiness = 0;
}
	
SState::SState(int m, int p, int w, int h) {
	time = clock();
	money = m;
	population = p;
	wealth = w;
	happiness = h;
}