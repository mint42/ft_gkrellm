#include "../includes/Mdate.hpp"

Mdate::Mdate() {}

Mdate::~Mdate(){}

Mdate::Mdate(const Mdate &d) {
	*this = d;
}

Mdate & Mdate::operator = (const Mdate &) {
	return *this;
}

std::string Mdate::getMName() const {
	return "Date/time: ";
}

void Mdate::execute() const {
	time_t t = time(NULL);
	std::cout << ctime(&t);
}
