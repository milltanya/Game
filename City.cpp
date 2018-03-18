#include "City.h"

#include "House.h"
#include "Work.h"
#include "Park.h"
#include "Road.h"
#include <iostream>

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
	x = std::stoi(s.substr(i, j - i + 1));
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
	y = std::stoi(s.substr(i, j - i + 1));
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
	Field = std::vector<std::vector<CBuilding*> >(height, std::vector<CBuilding*>(width, NULL));
	City_State.time = clock();
	City_State.money = 10;
	City_State.population = 1;
	City_State.wealth = 5;
	City_State.happiness = 5;
	Factories = { new CHouseFactory, new CWorkFactory, new CParkFactory };
}

CCity::~CCity() {

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
	std::cout << "money: " << City_State.money << "  population: " << City_State.population << "  wealth: " << City_State.wealth << "  happiness = " << City_State.happiness << std::endl << std::endl;
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
	std::string s;
	bool flag = false;
	int i = 0;
	std::cout << "Enter the type of the building (House / Work / Park)" << std::endl;
	while (!flag) {
		std::getline(std::cin, s);
		if (s == "Exit")
			return;
		i = 0;
		while ((i < Factories.size()) && (s != Factories[i]->type))
			++i;
		if (i < Factories.size())
			flag = true;
		else
			std::cout << "Error! Wrong type of the building!" << std::endl;
	}
	flag = false;
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
		if (Field[y][x] != nullptr) {
			std::cout << "Error! There is an object!" << std::endl;
			x = -1;
			y = -1;
		}
		else {
			if (s == "House")
				flag = true;
			else {
				if (((x > 0) && (Field[y][x - 1] != nullptr) && (Field[y][x - 1]->symbol == 'R')) || ((x < width - 1) && (Field[y][x + 1] != nullptr) && (Field[y][x + 1]->symbol == 'R')) || ((y > 0) && (Field[y - 1][x] != nullptr) && (Field[y - 1][x]->symbol == 'R')) || ((x < height - 1) && (Field[y + 1][x] != nullptr) && (Field[y + 1][x]->symbol == 'R')))
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
		if (Field[y][x] != nullptr) {
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
