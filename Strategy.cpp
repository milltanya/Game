#include "Strategy.h"

void Client::useStrategy(SState& current) {
	operation->action(current);
}

void Client::setStrategy(CBuilding* o) {
	operation = o;
}