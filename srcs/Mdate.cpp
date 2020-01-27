#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mdate.hpp"

Mdate::Mdate() : _height(3) {}

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

void Mdate::execute(IMonitorDisplay *display_mode) {
	time_t t = time(NULL);
	display_mode->display_line(std::string(ctime(&t)));
}

unsigned int	Mdate::get_height(void) const
{
	return (_height);
}
