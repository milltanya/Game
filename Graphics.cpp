#include "Graphics.h"
#include <ctime>
#include <iostream>
#include <string>


CCityDecorator::CCityDecorator() {
    m_city = new CCity;
}

CCityDecorator::CCityDecorator(CCity* city) {
	m_city = city;
    draw(m_city);
}
CCityDecorator::~CCityDecorator() {
	//delete m_city;
}
void CCityDecorator::Check(const std::string& s, const clock_t& current) {
	m_city->Check(s, current);
    draw(m_city);
}

void draw(CCity* city) {
    int p;
    for (int i = 0; i < city->height; ++i) {
        p = city->height - i;
        std::cout << " " << p;
        if (p < 10) {
            std::cout << " ";
        }
        for (int j = 0; j < city->width; ++j) {
            std::cout << " ";
            if (city->Field[i][j] == nullptr) {
                std::cout << " ";
            }
            else {
                std::cout << city->Field[i][j]->getType()[0];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for (int i = 0; i < city->width; ++i) {
        p = i + 1;
        std::cout << " " << p;
        if (p < 10) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "money: " << city->City_State.money << std::endl;
    std::cout << "population: " << city->City_State.population << std::endl;
    std::cout << "wealth: " << city->City_State.wealth << std::endl;
    std::cout << "happiness: " << city->City_State.happiness << std::endl;
}