#include "City.h"

#include "House.h"
#include "Work.h"
#include "Park.h"
#include "Road.h"
#include "Parser.h"
#include "ParserAdapter.h"
#include <iostream>
#include <string>

CCity::CCity() {
	width = 0;
	height = 0;
	Field = nullptr;
	City_State.time = 0;
	City_State.money = 0;
	City_State.population = 0;
	City_State.wealth = 0;
	City_State.happiness = 0;
	Factories = nullptr;
	Parser = CParseAdapter(new CStringParse, width, height);
}

CCity::CCity(int x, int y) {
	width = x;
	height = y;
	Field = new CBuilding**[height];
	for (int i = 0; i < height; ++i) {
		Field[i] = new CBuilding*[width];
		for (int j = 0; j < width; ++j)
			Field[i][j] = nullptr;
	}
	City_State.time = clock();
	City_State.money = 10;
	City_State.population = 1;
	City_State.wealth = 5;
	City_State.happiness = 5;
	Factories = new CFactory*[3];
	Factories[0] = new CHouseFactory;
	Factories[1] = new CWorkFactory;
	Factories[2] = new CParkFactory;
	Parser = CParseAdapter(new CStringParse, width, height);
}

CCity::~CCity() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (Field[i][j] != nullptr) {
				delete Field[i][j];
			}
		}
		delete Field[i];
	}
	delete Field;
	for (int i = 0; i < 3; ++i) {
		delete Factories[i];
	}
	delete Factories;
}

void CCity::Build(const std::string& t, const int x, const int y, const clock_t& current) {
	int i = 0;
	if (t != "Road") {
		while ((i < 3) && (t != Factories[i]->type))
			++i;
		if (i == 3) {
			std::cout << "Error! Wrong type of the building!" << std::endl;
			return;
		}
	}
	if ((y < 0) || (y >= height) || (x < 0) || (x >= width)) {
		std::cout << "Error! Wrong coordinates!" << std::endl;
		return;
	}
	if (Field[y][x] != nullptr) {
		std::cout << "Error! There is an object!" << std::endl;
		return;
	}
	else {
		if ((t != "House") && !(((x > 0) && (Field[y][x - 1] != nullptr) && (Field[y][x - 1]->getType() == "Road")) ||
			((x < width - 1) && (Field[y][x + 1] != nullptr) && (Field[y][x + 1]->getType() == "Road")) ||
			((y > 0) && (Field[y - 1][x] != nullptr) && (Field[y - 1][x]->getType() == "Road")) ||
			((x < height - 1) && (Field[y + 1][x] != nullptr) && (Field[y + 1][x]->getType() == "Road")))) {
			std::cout << "Error! There is no road nearby!" << std::endl;
			return;
		}
	}
	if (t == "Road") {
		Field[y][x] = &CRoad::getInstance();
	}
	else {
		Field[y][x] = Factories[i]->create(current);
	}
}

void CCity::Check(const std::string& s, const clock_t& current) {
	std::vector<std::string> parse = Parser.parse(s);
	if (parse[0] == "Build") {
		if (parse.size() == 4) {
			Build(parse[1], stoi(parse[2]), stoi(parse[3]), current);
		} else {
			std::cout << "Error! Wrong number of arguments" << std::endl;
		}
	}
	City_State.time = current;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (Field[i][j] != nullptr) {
				Field[i][j]->action(this->City_State);
			}
		}
	}
}