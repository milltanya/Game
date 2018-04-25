#include "Parser.h"

#include <string>
#include <vector>

std::vector<std::string> CStringParse::parse(const std::string& s) {
	int i = 0;
	int j = -1;
    std::vector<std::string> ans;
    while (i < s.length()) {
		i = j + 1;
		while (i < s.length() && s[i] == ' ') {
			++i;
		}
        j = i + 1;
        while (j < s.length() && s[j] != ' ') {
            ++j;
        }
		if (j <= s.length())
			ans.push_back(s.substr(i, j-i));
    }
    return ans;
}