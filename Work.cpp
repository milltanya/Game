#include "Work.h"
#include <ctime>
#include <string>

CWork::CWork() {
	///Конструктор по умолчанию
	prev_time = clock();
	level = 1;
	action_cost = 3;
	action_time = 2;
}

CWork::CWork(const clock_t& current) {
	///Конструктор по текущему моменту времени
	prev_time = current;
	level = 1;
	action_cost = 3;
	action_time = 2;
}

std::string CWork::getType() {
	///Возвращает тип здания
	return "Work";
}

void CWork::action(SState& current) {
	///Уменьшает счастье, увеличивает деньги и благополучие
	if (((current.time - prev_time) / CLOCKS_PER_SEC >= action_time) && (current.happiness >= action_cost)) {
		current.money += level;
		current.wealth += level;
		current.happiness -= action_cost;
		prev_time = current.time;
	}
}

CWorkFactory::CWorkFactory() {
	///Конструктор по умолчанию
	type = "Work";
}

CBuilding* CWorkFactory::create(const clock_t& current) {
	///Создание нового объекта класса CWork
	return new CWork(current);
}
