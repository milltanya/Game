#include "Parser.h"

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> CStringParse::parse(const std::string& s) {
    int i, j = 0;
    while (s[i] == ' ') {
        ++i;
    }
    std::vector<std::string> ans;
    while (i < s.length()) {
        j = i + 1;
        while (s[j] != ' ') {
            ++j;
        }
        ans.push_back(s.substr(i, j-i));
        i = j + 1;
        while (s[i] == ' ') {
            ++i;
        }
    }
    return ans;
}