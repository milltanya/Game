#include "Graphics.h"
#include <string>

CCityDecorator::CCityDecorator(CCity* city) {
	m_city = city;
    draw(m_city);
}
CCityDecorator::~CCityDecorator() {
	delete m_city;
}
void CCityDecorator::Check(const std::string& s, const clock_t& current) {
	m_city->Check(s, current);
    draw(m_city);
}

void draw(CCity* city) {
    std::cout << "   ";
    for (int i = 0; i < city->width; ++i) {
        std::cout << " " << i;
        if (i < 10) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < city->height; ++i) {
        std::cout << " " << i;
        if (i < 10) {
            std::cout << " ";
        }
        for (int j = 0; j < city->width; ++j) {
            std::cout << " ";
            if (city->Field[i][j] == NULL) {
                std::cout << " ";
            }
            else {
                std::string s = city->Field[i][j]->getType();
                std::cout << s[0];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "money: " << city->City_State.money << std::endl;
    std::cout << "population: " << city->City_State.population << std::endl;
    std::cout << "wealth: " << city->City_State.wealth << std::endl;
    std::cout << "happiness: " << city->City_State.happiness << std::endl;
}