#ifndef MIP_HPP
#define MIP_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Mip : virtual public IMonitorModule{
	public:
		Mip();
		~Mip();
		Mip(const Mip &);
		Mip & operator = (const Mip &);
		std::string getMName() const;
		void execute(IMonitorDisplay *display_mode);
		unsigned int get_height(void) const;

	protected:
		unsigned int	_height;
};

#endif
