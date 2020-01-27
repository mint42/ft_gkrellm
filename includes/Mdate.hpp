#ifndef MDATE_HPP
#define MDATE_HPP

#include <unistd.h>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Mdate : virtual public IMonitorModule{
	public:
		Mdate();
		~Mdate();
		Mdate(const Mdate &);
		Mdate & operator = (const Mdate &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
