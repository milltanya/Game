#ifndef GAME_CITY_H
#define GAME_CITY_H

#include <ctime>
#include <string>
#include "Building.h"
#include "ParserAdapter.h"
#include "Strategy.h"
#include "CityState.h"
#include "Memento.cpp"

class CCity
{
private:
	SCityState State;
	CFactory** Factories;
	CParseAdapter Parser;
	friend void draw(CCity* City);
	void Build(const std::string& s, const int x, const int y, const clock_t& current);
	Client customClient;
public:
	CCity();
	CCity(int x, int y);
	virtual ~CCity();
	virtual void Check(const std::string& s, const clock_t& current);
	SCityState getState();
    CMemento saveState();
    void restoreState(CMemento memento);
};

#endif
