#include "../includes/Mram.hpp"

Mram::Mram() {}

Mram::~Mram(){}

Mram::Mram(const Mram &d) {
	*this = d;
}

Mram & Mram::operator = (const Mram &) {
	return *this;
}

std::string Mram::getMName() const {
	return "RAM:";
}

void Mram::execute() const {
	std::system("sysctl -n hw.memsize > dummy.txt");
	std::cout << "RAM: " << std::ifstream("dummy.txt").rdbuf();
}
