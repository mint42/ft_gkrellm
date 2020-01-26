#ifndef MDATE_HPP
#define MDATE_HPP

#include <unistd.h>
#include "IMonitorModule.hpp"

class Mdate : virtual public IMonitorModule{
	public:
		Mdate();
		~Mdate();
		Mdate(const Mdate &);
		Mdate & operator = (const Mdate &);
		std::string getMName() const;
		void execute() const;
};

#endif
