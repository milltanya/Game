#ifndef CITY
#define CITY

#include <string>
#include <vector>
#include <ctime>
#include "Building.h"

void strtoint(std::string& s, int& x, int& y);

class CCity
{
private:
	CBuilding*** Field;
	CFactory** Factories;
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
