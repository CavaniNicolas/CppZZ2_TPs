
#ifndef MERE_H
#define MERE_H

#include <string>

class Mere {

private:
	std::string name;
	static int compteur;

public:
	Mere(std::string = "None");
	~Mere();
	static int getCompteur();
	std::string getName();
	void afficher();
};

#endif
