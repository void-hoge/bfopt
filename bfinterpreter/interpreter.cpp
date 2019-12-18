#include "interpreter.hpp"

interpreter::interpreter(){
	for (auto &a:this->data){
		a = 0;
	}
	data_ptr = 0;
	pc = 0;
}

void interpreter::add_prg(const std::string p){
	for (auto &a: p){
		this->prg.push_back(a);
	}
}

void interpreter::show_data(const size_t begin, const size_t end) const{
	if (begin < 0 || begin > size) return;
	if (end < 0 || begin > size) return;
	for (size_t i = begin; i < end; i++) {
		if (this->data_ptr == i) {
			std::cout << "\e[44m";
		}
		std::cout << (int)this->data[i] << "\e[0m ";
	}
	std::cout << std::endl;
}

void interpreter::show_prg() const{
	for (size_t i = 0; i < this->prg.size(); i++) {
		if (this->pc==i) {
			std::cout << "\e[41m";
		}
		std::cout << this->prg[i] << "\e[0m";
	}
	std::cout << std::endl;
}

bool interpreter::dbg(){
	this->show_prg();
	this->show_data(0, 20);
	while (this->pc < this->prg.size()){
		// std::this_thread::sleep_for(std::chrono::milliseconds());
		if (!this->eval(this->prg[this->pc]))return false;
		if (data_ptr < 0 || data_ptr > size) return false;
		if (pc < 0 || pc > prg.size()) return false;
		this->show_prg();
		this->show_data(0, 40);
	}
	std::cout << "end" << std::endl;
	return true;
}

bool interpreter::run(){
	while (this->pc < this->prg.size()){
		if (!this->eval(this->prg[this->pc])){
			std::cout << "returned false from eval()" << '\n';
			return false;
		}
		if (data_ptr < 0 || data_ptr > size) {
			std::cout << "data_ptr out of range" << std::endl;
			return false;
		}
		if (pc < 0 || pc > prg.size()){
			std::cout << "pc out of range" << std::endl;
			return false;
		}
	}
	return true;
}

bool interpreter::eval(const char instruction) {
	switch (instruction) {
		case '>':{
			this->data_ptr++;
			break;
		}
		case '<':{
			this->data_ptr--;
			break;
		}
		case '+':{
			this->data[this->data_ptr]++;
			break;
		}
		case '-':{
			this->data[this->data_ptr]--;
			break;
		}
		case '.':{
			std::cout << this->data[this->data_ptr];
			break;
		}
		case ',':{
			std::cin >> this->data[this->data_ptr];
			break;
		}
		case '[':{
			if (this->data[this->data_ptr] == 0) {
				int nest_cnt = 1;
				while (nest_cnt) {
					this->pc++;
					// if (this->pc > this->prg.size()) return false;
					// if (this->pc < 1) return false;
					if (this->prg[this->pc] == '[') nest_cnt++;
					if (this->prg[this->pc] == ']') nest_cnt--;
				}
			}
			break;
		}
		case ']':{
			if (this->data[this->data_ptr] != 0) {
				int nest_cnt = 1;
				while (nest_cnt) {
					this->pc--;
					// if (this->pc > this->prg.size()) return false;
					// if (this->pc < 1) return false;
					if (this->prg[this->pc] == ']') nest_cnt++;
					if (this->prg[this->pc] == '[') nest_cnt--;
				}
			}
			break;
		}
		default:{
			break;
		}
	}
	this->pc++;
	return true;
}
