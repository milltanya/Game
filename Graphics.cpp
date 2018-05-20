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
    for (int i = 0; i < city->State.Field.size(); ++i) {
        p = city->State.Field.size() - i;
        std::cout << " " << p;
        if (p < 10) {
            std::cout << " ";
        }
        for (int j = 0; j < city->State.Field[0].size(); ++j) {
            std::cout << " ";
            if (city->State.Field[i][j] == nullptr) {
                std::cout << " ";
            }
            else {
                std::cout << city->State.Field[i][j]->getType()[0];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for (int i = 0; i < city->State.Field[0].size(); ++i) {
        p = i + 1;
        std::cout << " " << p;
        if (p < 10) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "money: " << city->State.State.money << std::endl;
    std::cout << "population: " << city->State.State.population << std::endl;
    std::cout << "wealth: " << city->State.State.wealth << std::endl;
    std::cout << "happiness: " << city->State.State.happiness << std::endl;
}