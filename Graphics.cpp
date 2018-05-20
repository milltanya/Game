#include "Graphics.h"
#include <ctime>
#include <iostream>
#include <string>


CCityDecorator::CCityDecorator() {
	///Конструктор по умолчанию
    m_city = new CCity;
}

CCityDecorator::CCityDecorator(CCity* city) {
	///Конструктор по ссылке на объект класса CCity
	m_city = city;
	draw(m_city->State);
}

CCityDecorator::~CCityDecorator() {}

void CCityDecorator::Check(const std::string& s, const clock_t& current) {
	///Дукоратор функции Check класса CCity
	m_city->Check(s, current);
    draw(m_city->State);
}

void draw(const SCityState& state) {
	///Вывод поля на экран
    int p;
    for (int i = 0; i < state.Field.size(); ++i) {
        p = state.Field.size() - i;
        std::cout << " " << p;
        if (p < 10) {
            std::cout << " ";
        }
        for (int j = 0; j < state.Field[0].size(); ++j) {
            std::cout << " ";
            if (state.Field[i][j] == nullptr) {
                std::cout << " ";
            }
            else {
                std::cout << state.Field[i][j]->getType()[0];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for (int i = 0; i < state.Field[0].size(); ++i) {
        p = i + 1;
        std::cout << " " << p;
        if (p < 10) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "money: " << state.State.money << std::endl;
    std::cout << "population: " << state.State.population << std::endl;
    std::cout << "wealth: " << state.State.wealth << std::endl;
    std::cout << "happiness: " << state.State.happiness << std::endl;
}