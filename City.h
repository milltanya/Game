#ifndef GAME_CITY_H
#define GAME_CITY_H

#include <ctime>
#include <string>
#include <vector>
#include "Building.h"
#include "ParserAdapter.h"
#include "Strategy.h"
#include "CityState.h"
#include "Memento.h"

class CCity
{
private:
	SCityState State;
	std::vector<CFactory*> Factories;
	CParseAdapter Parser;
	void Build(const std::string& s, const int x, const int y, const clock_t& current);
	Client customClient;
	friend class CCityDecorator;
public:
	CCity();
	CCity(int x, int y);
	virtual ~CCity();
	virtual void Check(const std::string& s, const clock_t& current);
	SCityState getState();
    CMemento saveState();
    void restoreState(CMemento m);
};

#endif
