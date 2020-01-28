#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mserial.hpp"

Mserial::Mserial() : _height(4) {}

Mserial::~Mserial(){}

Mserial::Mserial(const Mserial &d) {
	*this = d;
}

Mserial & Mserial::operator = (const Mserial &rhs) {
	if (this != &rhs) {
		_height = rhs.get_height();
	}
	return *this;
}

std::string Mserial::getMName() const {
	return MOD_SERIAL;
}

void Mserial::execute(IMonitorDisplay *display_mode) {
	display_mode->display_line(cmd_to_str("ioreg -l | grep IOPlatformSerialNumber | awk '{print $4}'"));
}

unsigned int	Mserial::get_height(void) const
{
	return (_height);
}
