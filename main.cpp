#include <ctime>
#include <iostream>
#include <string>
#include "City.h"



int main() {
	int width = -1;
	int height = -1;
	std::cout << "Enter height and width" << std::endl;
	std::string s;
	while ((width < 0) || (height < 0)) {
		std::cout << "Format: 0 < height < 30 and 0 < width < 40" << std::endl;
		std::getline(std::cin, s);
		strtoint(s, height, width);
		if ((height <= 0) || (height >= 30) || (width <= 0) || (width >= 40)) {
			width = -1;
			height = -1;
		}
	}
	CCity City(width, height);
	City.print();
	std::cout << "Check(any symbol) / Build / Add a road / End" << std::endl;
	std::getline(std::cin, s);
	while (!(s == "End")) {
		if (s == "Build")
			City.Build();
		else
			if (s == "Add a road")
				City.AddRoad();
		City.Check(clock());
		City.print();
		std::cout << "Check(any symbol) / Build / Add a road / End" << std::endl;
		std::getline(std::cin, s);
	}
}
