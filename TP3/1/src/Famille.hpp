
#ifndef FAMILLE_H
#define FAMILLE_H

#include "Bavarde.hpp"

class Famille {

	private:
		Bavarde * allBavarde;

	public:
		Famille(int = 2);
		~Famille();
		Bavarde * getAllBavarde();

};

#endif
