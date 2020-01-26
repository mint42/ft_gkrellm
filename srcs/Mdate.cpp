#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mdate.hpp"

Mdate::Mdate() {}

Mdate::~Mdate(){}

Mdate::Mdate(const Mdate &d) {
	*this = d;
}

Mdate & Mdate::operator = (const Mdate &) {
	return *this;
}

std::string Mdate::getMName() const {
	return MOD_DT;
}

void Mdate::execute(IMonitorDisplay *display_mode) const {
	time_t t = time(NULL);
	display_mode->display_line(std::string(ctime(&t)));
}
