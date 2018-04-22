//
// Created by tanya on 19.04.2018.
//

#ifndef GAME_PARSERADAPTER_H
#define GAME_PARSERADAPTER_H

#include <vector>
#include <string>
#include "Parser.h"

class CParse {
public:
    virtual std::vector<std::string> parse(const std::string& s) = 0;
};

class CParseAdapter : public CParse {
public:
    CParseAdapter(CStringParse* p, int w, int h);
    ~CParseAdapter();
    std::vector<std::string> parse(const std::string& s);
private:
    int width, height;
    CStringParse* p_parse;
};


#endif //GAME_PARSERADAPTER_H
