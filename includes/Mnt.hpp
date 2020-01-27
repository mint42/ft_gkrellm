#ifndef MNT_HPP
#define MNT_HPP

#include "IMonitorModule.hpp"

class Mnt : virtual public IMonitorModule{
	private:
        bool _b;
        std::string _s;

	protected:
		unsigned int	_height;
    
    public:
		Mnt();
		~Mnt();
		Mnt(const Mnt &);
		void Sset(std::string);
		Mnt & operator = (const Mnt &);
		std::string getMName() const;
		void execute();
		std::string getS() const ;
		unsigned int get_height(void) const;
};

void *setS(void *);

#endif
