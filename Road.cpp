#include "Road.h"
#include <ctime>
#include <string>

CRoad::CRoad() {}

void CRoad::action(SState& current) {}

CBuilding& CRoad::getInstance() {
	///Возвращает указатель на объект CRoad
	static CRoad instance;
	return instance;
}

std::string CRoad::getType() {
	///Возвращает тип здания
	return "Road";
}