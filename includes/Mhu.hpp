#ifndef MHU_HPP
#define MHU_HPP

#include "IMonitorModule.hpp"

class Mhu : virtual public IMonitorModule{
	public:
		Mhu();
		~Mhu();
		Mhu(const Mhu &);
		Mhu & operator = (const Mhu &);
		std::string getMName() const;
		void execute() const;
};

#endif