#ifndef MNT_HPP
#define MNT_HPP

#include "IMonitorModule.hpp"

class Mnt : virtual public IMonitorModule{
	private:
        bool _b;
        std::string _s;
    
    public:
		Mnt();
		~Mnt();
		Mnt(const Mnt &);
		void Sset(std::string);
		Mnt & operator = (const Mnt &);
		std::string getMName() const;
		void execute();
		std::string getS() const ;
};

void *setS(void *);

#endif
