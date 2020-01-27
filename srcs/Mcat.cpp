#include "Mcat.hpp"
#include "IMonitorDisplay.hpp"

Mcat::Mcat() : _frame(0), _height(6) {}

Mcat::~Mcat(){}

Mcat::Mcat(const Mcat &d) {
	*this = d;
}

Mcat & Mcat::operator = (const Mcat &rhs) {
    if (this != &rhs) {
        _frame = rhs._frame;
    }
	return *this;
}

std::string Mcat::getMName() const {
	return "Cat!:";
}

void Mcat::execute(IMonitorDisplay *display_mode) {
	display_mode->display_cat(_frame);
	_frame = !_frame;
}

unsigned int	Mcat::get_height(void) const
{
	return (_height);
}
