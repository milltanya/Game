#include "ParserAdapter.h"


#include <string>
#include <vector>
#include "Parser.h"

CParseAdapter::CParseAdapter() {
    p_parse = new CStringParse;
    width = 0;
    height = 0;
}

CParseAdapter::CParseAdapter(CStringParse* p, int w, int h) {
    p_parse = p;
    width = w;
    height = h;
}

CParseAdapter::~CParseAdapter(){
    //delete p_parse;
}

std::vector<std::string> CParseAdapter::parse(const std::string& s) {
	std::vector<std::string> t = p_parse->parse(s);
	int i = 0;
	int a = -1;
	int b = -1;
	bool fisdigit;
	while (b == -1 && i < t.size()) {
		fisdigit = true;
		for (char c : t[i])
			if (!isdigit(c))
				fisdigit = false;
		if (fisdigit) {
			if (a == -1) {
				a = i;
			}
			else {
				if (a + 1 == i)
					b = i;
				else
					a = i;
			}
		}
		++i;
	}
	if (a != -1 && b != -1) {
		int x = stoi(t[a]);
		int y = stoi(t[b]);
		t[a] = std::to_string(height - y);
		t[b] = std::to_string(x - 1);
	}
    return t;
}