#include "producteur.hpp"
#include <fstream>

bool Producteur::produire(int quantite, std::string nom) {
	travail++;
	bool error = true;

	std::ofstream fichier(nom.c_str());

	if (!fichier.fail()) {
		std::cout << "Ecriture dans " << nom << std::endl; 
		fichier << quantite << std::endl; 
		for (int i = 0; i < quantite; ++i)
			fichier << i+1 << std::endl;

		fichier.close();
		error = false;
	}

	return error;
}

int Producteur::getTravail() {
	return travail;
}