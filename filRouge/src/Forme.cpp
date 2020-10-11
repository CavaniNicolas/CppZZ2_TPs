
#include <sstream>
#include "Forme.hpp"

int Forme::nbFormes = 0;

Forme::Forme(Point point, int width, int height, COULEURS couleur):
	point(point), width(width), height(height), couleur(couleur)
{
	id = nbFormes;
	nbFormes ++;
}

Forme::Forme(Point point, COULEURS couleur):
	Forme(point, 0, 0, couleur)
{}

void Forme::setPoint(Point newP) {
	point = newP;
}

void Forme::setWidth(int newW) {
	width = newW;
}

void Forme::setHeight(int newH) {
	height = newH;
}

void Forme::setX(int x) {
	point.setX(x);
}

void Forme::setY(int y) {
	point.setY(y);
}

void Forme::setCouleur(COULEURS coul) {
	couleur = coul;
}


Point& Forme::getPoint() {
	return point;
}

int Forme::getWidth() {
	return width;
}

int Forme::getHeight() {
	return height;
}

int Forme::getX() {
	return point.getX();
}

int Forme::getY() {
	return point.getY();
}

COULEURS Forme::getCouleur() {
	return couleur;
}

int Forme::getId() {
	return id;
}

int Forme::prochainId() {
	return Forme::nbFormes;
}

std::string Forme::toString() {
	std::stringstream flux; 
	flux << point.toString() << " " << width << " " << height;
	return flux.str();
}
