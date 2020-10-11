
#include "Famille.hpp"

Famille::Famille(int taille) {
	allBavarde = new Bavarde[taille];
}

Famille::~Famille() {
	delete [] allBavarde;
}

Bavarde * Famille::getAllBavarde() {
	return allBavarde;
}


int main(int, char const **) {

	Famille * famille = new Famille(5000);
	delete famille;
	return 0;
}