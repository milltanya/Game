#include "Graphics.h"
#include <string>

void draw(CBuilding& Building) {
	std::string s = Building.getType();
	std::cout << s[0];
}

void draw(const CCity& City) {
	std::cout << "   ";
	for (int i = 0; i < City.width; ++i) {
		std::cout << " " << i;
		if (i < 10) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < City.height; ++i) {
		std::cout << " " << i;
		if (i < 10) {
			std::cout << " ";
		}
		for (int j = 0; j < City.width; ++j) {
			std::cout << " ";
			if (City.Field[i][j] == NULL) {
				std::cout << " ";
			}
			else {
				draw(*City.Field[i][j]);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "money: " << City.City_State.money << std::endl;
	std::cout << "population: " << City.City_State.population << std::endl;
	std::cout << "wealth: " << City.City_State.wealth << std::endl;
	std::cout << "happiness: " << City.City_State.happiness << std::endl;
}

