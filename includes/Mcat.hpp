#ifndef MCAT_HPP
#define MCAT_HPP

#include <unistd.h>
#include "IMonitorModule.hpp"

class Mcat : virtual public IMonitorModule{
	private:
        int 			_frame;

	protected:
		unsigned int	_height;

    public:
		Mcat();
		~Mcat();
		Mcat(const Mcat &);
		Mcat & operator = (const Mcat &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;
};

#endif
