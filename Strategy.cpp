#include "Strategy.h"

void Client::useStrategy(SState& current) {
	///Вызывает действие у объекта operation
	operation->action(current);
}

void Client::setStrategy(CBuilding* o) {
	///Задает объект operation
	operation = o;
}