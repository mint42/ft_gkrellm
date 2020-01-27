#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mos.hpp"

Mos::Mos() : _height(5) {}

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
	display_mode->display_line(cmd_to_str("sw_vers | grep ProductName | tr '\t' ' '"));
	display_mode->display_line(cmd_to_str("sw_vers | grep ProductVersion | tr '\t' ' '"));
	display_mode->display_line(cmd_to_str("sw_vers | grep BuildVersion | tr '\t' ' '"));
}

unsigned int	Mos::get_height(void) const
{
	return (_height);
}
