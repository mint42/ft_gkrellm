#ifndef MSERIAL_HPP
#define MSERIAL_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Mserial : virtual public IMonitorModule{
	public:
		Mserial();
		~Mserial();
		Mserial(const Mserial &);
		Mserial & operator = (const Mserial &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
