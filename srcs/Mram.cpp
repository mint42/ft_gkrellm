#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mram.hpp"

Mram::Mram() : _height(4) {}

Mram::~Mram(){}

Mram::Mram(const Mram &d) {
	*this = d;
}

Mram & Mram::operator = (const Mram &) {
	return *this;
}

std::string Mram::getMName() const {
	return MOD_RAM;
}

void Mram::execute(IMonitorDisplay * display_mode) {
	display_mode->display_line_2("RAM", cmd_to_str("sysctl -n hw.memsize"));
}

unsigned int	Mram::get_height(void) const
{
	return (_height);
}
