#pragma once

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

// > data_ptr++
// < data_ptr--
// + data[data_ptr]++
// - data[data_ptr]--
// . show(data[data_ptr])
// , input(data[data_ptr])
// [ goto ]
// ] goto [

class instruction {
private:
	instype type;
	int num;
public:
	instruction ();
};

using instype = int;
const instype nop = 0x0;
const instype move = 0x1;
const instype add = 0x2;
const instype show = 0x4;
const instype input = 0x8;
const instype goto = 0x10;
const instype gotob = 0x11;
const instype gotof = 0x12;

// > move,1
// < move,-1
// + add,1
// - add,-1
// . show
// , input
// [ gotob
// ] gotof
// [ goto
// ] goto

class interpreter {
private:
	static const size_t size = 1<<16;
	std::array<char, size> data;
	std::vector<char> prg;
	std::vector<instruction> ins;
	size_t data_ptr;
	size_t pc;
public:
	interpreter();
	void add_prg(std::string);
	bool run();
	bool dbg();
	void show_data(const size_t, const size_t) const;
	void show_prg() const;
	bool eval(const char);
};
