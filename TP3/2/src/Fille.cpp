
#include <iostream>
#include "Fille.hpp"

Fille::Fille(std::string name):
	Mere(name)
{
	std::cout << "Creation Fille" << std::endl;
}

Fille::~Fille() {
}


void Fille::afficher() {
	std::cout << "Fille" << std::endl;
}

int main(int, char const **) {
	
	Mere mere("yo");
	Fille fille("yal");

	std::cout << std::endl;
	std::cout << Mere::getCompteur() << " instances Mere" << std::endl;

	mere.afficher();
	fille.afficher();

	Mere * fille2 = new Fille();
	std::cout << fille2->getName() << std::endl;
	fille2->afficher();

	delete fille2;

	return 0;
}