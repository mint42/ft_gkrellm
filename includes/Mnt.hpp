#ifndef MNT_HPP
#define MNT_HPP

#include "IMonitorModule.hpp"

class Mnt : virtual public IMonitorModule{
    public:
		Mnt();
		~Mnt();
		Mnt(const Mnt &);
		Mnt & operator = (const Mnt &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
