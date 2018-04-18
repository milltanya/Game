#include <ctime>
#include <iostream>
#include <string>
#include "City.h"
#include "Graphics.h"



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
	CCityDecorator CityDec(&City);
	std::cout << "Enter commands: " << std::endl;
	std::cout << "End        or        Build <type> <coords(y x)>        or        any symbol for checking" << std::endl;
	std::getline(std::cin, s);
	while (!(s == "End")) {
		if (s != "") {
			CityDec.Check(s, clock());
		}
		std::getline(std::cin, s);
	}
	return 0;
}
