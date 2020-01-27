#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mip.hpp"

Mip::Mip() : _height(4) {}

Mip::~Mip(){}

Mip::Mip(const Mip &d) {
	*this = d;
}

Mip & Mip::operator = (const Mip &rhs) {
	if (this != &rhs) {
		_height = rhs.get_height();
	}
	return *this;
}

std::string Mip::getMName() const {
	return MOD_IP;
}

void Mip::execute(IMonitorDisplay *display_mode) {
	display_mode->display_line(cmd_to_str("echo $(system_profiler SPDisplaysDataType | head -n 3 | tail -n +3)"));
	display_mode->display_line(cmd_to_str("echo $(system_profiler SPDisplaysDataType | grep Vendor)"));
	display_mode->display_line(cmd_to_str("echo $(system_profiler SPDisplaysDataType | grep Resolution)"));
}

unsigned int	Mip::get_height(void) const
{
	return (_height);
}
