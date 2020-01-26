#include "../includes/Mos.hpp"

Mos::Mos() {}

Mos::~Mos(){}

Mos::Mos(const Mos &d) {
	*this = d;
}

Mos & Mos::operator = (const Mos &) {
	return *this;
}

std::string Mos::getMName() const {
	return "OS info:";
}

void Mos::execute() const {
	std::system("sw_vers > dummy.txt");
	std::cout << std::ifstream("dummy.txt").rdbuf();
}
