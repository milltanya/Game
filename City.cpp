#include "City.h"

#include "House.h"
#include "Work.h"
#include "Park.h"
#include "Road.h"
#include "Strategy.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

CCity::CCity() {
	State = SCityState(0, 0);
	Factories = nullptr;
}

CCity::CCity(int x, int y) {
	State = SCityState(x, y);	
	Factories = new CFactory*[3];
	Factories[0] = new CHouseFactory;
	Factories[1] = new CWorkFactory;
	Factories[2] = new CParkFactory;
	Parser = CParseAdapter(new CStringParse, x, y);
}

CCity::~CCity() {
	for (int i = 0; i < 3; ++i) {
		if (Factories[i] != nullptr) {
			delete Factories[i];
		}
	}
	delete Factories;
}

void CCity::Build(const std::string& t, const int y, const int x, const clock_t& current) {
	int i = 0;
	if (t != "Road") {
		while ((i < 3) && (t != Factories[i]->type))
			++i;
		if (i == 3) {
			std::cout << "Error! Wrong type of the building!" << std::endl;
			return;
		}
	}
	if ((y < 0) || (y >= State.height) || (x < 0) || (x >= State.width)) {
		std::cout << "Error! Wrong coordinates!" << std::endl;
		return;
	}
	if (State.Field[y][x] != nullptr) {
		std::cout << "Error! There is an object!" << std::endl;
		return;
	}
	if (t != "House" && t != "Road" && !(((x > 0) && (State.Field[y][x - 1] != nullptr) && (State.Field[y][x - 1]->getType() == "Road")) ||
			((x < State.width - 1) && (State.Field[y][x + 1] != nullptr) && (State.Field[y][x + 1]->getType() == "Road")) ||
			((y > 0) && (State.Field[y - 1][x] != nullptr) && (State.Field[y - 1][x]->getType() == "Road")) ||
			((x < State.height - 1) && (State.Field[y + 1][x] != nullptr) && (State.Field[y + 1][x]->getType() == "Road")))) {
		std::cout << "Error! There is no road nearby!" << std::endl;
		return;
	}
	if (t == "Road") {
		State.Field[y][x] = &CRoad::getInstance();
	}
	else {
		State.Field[y][x] = Factories[i]->create(current);
	}
}

void CCity::Check(const std::string& s, const clock_t& current) {
	std::vector<std::string> parse = Parser.parse(s);
	for (int i = 0; i < parse.size(); ++i)
		std::cout << parse[i] << std::endl;
	if (parse.size() > 0 && parse[0].length() == 5 && parse[0] == "Build") {
		if (parse.size() == 4) {
			Build(parse[1], stoi(parse[2]), stoi(parse[3]), current);
		} else {
			std::cout << "Error! Wrong number of arguments" << std::endl;
		}
	}
	State.State.time = current;
	for (int i = 0; i < State.height; ++i) {
		for (int j = 0; j < State.width; ++j) {
			if (State.Field[i][j] != nullptr) {
				customClient.setStrategy(State.Field[i][j]);
				customClient.useStrategy(State.State);
			}
		}
	}
}

SCityState CCity::getState() {
    return State;
}

CMemento CCity::saveState() {
    return *new CMemento(State);
}

void CCity::restoreState(CMemento memento) {
    State = memento.getState();
}
