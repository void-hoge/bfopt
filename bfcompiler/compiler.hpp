#pragma once

#include <vector>
#include <string>

class compiler {
private:
	std::vector<char> prg;

public:
	compiler ();
	void add_prg(std::string);
};
