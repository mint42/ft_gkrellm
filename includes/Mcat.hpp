#ifndef MCAT_HPP
#define MCAT_HPP

#include <unistd.h>
#include "IMonitorModule.hpp"

class MCat : virtual public IMonitorModule{
	private:
        int _frame;
    
    public:
		MCat();
		~MCat();
		MCat(const MCat &);
		MCat & operator = (const MCat &);
		std::string getMName() const;
		void execute();
};

#endif
