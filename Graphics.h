#ifndef GRAPHICS
#define GRAPHICS

#include <iostream>
#include "Building.h"
#include "City.h"

class CCityDecorator : public CCity {
protected:
    CCity* m_city;
public:
    CCityDecorator();
    CCityDecorator(CCity* city);
    ~CCityDecorator();
    void Check(const std::string& s, const clock_t& current);
};

void draw(const CCity& city);

#endif
