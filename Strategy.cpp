#include "Strategy.h"

void Client::useStrategy(SState& current) {
	///�������� �������� � ������� operation
	operation->action(current);
}

void Client::setStrategy(CBuilding* o) {
	///������ ������ operation
	operation = o;
}