
#ifndef FILLE_H
#define FILLE_H

#include "Mere.hpp"

class Fille : public Mere {
private:

public:
	Fille(std::string = "None");
	~Fille();
	void afficher();
};


#endif