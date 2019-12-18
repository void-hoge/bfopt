//brainfuckのコードをCのコードに変換する。

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

int main(const int argc, const char* argv[]){
	std::string filename = argv[1];
	std::ifstream read(filename, std::ios::in);
	std::string buf;
	compiler cpl;
	while (!read.eof()) {
		std::getline(read, buf);
		cpl.add_prg(buf);
	}
}
