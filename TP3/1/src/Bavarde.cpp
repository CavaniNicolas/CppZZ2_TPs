
#include <iostream>
#include "Bavarde.hpp"

Bavarde::Bavarde(int a) : a(a) {
	std::cout << "Construction" << std::endl;
}

Bavarde::~Bavarde() {
	std::cout << "Destruction" << std::endl;
}

void fonction(Bavarde b) {
	std::cout << "code de la fonction" << std::endl;
	int a = b.getA();
	std::cout << a << std::endl;
}

int Bavarde::getA() {
	return a;
}

void Bavarde::afficher() {
	std::cout << "Affichage (getA()) " << getA() << std::endl;
}

// int main(int, char const **) {
// 	Bavarde * bavarde = (Bavarde *)malloc(sizeof(Bavarde));
// 	bavarde->afficher();
// 	free(bavarde);
// 	return 0;
// }


// int main(int, char const **) {
// 	Bavarde * bavarde = new Bavarde(3);
// 	fonction(*bavarde);
// 	delete bavarde;
// 	return 0;
// }

// int main(int, char **) {
// 	const int TAILLE = 2;
// 	Bavarde   tab1[TAILLE];
// 	Bavarde * tab2 = new Bavarde[TAILLE];

// 	for (int i =0; i < TAILLE; ++i) {
// 		tab1[i].afficher();
// 		tab2[i].afficher();
// 	}
// 	delete [] tab2;
// 	return 0;
// }
