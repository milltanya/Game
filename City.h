#ifndef GAME_CITY_H
#define GAME_CITY_H

#include <ctime>
#include <string>
#include "Building.h"
#include "ParserAdapter.h"

class CCity
{
private:
	CBuilding*** Field;
	CFactory** Factories;
	int width, height;
	State City_State;
	CParseAdapter Parser;
	friend void draw(CCity* City);
	void Build(const std::string& s, const int x, const int y, const clock_t& current);
public:
	CCity();
	CCity(int x, int y);
	virtual ~CCity();
	virtual void Check(const std::string& s, const clock_t& current);
};

#endif
