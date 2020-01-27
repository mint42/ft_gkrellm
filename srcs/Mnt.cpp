#include "../includes/Mnt.hpp"

Mnt::Mnt() : _b(true), _height(3) {}

Mnt::~Mnt(){}

Mnt::Mnt(const Mnt &d) {
	*this = d;
}

Mnt & Mnt::operator = (const Mnt &) {
	return *this;
}

std::string Mnt::getMName() const {
	return "Network throughput:";
}

void Mnt::Sset(std::string s) {
    _s = s;
}

std::string Mnt::getS(void) const {
    return _s;
}

void* setS(void* nt) {
    FILE *f = popen("netstat -w1", "r");
    char buffer [4096];

    long i = 0;
    long o = 0;
    while (fgets(buffer, 4096, f)) {
        std::string line(buffer);
        if(line.find("input") == line.npos && line.find("packets") == line.npos) {
            long discard;
            std::stringstream ss(line);
            ss >> discard;
            ss >> discard;
            ss >> i;
            ss >> discard;
            ss >> discard;
            ss >> o;
            std::stringstream ss2;
            ss2 << "Input: " << i << " Output: " << o;
            reinterpret_cast<Mnt*>(nt)->Sset( ss2.str());
            break;
        }
    }
    return NULL;
}

void Mnt::execute(IMonitorDisplay *display_mode)
{
	(void)display_mode;
    if (_b) {
        _b = false;
//        pthread_t id;
        setS(this);
//        pthread_create(&id, NULL, &setS, this);
    }
	std::cout << _s << std::endl;
}

unsigned int	Mnt::get_height(void) const
{
	return (_height);
}
