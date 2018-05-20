#ifndef GAME_STRATEGY_H
#define GAME_STRATEGY_H

#include "Building.h"
#include "House.h"
#include "Work.h"
#include "Park.h"

class Context
{
protected:
	CBuilding* operation;
public:
	virtual void useStrategy(SState& current) = 0;
	virtual void setStrategy(CBuilding* v) = 0;
};

class Client: public Context
{
public:
	void useStrategy(SState& current) override;
	void setStrategy(CBuilding* o) override;
};

#endif