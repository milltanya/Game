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

CCity::CCity() {}

CCity::CCity(int width, int height) {
	State = SCityState(width, height);	
	Factories.resize(3);
	Factories[0] = new CHouseFactory;
	Factories[1] = new CWorkFactory;
	Factories[2] = new CParkFactory;
	Parser = CParseAdapter(new CStringParse, width, height);
}

CCity::~CCity() {
	for (int i = 0; i < Factories.size(); ++i)
		delete Factories[i];
}

void CCity::Build(const std::string& t, const int y, const int x, const clock_t& current) {
	int i = 0;
	if (t != "Road") {
		while ((i < Factories.size()) && (t != Factories[i]->type))
			++i;
		if (i == Factories.size()) {
			std::cout << "Error! Wrong type of the building!" << std::endl;
			return;
		}
	}
	if ((y < 0) || (y >= State.Field.size()) || (x < 0) || (x >= State.Field[0].size())) {
		std::cout << "Error! Wrong coordinates!" << std::endl;
		return;
	}
	if (State.Field[y][x] != nullptr) {
		std::cout << "Error! There is an object!" << std::endl;
		return;
	}
	if (t != "House" && t != "Road" && !(((x > 0) && (State.Field[y][x - 1] != nullptr) && (State.Field[y][x - 1]->getType() == "Road")) ||
			((x < State.Field[0].size() - 1) && (State.Field[y][x + 1] != nullptr) && (State.Field[y][x + 1]->getType() == "Road")) ||
			((y > 0) && (State.Field[y - 1][x] != nullptr) && (State.Field[y - 1][x]->getType() == "Road")) ||
			((x < State.Field.size() - 1) && (State.Field[y + 1][x] != nullptr) && (State.Field[y + 1][x]->getType() == "Road")))) {
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
	if (parse.size() > 0 && parse[0].length() == 5 && parse[0] == "Build") {
		if (parse.size() == 4) {
			Build(parse[1], stoi(parse[2]), stoi(parse[3]), current);
		} else {
			std::cout << "Error! Wrong number of arguments" << std::endl;
		}
	}
	State.State.time = current;
	for (int i = 0; i < State.Field.size(); ++i) {
		for (int j = 0; j < State.Field[0].size(); ++j) {
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
    return CMemento(State);
}

void CCity::restoreState(CMemento memento) {
    State = memento.getState();
}
