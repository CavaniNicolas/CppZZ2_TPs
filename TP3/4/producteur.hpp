#ifndef __CPP3_PRODUCTEUR_HPP__
#define __CPP3_PRODUCTEUR_HPP__

#include <iostream>
#include <string>

class Producteur {

	private:
		int travail;
	
	public:
		int getTravail();
		bool produire(int, std::string);
};

#endif
