#ifndef MHU_HPP
#define MHU_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Mhu : virtual public IMonitorModule{
	public:
		Mhu();
		~Mhu();
		Mhu(const Mhu &);
		Mhu & operator = (const Mhu &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
