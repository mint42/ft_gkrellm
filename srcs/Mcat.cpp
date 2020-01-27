#include "../includes/Mcat.hpp"

MCat::MCat() : _frame(0){}

MCat::~MCat(){}

MCat::MCat(const MCat &d) {
	*this = d;
}

MCat & MCat::operator = (const MCat &rhs) {
    if (this != &rhs) {
        _frame = rhs._frame;
    }
	return *this;
}

std::string MCat::getMName() const {
	return "Cat!:";
}

void MCat::execute()  {
    if (_frame == 0) {
        std::cout << "      |\\      _,,,---,,_" << std::endl;
        std::cout << "ZZZzz /,`.-'`'    -.  ;-;;,_" << std::endl;
        std::cout << "     |,4-  ) )-,_. ,\\ (  `'-'" << std::endl;
        std::cout << "    '---''(_/--'  `-'\\_)  " << std::endl;
        _frame = 1;
    }
    else {
        std::cout << "      |\\      " << std::endl;
        std::cout << "zzzZZ /,`.-'`'_,,,---,,_;,_" << std::endl;
        std::cout << "     |,4-  ) )-,_. ,\\ (  `'-'" << std::endl;
        std::cout << "    '---''(_/--'  `-'\\_)  " << std::endl;
        _frame = 0;
    }
}
