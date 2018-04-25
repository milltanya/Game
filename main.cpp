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
		int a = 0;
		while (s[a] == ' ')
			++a;
		int b = a + 1;
		while (isdigit(s[b]))
			++b;
		int c = b + 1;
		while (s[c] == ' ')
			++c;
		int d = c + 1;
		while (isdigit(s[d]))
			++d;
		int e = d + 1;
		while (e < s.size() && s[e] == ' ')
			++e;
		if (a < b && b < c && c < d && d < e && e >= s.size()) {
			height = std::stoi(s.substr(a, b - a));
			width = std::stoi(s.substr(c, d - c));
			if (width < 0 || width >= 40 || height < 0 || height >= 30) {
				std::cout << "Error!" << std::endl;
				height = -1;
				width = -1;
			}
		}
		else {
			std::cout << "Error!" << std::endl;
		}
	}
	CCity City(width, height);
	CCityDecorator CityDec(&City);
	std::cout << "Enter commands: " << std::endl;
	std::cout << "End        or        Build <type> <x> <y>        or        any symbol for checking" << std::endl;
	std::getline(std::cin, s);
	while (s != "End") {
		CityDec.Check(s, clock());
		std::getline(std::cin, s);
	}
	return 0;
}