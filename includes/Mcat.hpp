#ifndef MCAT_HPP
#define MCAT_HPP

#include <unistd.h>
#include "IMonitorModule.hpp"

class MCat : virtual public IMonitorModule{
	private:
        int 			_frame;

	protected:
		unsigned int	_height;

    public:
		MCat();
		~MCat();
		MCat(const MCat &);
		MCat & operator = (const MCat &);
		std::string getMName() const;
		void execute();
		unsigned int get_height(void) const;
};

#endif
