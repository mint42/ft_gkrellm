#include "config.hpp"
#include "IMonitorDisplay.hpp"
#include "cmd_to_str.hpp"
#include "Mhu.hpp"

Mhu::Mhu() : _height(4) {}

Mhu::~Mhu(){}

Mhu::Mhu(const Mhu &d) {
	*this = d;
}

Mhu & Mhu::operator = (const Mhu &) {
	return *this;
}

std::string Mhu::getMName() const {
	return MOD_HU;
}

void Mhu::execute(IMonitorDisplay *display_mode) {
	char hostname[_POSIX_HOST_NAME_MAX];
	gethostname(hostname, _POSIX_HOST_NAME_MAX);

	display_mode->display_line_2("Hostname", hostname);
	display_mode->display_line_2("Username", getenv("USER"));
}

unsigned int	Mhu::get_height(void) const
{
	return (_height);
}
