#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "interpreter.hpp"

int main(const int argc, const char* argv[]){
	std::string filename = argv[1];
	std::ifstream read(filename, std::ios::in);
	std::string buf;

	interpreter itp;
	while (!read.eof()) {
		std::getline(read, buf);
		itp.add_prg(buf);
	}
//	std::cout << itp.dbg() << std::endl;
	std::cout << itp.run() << std::endl;
}
