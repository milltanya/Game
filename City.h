#ifndef CITY
#define CITY

#include <string>
#include <vector>
#include <ctime>
#include "Building.h"

void strtoint(const std::string& s, int& x, int& y);

class CCity
{
private:
	CBuilding*** Field;
	CFactory** Factories;
	int width, height;
	State City_State;
	friend void draw(const CCity& City);
	void Build(const std::string& s, const int x, const int y);
public:
	CCity(int x, int y);
	~CCity();
	void Check(const std::string& s, const clock_t& current);
};

#endif
