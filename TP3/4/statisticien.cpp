#include "statisticien.hpp"
#include <fstream>


int Statisticien::acquerir(std::string nom) {

	int result = 0;
	std::ifstream fichier;
	int i = 0, max;

	fichier.open(nom.c_str());

	if (!fichier.fail()) {

		fichier >> max;

		while(!fichier.eof() && i<max) {
			double lecture;
			fichier >> lecture;
			++i;
			result += lecture;
			// std::cout << lecture << " ";
		}
		// std::cout << result << std::endl;
		fichier.close();	
	}

	return result;
}

bool Statisticien::aCalcule() {
	return calcul;
}