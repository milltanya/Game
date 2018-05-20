#include "House.h"
#include <ctime>
#include <string>

CHouse::CHouse() {
	///Конструктор по умолчанию
	prev_time = clock();
	level = 1;
	action_cost = 3;
	action_time = 2;
}

CHouse::CHouse(const clock_t& current) {
	///Конструктор по текущему моменту времени
	prev_time = current;
	level = 1;
	action_cost = 3;
	action_time = 2;
}

std::string CHouse::getType() {
	///Возвращает тип здания
	return "House";
}

void CHouse::action(SState& current) {
	///Увеличивает количество населения
	if (((current.time - prev_time) >= CLOCKS_PER_SEC*action_time) && (current.wealth >= action_cost)) {
		current.population += level;
		current.wealth -= action_cost;
		prev_time = current.time;
	}
}

CHouseFactory::CHouseFactory() {
	///Конструктор по умолчанию
	type = "House";
}

CBuilding* CHouseFactory::create(const clock_t& current) {
	///Создание нового объекта класса CHouse
	return new CHouse(current);
}
