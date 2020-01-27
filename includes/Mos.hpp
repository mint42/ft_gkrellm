#ifndef MOS_HPP
#define MOS_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Mos : virtual public IMonitorModule{
	public:
		Mos();
		~Mos();
		Mos(const Mos &);
		Mos & operator = (const Mos &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
