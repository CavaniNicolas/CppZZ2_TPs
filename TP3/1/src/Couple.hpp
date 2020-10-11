
#ifndef COUPLE_H
#define COUPLE_H

#include "Bavarde.hpp"

class Couple {

	private:
		Bavarde * bavarde1;
		Bavarde * bavarde2;

	public:
		Couple(Bavarde * = nullptr, Bavarde * = nullptr);
		~Couple();
		Bavarde * getBavarde1();
		Bavarde * getBavarde2();

};

#endif
