#ifndef GAME_PARSERADAPTER_H
#define GAME_PARSERADAPTER_H

#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

class CParse {
public:
    virtual std::vector<std::string> parse(const std::string& s) = 0;
};

class CParseAdapter : public CParse {
public:
    CParseAdapter();
    CParseAdapter(CStringParse* p, int w, int h);
    ~CParseAdapter();
    std::vector<std::string> parse(const std::string& s) override;
private:
    int width, height;
    CStringParse* p_parse;
};


#endif //GAME_PARSERADAPTER_H
