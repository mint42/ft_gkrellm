#ifndef MRAM_HPP
#define MRAM_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Mram : virtual public IMonitorModule{
	public:
		Mram();
		~Mram();
		Mram(const Mram &);
		Mram & operator = (const Mram &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
