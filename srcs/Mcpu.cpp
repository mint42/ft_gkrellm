#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mcpu.hpp"

Mcpu::Mcpu() {}

Mcpu::~Mcpu(){}

Mcpu::Mcpu(const Mcpu &d) : _height(5) {
	*this = d;
}

Mcpu & Mcpu::operator = (const Mcpu &) {
	return *this;
}

std::string Mcpu::getMName() const {
	return MOD_CPU;
}

void Mcpu::execute(IMonitorDisplay *display_mode) {
	display_mode->display_line(cmd_to_str("echo $(sysctl -n machdep.cpu.brand_string)"));
	display_mode->display_line(cmd_to_str("echo $(sysctl -n hw.logicalcpu)"));
	display_mode->display_line(cmd_to_str("echo $(top -l 1 | grep 'CPU usage:')"));
}

unsigned int	Mcpu::get_height(void) const
{
	return (_height);
}
