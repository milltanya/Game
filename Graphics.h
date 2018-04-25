#ifndef GAME_GRAPHICS_H
#define GAME_GRAPHICS_H

#include <ctime>
#include <string>
#include "City.h"

class CCityDecorator : public CCity {
protected:
    CCity* m_city;
public:
    CCityDecorator();
    explicit CCityDecorator(CCity* city);
    ~CCityDecorator();
    void Check(const std::string& s, const clock_t& current);
};

void draw(CCity* city);

#endif
