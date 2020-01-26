#include "../includes/Mcpu.hpp"

Mcpu::Mcpu() {}

Mcpu::~Mcpu(){}

Mcpu::Mcpu(const Mcpu &d) {
	*this = d;
}

Mcpu & Mcpu::operator = (const Mcpu &) {
	return *this;
}

std::string Mcpu::getMName() const {
	return "CPU:";
}

void Mcpu::execute() const {
	std::system("sysctl -n machdep.cpu.brand_string > dummy.txt");
	std::cout << std::ifstream("dummy.txt").rdbuf();
	std::system("sysctl -n hw.logicalcpu > dummy.txt");
	std::cout << "Number of Cores: " << std::ifstream("dummy.txt").rdbuf();
	std::system("top -l 1 | grep 'CPU usage:'");
	std::cout << "Usage: " << std::ifstream("dummy.txt").rdbuf();
}
