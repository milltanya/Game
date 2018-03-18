#include "City.h"

#include "House.h"
#include "Work.h"
#include "Park.h"
#include "Road.h"
#include <iostream>
#include <string>

void strtoint(std::string& s, int& x, int& y) {
	int i = 0;
	int length = s.size();
	while ((i < length) && !(isdigit(s[i])))
		++i;
	if (i == length) {
		std::cout << "Error!" << std::endl;
		x = -1;
		y = -1;
		return;
	}
	int j = i;
	while ((i < length) && isdigit(s[j]))
		++j;
	if (j == length) {
		std::cout << "Error!" << std::endl;
		x = -1;
		y = -1;
		return;
	}
	x = stoi(s.substr(i, j - i + 1));
	i = j + 1;
	while ((i < length) && !(isdigit(s[i])))
		++i;
	if (i == length) {
		std::cout << "Error!" << std::endl;
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
		std::cout << "Error!" << std::endl;
		x = -1;
		y = -1;
		return;
	}
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

void CCity::print() {
	std::cout << "   ";
	for (int i = 0; i < width; ++i) {
		std::cout << " " << i;
		if (i < 10) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < height; ++i) {
		std::cout << " " << i;
		if (i < 10) {
			std::cout << " ";
		}
		for (int j = 0; j < width; ++j) {
			if (Field[i][j] == NULL) {
				std::cout << "   ";
			}
			else {
				std::cout << " " << Field[i][j]->symbol << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "money: " << City_State.money << "  population: " << City_State.population << "  wealth: " << City_State.wealth << "  happiness: " << City_State.happiness << std::endl << std::endl;
}

void CCity::Check(clock_t current) {
	City_State.time = current;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (Field[i][j] != NULL) {
				Field[i][j]->action(this->City_State);
			}
		}
	}
}

void CCity::Build() {
	std::string t;
	bool flag = false;
	int i = 0;
	std::cout << "Enter the type of the building (House / Work / Park)" << std::endl;
	while (!flag) {
		std::getline(std::cin, t);
		if (t == "Exit")
			return;
		i = 0;
		while ((i < 3) && (t != Factories[i]->type))
			++i;
		if (i < 3)
			flag = true;
		else
			std::cout << "Error! Wrong type of the building!" << std::endl;
	}
	flag = false;
	std::string s;
	int x, y;
	while (!flag) {
		std::cout << "Enter height and width" << std::endl;
		x = -1;
		y = -1;
		while ((x < 0) || (y < 0)) {
			std::cout << "Format: 0 <= Height < " << height << " and 0 <= Width < " << width << "" << std::endl;
			std::getline(std::cin, s);
			if (s == "Exit")
				return;
			strtoint(s, y, x);
			if ((y < 0) || (y >= height) || (x < 0) || (x >= width)) {
				x = -1;
				y = -1;
			}
		}
		if (Field[y][x] != NULL) {
			std::cout << "Error! There is an object!" << std::endl;
			x = -1;
			y = -1;
		}
		else {
			if (t == "House")
				flag = true;
			else {
				if (((x > 0) && (Field[y][x - 1] != NULL) && (Field[y][x - 1]->symbol == 'R')) || ((x < width - 1) && (Field[y][x + 1] != NULL) && (Field[y][x + 1]->symbol == 'R')) || ((y > 0) && (Field[y - 1][x] != NULL) && (Field[y - 1][x]->symbol == 'R')) || ((x < height - 1) && (Field[y + 1][x] != NULL) && (Field[y + 1][x]->symbol == 'R')))
					flag = true;
				else {
					std::cout << "Error! There is no road nearby! You can Continue, Add a road or Exit the building process" << std::endl;
					std::getline(std::cin, s);
					if (s == "Exit")
						return;
					if (s == "Add a road")
						AddRoad();
				}
			}
		}
	}
	Field[y][x] = Factories[i]->create();
}

void CCity::AddRoad() {
	bool flag = false;
	int x, y;
	std::string s;
	while (!flag) {
		std::cout << "Enter height and width" << std::endl;
		x = -1;
		y = -1;
		while ((x < 0) || (y < 0)) {
			std::cout << "Format: 0 <= Height < " << height << " and 0 <= Width < " << width << "" << std::endl;
			std::getline(std::cin, s);
			if (s == "Exit")
				return;
			strtoint(s, y, x);
			if ((y < 0) || (y >= height) || (x < 0) || (x >= width)) {
				x = -1;
				y = -1;
			}
		}
		if (Field[y][x] != NULL) {
			std::cout << "Error! There is an object!" << std::endl;
			x = -1;
			y = -1;
		}
		else {
			flag = true;
		}
	}
	Field[y][x] = &CRoad::getInstance();
}
