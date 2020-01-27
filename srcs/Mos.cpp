#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mos.hpp"

Mos::Mos() {}

Mos::~Mos(){}

Mos::Mos(const Mos &d) {
	*this = d;
}

Mos & Mos::operator = (const Mos &) {
	return *this;
}

std::string Mos::getMName() const {
	return MOD_OS;
}

void Mos::execute(IMonitorDisplay *display_mode) {
	display_mode->display_line(cmd_to_str("sw_vers"));
}
