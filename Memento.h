#ifndef GAME_MEMENTO_H
#define GAME_MEMENTO_H

#include "CityState.h"

class CMemento {
private:
	SCityState state;
public:
	CMemento();
	CMemento(SCityState s);
    SCityState getState();
};

class CCaretaker {
private:
	CMemento memento;
public:
	CCaretaker(CMemento m);
	CMemento getMemento();
	void setMemento(CMemento m);
};

#endif