#ifndef CITY
#define CITY

#include <string>
#include <vector>
#include <ctime>
#include "Building.h"
#include "ParserAdapter.h"

class CCity
{
private:
	CBuilding*** Field;
	CFactory** Factories;
	int width, height;
	State City_State;
	CParseAdapter Parser(nullptr, 0, 0);
	friend void draw(CCity* City);
	void Build(const std::string& s, const int x, const int y, const clock_t& current);
public:
	CCity();
	CCity(int x, int y);
	~CCity();
	void Check(const std::string& s, const clock_t& current);
};

#endif
