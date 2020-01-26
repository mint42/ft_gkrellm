#ifndef MRAM_HPP
#define MRAM_HPP

#include "IMonitorModule.hpp"

class Mram : virtual public IMonitorModule{
	public:
		Mram();
		~Mram();
		Mram(const Mram &);
		Mram & operator = (const Mram &);
		std::string getMName() const;
		void execute() const;
};

#endif
