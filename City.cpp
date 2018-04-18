#include "City.h"

#include "House.h"
#include "Work.h"
#include "Park.h"
#include "Road.h"
#include <iostream>
#include <string>

void strtoint(const std::string& s, int& x, int& y) {
	int i = 0;
	int length = s.size();
	while ((i < length) && !(isdigit(s[i])))
		++i;
	if (i == length) {
		x = -1;
		y = -1;
		return;
	}
	int j = i;
	while ((i < length) && isdigit(s[j]))
		++j;
	if (j == length) {
		x = -1;
		y = -1;
		return;
	}
	x = stoi(s.substr(i, j - i + 1));
	i = j + 1;
	while ((i < length) && !(isdigit(s[i])))
		++i;
	if (i == length) {
		x = -1;
		y = -1;
		return;
	}
	j = i;
	while ((i < length) && isdigit(s[j]))
		++j;
	y = stoi(s.substr(i, j - i + 1));
	i = j + 1;
	while ((i < length) && !(isdigit(s[i])))
		++i;
	if (i < length) {
		x = -1;
		y = -1;
		return;
	}
}

CCity::CCity() {
	width = 0;
	height = 0;
	Field = new CBuilding**[height];
	for (int i = 0; i < height; ++i) {
		Field[i] = new CBuilding*[width];
		for (int j = 0; j < width; ++j)
			Field[i][j] = NULL;
	}
	City_State.time = 0;
	City_State.money = 0;
	City_State.population = 0;
	City_State.wealth = 0;
	City_State.happiness = 0;
	Factories = new CFactory*[3];
	Factories[0] = new CHouseFactory;
	Factories[1] = new CWorkFactory;
	Factories[2] = new CParkFactory;
}

CCity::CCity(int x, int y) {
	width = x;
	height = y;
	Field = new CBuilding**[height];
	for (int i = 0; i < height; ++i) {
		Field[i] = new CBuilding*[width];
		for (int j = 0; j < width; ++j)
			Field[i][j] = NULL;	
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
}

CCity::~CCity() {
	delete Field;
	delete Factories;
}

void CCity::Build(const std::string& t, const int x, const int y) {
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
	if (Field[y][x] != NULL) {
		std::cout << "Error! There is an object!" << std::endl;
		return;
	}
	else {
		if ((t != "House") && !(((x > 0) && (Field[y][x - 1] != NULL) && (Field[y][x - 1]->getType() == "Road")) ||
			((x < width - 1) && (Field[y][x + 1] != NULL) && (Field[y][x + 1]->getType() == "Road")) ||
			((y > 0) && (Field[y - 1][x] != NULL) && (Field[y - 1][x]->getType() == "Road")) ||
			((x < height - 1) && (Field[y + 1][x] != NULL) && (Field[y + 1][x]->getType() == "Road")))) {
			std::cout << "Error! There is no road nearby!" << std::endl;
			return;
		}
	}
	if (t == "Road") {
		Field[y][x] = &CRoad::getInstance();
	}
	else {
		Field[y][x] = Factories[i]->create();
	}
}

void CCity::Check(const std::string& s, const clock_t& current) {
	int i = 0;
	while (s[i] != ' ') {
		++i;
	}
	if (s.substr(0, i) == "Build") {
		int j = i+1;
		while (s[j] != ' ') {
			++j;
		}
		int x, y;
		strtoint(s.substr(j), x, y);
		std::cout << s.substr(i + 1, j - i - 1) << std::endl;
		Build(s.substr(i + 1, j - i - 1), x, y);
	}
	City_State.time = current;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (Field[i][j] != NULL) {
				Field[i][j]->action(this->City_State);
			}
		}
	}
}