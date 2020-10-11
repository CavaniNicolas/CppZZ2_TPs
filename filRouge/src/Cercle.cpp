
#include <sstream>
#include "Cercle.hpp"

Cercle::Cercle(Point point, int width, int height, COULEURS couleur) :
	Forme(point, width, height, couleur)
{}

Cercle::Cercle(int x, int y, int width, int height, COULEURS couleur) :
	Cercle(Point(x, y), width, height, couleur)
{}

Cercle::Cercle(int x, int y, int radius, COULEURS couleur) :
	Cercle(x, y, radius, radius, couleur)
{}

void Cercle::setRayon(int radius) {
	Forme::setHeight(radius);
	Forme::setWidth(radius);
}

int Cercle::getRayon() {
	int width = Forme::getWidth();
	int height = Forme::getHeight();
	return (width < height) ? width : height;
}

std::string Cercle::toString() {
	std::stringstream flux; 
	flux << "Cercle: " << Forme::toString();
	return flux.str();
}
