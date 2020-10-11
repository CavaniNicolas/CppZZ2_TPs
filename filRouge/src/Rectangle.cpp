
#include <sstream>
#include "Rectangle.hpp"

Rectangle::Rectangle(Point point, int width, int height, COULEURS couleur) :
	Forme(point, width, height, couleur)
{}

Rectangle::Rectangle(int x, int y, int width, int height, COULEURS couleur) :
	Rectangle(Point(x, y), width, height, couleur)
{}

std::string Rectangle::toString() {
	std::stringstream flux;
	flux << "Rectangle: " << Forme::toString();
	return flux.str();
}
