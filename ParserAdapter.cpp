#include "ParserAdapter.h"

#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

CParseAdapter::CParseAdapter() {
    p_parse = nullptr;
    width = 0;
    height = 0;
}

CParseAdapter::CParseAdapter(CStringParse* p, int w, int h) {
    p_parse = p;
    width = w;
    height = h;
}

CParseAdapter::~CParseAdapter(){
    delete p_parse;
}

std::vector<std::string> CParseAdapter::parse(const std::string& s) {
    std::vector<std::string> t = p_parse->parse(s);
    int x = stoi(t[2]);
    int y = stoi(t[3]);
    t[2] = std::to_string(x - 1);
    t[3] = std::to_string(height - y);
    return t;
}