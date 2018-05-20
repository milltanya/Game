#include "Park.h"
#include <ctime>
#include <string>

CPark::CPark() {
	///Конструктор по умолчанию
	prev_time = clock();
	level = 1;
	action_time = 2;
}

CPark::CPark(const clock_t& current) {
	///Конструктор по текущему моменту времени
	prev_time = current;
	level = 1;
	action_time = 2;
}

std::string CPark::getType() {
	///Возвращает тип здания
	return "Park";
}

void CPark::action(SState& current) {
	///Увеличивает счастье
	if ((current.time - prev_time) / CLOCKS_PER_SEC >= action_time) {
		current.happiness += level;
		prev_time = current.time;
	}
}

CParkFactory::CParkFactory() {
	///Конструктор по умолчанию
	type = "Park";
}

CBuilding* CParkFactory::create(const clock_t& current) {
	///Создание нового объекта класса CPark
	return new CPark(current);
}
