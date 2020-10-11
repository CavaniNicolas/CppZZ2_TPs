
#include <iostream>
#include "Cercle.hpp"
#include "Rectangle.hpp"

void afficher1(Forme f) {
	std::cout << f.toString() << std::endl; // Forme
}

void afficher2(Forme &f) {
	std::cout << f.toString() << std::endl; // Cercle
}

void afficher3(Forme * f) {
	std::cout << f->toString() << std::endl; // Cercle
}

int main(int, char const **) {

	Rectangle rect(1, 1, 2, 2);
	Cercle cercle1(3, 3, 4, 5);
	Cercle cercle2(7, 7, 6);

	std::cout << rect.toString() << std::endl;
	std::cout << cercle1.toString() << std::endl;
	std::cout << cercle2.toString() << std::endl;

	afficher1(cercle1);
	afficher2(cercle1);
	afficher3(&cercle1);

	return 0;
}
