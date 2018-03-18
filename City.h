#ifndef CITY_
#define CITY_

#include <string>
#include <vector>
#include <ctime>
#include "Building.h"

void strtoint(std::string& s, int& x, int& y);

class CCity
{
private:
	std::vector<std::vector<CBuilding*> > Field;
	std::vector<CFactory*> Factories;
	int width, height;
	State City_State;
public:
	CCity(int x, int y);
	~CCity();
	void print();
	void Check(clock_t current);
	void Build();
	void AddRoad();
};

#endif
