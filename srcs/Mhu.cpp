#include "../includes/Mhu.hpp"

Mhu::Mhu() {}

Mhu::~Mhu(){}

Mhu::Mhu(const Mhu &d) {
	*this = d;
}

Mhu & Mhu::operator = (const Mhu &) {
	return *this;
}

std::string Mhu::getMName() const {
	return "Hostname/username:";
}

void Mhu::execute() const {
	char hostname[_POSIX_HOST_NAME_MAX];
	gethostname(hostname, _POSIX_HOST_NAME_MAX);

	std::cout << hostname << std::endl << getenv("USER") << std::endl;
}
