#include "Mnt.hpp"
#include "cmd_to_str.hpp"
#include "config.hpp"

Mnt::Mnt() : _height(3) {}

Mnt::~Mnt(){}

Mnt::Mnt(const Mnt &d) {
	*this = d;
}

Mnt & Mnt::operator = (const Mnt &) {
	return *this;
}

std::string Mnt::getMName() const {
	return MOD_NET;
}

void Mnt::execute(IMonitorDisplay *display_mode)
{
	display_mode->display_line(cmd_to_str_DummyThicc("netstat -w1"));
}

unsigned int	Mnt::get_height(void) const
{
	return (_height);
}
