#ifndef MCPU_HPP
#define MCPU_HPP

#include <unistd.h>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Mcpu : virtual public IMonitorModule{
	public:
		Mcpu();
		~Mcpu();
		Mcpu(const Mcpu &);
		Mcpu & operator = (const Mcpu &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
