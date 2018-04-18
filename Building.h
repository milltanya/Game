#ifndef BUILDING
#define BUILDING

#include <ctime>
#include <string>

struct State
{
	clock_t time;
	int money, population, wealth, happiness;
};

class CBuilding {
public:
	CBuilding() {}
	virtual ~CBuilding() {}
	virtual void action(State& current) = 0;
	virtual std::string getType() = 0;
}; 

class CFactory {
public:
	std::string type;
	virtual CBuilding* create() = 0;
	virtual ~CFactory() { }
};

#endif
